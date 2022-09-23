/* [경우의수_조합] 주어진 숫자들 배치해 만들수 있는 소수의 개수 구하는 문제 
<유의점>
 1. 숫자의 자리를 바꿀 수 있는 문제는, 경우의수 string으로 모두 나열 후, stoi해주는게 더 쉬움. ***
    int로 먼저 바꿔버리면 꽤 어려워짐 
 2. [접근방식]
    (1) 모든 조합을 만든다 [next_permutation]
        - 우선 정렬 (정렬필수)!!    ***
        - do-while로 next_permutation 돌려 기존 vector에 경우의 수 저장
        - 그냥 이것만 하면 numbers.size()자릿수를 유지하는 경우만 나오므로, 
        - for문을 하나 더 두어, 그 경우에 해당하는 다양한 자릿수의 경우까지 구함
        - substr 사용해 n자리의 부분집합 다 구함     ***
    (2) 형변환                                      
        - stoi로 제일 앞자리수 0뺌
    (3) 소수판별
    (4) 중복되는 경우의 수 제거
        - set에 넣으면, 중복 경우의수 제거                   ***
        - set의 size = 소수의 개수 


<기억사항>
 1. next_permutation (개념)
    - n개 원소들의 모든 순열 구해줌 -> n자리수인 경우들만 나옴 ***
    - vector 자체의 값을 재정렬해줌 
    - vector, string에서 모두 사용 가능(iterator를 인자로 받기 때문)
    - 중복되는 순열 제외하고 보내줌! (중복 X) ***
    - default: '오름차순'으로 순열 생성
    - <algorithm> 헤더에 포함
 2. next_permutation (주의사항)
    - 넣기 전 정렬 필수 !! *** 
    - '오름차순'으로 정렬된 데이터를 넣어야함. 무조건!!!    ***
      더 큰 순열로 재배열할 수 없을때까지 반복하는 구조이기 때문 
    - 반드시 {do-while}로 구현해야함!        {do-while O}    ***
      while로 하면 원래 vector값은 빼고나옴   {while    X} 
 3. prev_permutation 은 
     - '내림차순'정렬 데이터를 받아
     - '오름차순'으로 출력
     
 1. set STL컨테이너 (개념)
    - <key> 형태의 원소 집합
    - set               <  >        key값            중복X
      unordered_map     <  ,  >     key-value값      중복X
    - 중복허용 X
    - 자동정렬 
 2. set STL컨테이너 (함수)
    - set.insert(k)         k삽입
    - set.insert(iter, k)   iter가 가리키는 위치부터 k삽입할 위치를 탐색해 삽입
    - set.erase(iter)       iter가 가리키는 원소 삭제 
    - set.find(k)           k원소를 가리키는 iter반환                    */

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


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



int solution(string numbers){
    set<int> lists;    
    string sub;
    int tmp;
    
    // 1. 우선 정렬 
    sort(numbers.begin(), numbers.end());       // next_permutation 정렬 필수 ***
    
    // 2. 모든 순열(조합)경우의 수 구하기 
    do{
        // 모든자릿수에 대한 경우의 수 구하기 
        for(int i=1; i<=numbers.size(); i++){
            sub = numbers.substr(0, i);         // *** 
            tmp = stoi(sub);                    // stoi 거치며, 제일 앞 0 숫자 사라짐 
            // 3. 소수판별 
            if(check(tmp))
                // 4. 중복제거(set 사용)
                lists.insert(tmp);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));   // *** 

    
    return lists.size();
}
