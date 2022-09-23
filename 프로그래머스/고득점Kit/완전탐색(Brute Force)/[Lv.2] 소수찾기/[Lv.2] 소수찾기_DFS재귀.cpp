/* [경우의수_조합] 주어진 숫자들 배치해 만들수 있는 소수의 개수 구하는 문제 
<유의점>
 1. 숫자의 자리를 바꿀 수 있는 문제는, 경우의수 string으로 모두 나열 후, stoi해주는게 더 쉬움. ***
    int로 먼저 바꿔버리면 꽤 어려워짐 
 2. [접근방식]
    (1) 모든 조합을 만든다 
        - 모든 경우의 수 -> 보통 자릿수 정해진 {재귀(recur)}로 만듦        ***
        - 자릿수 고정 아님 -> 모든 자릿수에 대한 모든 경우의수 구함 -> recur을 반복문에 넣고, 모든 자릿수에 대해 돌린다. 
    (2) 조합한 경우의 수 형변환                                      
        - {char벡터}의 index로 쉽게 recur 돌린 후,
        - -> {string}으로 변환                                      ***
        - -> {int}로 다시변환(stoi)
    (3) 소수인지 판별
        - a이하의 모든 수에대해 약수인지 판별 X
        - a의 {제곱수 이하}의 모든 수에 대해서만 판별 O  => 꽤 큰 시간단축  ***
    (4) 중복되는 경우의 수 제거
        - unordered_map 에 넣으면, 중복 경우의수 제거                   ***
        - unordered_map의 size = 소수의 개수 
    
<제한조건>
 1. 11, 011는 같은 숫자 취급 => stoi 하는 순간 제일 앞 0은 의미 없어짐 ***
 2. 자릿수 7자리 밖에 안됨 -> 그래도 조합의 수는 매우 많아짐 
 
<기억사항> ***
 1. vector<char> -> string 변환하는 방법      ***
    string s(v.begin(), v.end());  
 2. vector를 resize후 push_back 하면,    
    resize된만큼의 공간 앞에 비우고, 그 뒤로부터 들어감 => 오류발생 가능성    *** 
 3. {vector<char>}와 {string}은 완전히 같음!!!                         ***
    - string a = b로 string 복사 가능 
    - string 선언 시, ="  " 등으로 공간배분만 한다면, string[idx]로 vector와 똑같이 인덱스 접근 가능하다.   ***
 4. typeid()    :변수의 type을 출력해주는 함수
    #include <typeinfo>로 사용 */

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<char> lists;             // 숫자카드 모두 뽑아 list에 넣기    // vector<char> = string  과 완전 동치! ***
vector<int> visited;            // 사용한 카드 재사용 x
vector<char> path(7);           // 경우의 수 저장용                // = {string path="       "} : size하는 대신, 스페이스바 *7번으로 공간 배분 ***
unordered_map<int, int> ans;    // answer세며 중복 제거 위함 


// 소수판별 함수 
int check(int a){ 
    if(a < 2)
        return 0;
    for(int i=2; i*i<=a; i++){  // 제곱수 이하까지만 check ***
        if(a%i == 0)            // 약수가 한개라도 나온다면 
            return 0;   // 소수 X
    }
    return 1;           // 소수 o 
}


// 재귀함수(DFS)
void recur(int val,int level, int digit){   // digit자릿수의 모든 경우의 수 파악 
    // level (자릿수)
    if(level == digit){ 
        // char벡터 -> string -> int 로 형변환 
        string s(path.begin(), path.end()); // vector<char>  ->  string        *** 
        int a = stoi(s);                    // stoi하며 자동으로 제일 앞 0 사라짐   ***
        // 소수 check 
        if(check(a))
            ans.insert(make_pair(a,0));     // first: key값 a,  second: 의미없는 값  => 중복제거 위함 ***  
        return;
    }
    // branch (카드종류)
    for(int i=0; i<lists.size(); i++){
        if(visited[i] == 0){
            visited[i]=1;
            path[level] = lists[i];         // path가 string이어도, 공간배분"  "만 했다면, path[idx]로 접근가능
            recur(lists[i], level+1, digit);   // ***
            visited[i]=0;
        }
    }
}


int solution(string numbers) {
    // lists벡터에 숫자카드 종류 하나씩 넣음 
    visited.resize(numbers.length(), 0);
    for(int i=0; i<numbers.length(); i++){      // lists를 string으로 한다면 lists = numbers로 한줄요약 가능 ***
        lists.push_back(numbers[i]);
    }
    
    // 재귀(DFS) - 모든 경우의 수
    for(int i=1; i<=numbers.length(); i++){     // 자릿수 별로 recur 반복 ***
        recur(0,0,i);
    }
    
    return ans.size();
}
