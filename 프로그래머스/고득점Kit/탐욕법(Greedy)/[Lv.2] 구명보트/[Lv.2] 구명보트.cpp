/* 최소횟수로 왕복하며, 보트로 사람구하기  

 {Greedy 탐욕법}
 => 제일 무거운 사람부터 빨리빨리 보내버리기 (되는 대로 태우기)
 => 눈앞의 이익(어차피 태울거 가장 무거운 사람 + 남는데에 가벼운 사람부터)만 쫓으므로 그리디 탐욕법 
 => Greedy는 1중 for문 에서 끝내야 효율성 통과 ****** 
 => 1중 for문 만들기 위해 {제한조건} 활용 
    1. 사람무게 정렬 후 사용
    2. 태울 수 있나 가늠해볼 때, 조합을 미리 생각해 비교해보지 말고, 그때그때 여분 kg 에서 사람 무게 빼버리기  
 
<유의점>
 1. 제일 무거운 사람이더라도, 일단 보트를 1번 이상 타긴 타야한다. 
 2. 그때 그때 얼마나 더 태울 수 있나 while로 돌지말고 X
    한 턴에 사람 한명 씩(1중 for) O                                  *****
 3. 다음은 실패한 방법들
    1) 2중 for문으로 무거운쪽, 가벼운쪽에서 각각 for문 돌려 되는만큼 태우기 => 효율성 통과X
    2) 임의로 짝지어 태우기 X
    3) 무거운 쪽에서만, 가벼운 쪽에서만 차례대로 태우기 X

 
<제한사항>
 1. 40kg <= 사람몸무게 <= 보트무게제한 <= 240 
 2. people은 1 ~ 50,000 자리수
 => 2중 for문 이상 돌리기엔 너무 큼 .. => {Greedy} 의심 
    (실제로 시간초과로 효율성test 탈락)

<기억사항>  ***** 
 1. deque는 vector의 단점을 보완하기 위해서 만들어진 컨테이너
 2. deque도 vector와 마찬가지로 배열기반의 구조
 3. vector는 insert 시,  메모리 재할당 후 이전 원소를 복사하는 방식 =>  삽입 시 성능 저하  ****
 4. vec.poop_front()            X
    vec.erase(vec.begin())      O
    *단, deque는 다 됨 
 5. vector -> deque 변환 방법                                                     **** 
    deque<int> dq(vec.begin(), vec.end());                  */

#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 1. 사람 무게순으로 정렬
    sort(people.begin(), people.end(),greater<>());

    // 2. vector to deque
    deque<int> dq(people.begin(), people.end());       
    
    // 3. 보트에 사람 되는대로 넣기!       한 턴에 한 명씩 ***********
    int sum = limit; 
    while(!dq.empty()){
        // i) 제일 무거운 사람부터 넣어보기 
        if(sum>=dq.front()){
                sum-=dq.front();
                dq.pop_front();
        }
        // ii) 제일 가벼운 사람부터 넣어보기 (무거운 사람 다 찼을 때)
        else if(sum>=dq.back()){        // if로 안하고 else if 로 하는게 중요 !! ****
                sum-=dq.back();
                dq.pop_back();
        }
        // iii) 더이상 못태우면, -> 보트 보내고 & limit초기화
        else{
            answer++;
            sum = limit;
        }
    }
    
    return answer+1;
}
