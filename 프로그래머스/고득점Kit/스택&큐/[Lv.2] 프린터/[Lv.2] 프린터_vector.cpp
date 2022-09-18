/* 프린터 큐에 우선순위가 있는 문제 
<유의점>
 1. 중요도만으로 단순'정렬' 후 답을 찾기에는, 동순위의 순서를 예측할 수 없다. 
 2. que에 출입하며 index가 계속 바뀌므로, '어떻게 몇번째 인지 알지?'를 잘 고민해봐야 함. 
 3. => 여기선 두 벡터에, 같은 큐 작업(pop,push)을 동일하게 하며 해결
    priorities  [2,1,3,2,2,1] => 우선순위 표시 
    check_v     [0,0,1,0,0,0] => 1로 위치 표시
    
<기억사항>
 1. 최대&최소값 함수 => 모두 <algorithm> 헤더에 존재
    i) 두 값 중 최대/최소 찾는 경우     두 value비교      min(a,b);
    ii) {벡터}에서 최대/최소 찾는 경우  두 iterator비교   *min_element(v.begin(), v.end());    ***
        => 반환값이 iterator라 별표(*)를 항상 붙여 값을 표시한다. 
           입력 매개변수 또한 iterator이므로 v.begin, v.end  (O) 사용!
                                         v.front, v.back (X)
 2. vector에서 queue처럼 첫 원소를 'pop'하는 방법
    => v.erase(v.begin());                  ***
        erase함수는 입력 매개변수 iterator 
 3. vector에서 erase 하면 index 당겨짐 !       ***
    ex) 첫 원소 삭제해도, v[0] 다시 출력하면, 뒷 원소가 당겨져 정상적으로 출력됨
    * v[0]과 v.front()는 완전히 동일 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; 
    // 위치 확인용 벡터 만들기
    vector<int> check_v(priorities.size(), 0);
    check_v[location] = 1;  
    
    while(1){       // for elem 로 돌리면, 딱 처음 size만큼만 돔. (뒤에 추가되어 vector가 empty가 아님에도) 주의!***
        int max = *max_element(priorities.begin(), priorities.end());   // ***
        // 1. 다른 우선순위가 있을 시, => 뽑아서 제일 뒤에 넣음 
        if(priorities.front() < max){
            priorities.push_back(priorities.front());   // 뒤에 넣고    // front와 begin 잘 구분 ! ***
            priorities.erase(priorities.begin());       // 앞에 삭제 
            
            check_v.push_back(check_v.front());
            check_v.erase(check_v.begin());
        }
        // 2. 1순위 일 시, => pop
        else{
            priorities.erase(priorities.begin());   
            answer++;                                   // 몇번째로 pop되는지 count 
            if(check_v.front() == 1)                    // 찾던 원소면 stop 
                break;
            
            check_v.erase(check_v.begin());
        }
    }
    
    return answer;
}
