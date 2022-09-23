/* [경우의수_조합] 주어진 숫자들 배치해 만들수 있는 소수의 개수 구하는 문제 
<기억사항> ***
 1. DFS (string)
        - 매개변수          :   (전체string_고정 / str + 한글자)   :한글자씩 추가함
        - [level] stop조건 :  if(str != "")                     : 빈 str이 아닌이상, 모든경우의 수 저장
        - [level] return  :     X
    DFS (int)
        - 매개변수          :   (한글자 / level / 자릿수정함)   :정한자릿수까지 level을 올리며 한글자씩 추가 
        - [level] stop조건 :  if(level = digit)             : 정해진 자릿수가 되면 stop 
        - [level] return  :     O                                                       */

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int visited[7] = {0};
set<int> lists;

// 소수판별 함수 
int check(int a){ 
    if(a < 2)
        return 0;
    for(int i=2; i*i<=a; i++){  // 제곱수 이하까지만 check ***
        if(a%i == 0)           
            return 0;   // 소수 X
    }
    return 1;           // 소수 o 
}

// 재귀함수
void recur(string numbers, string str){
    // level
    if(str != ""){         // 조건주의! empty만 아니면, 모든경우에 대해 계속 경우의수 저장 ***
        if(check(stoi(str)))
            lists.insert(stoi(str));
            //return       => string DFS 여기선 return없어도 됨. ***
    }
    
    // branch
    for(int i=0; i<numbers.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            recur(numbers, str+numbers[i]);     // string DFS *** 
            visited[i] = 0;
        }
    }
}



int solution(string numbers){
    recur(numbers, "");     // 재귀만 호출. numbers는 전역변수처럼 쓰기 위함으로 항상 불변(고정) 
    
    return lists.size();
}
