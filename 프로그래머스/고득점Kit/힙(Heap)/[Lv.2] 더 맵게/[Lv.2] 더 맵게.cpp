/* 정해진 방법만 사용해 모든 수 K 이상으로 만들기 
    방법) 가장 작은 수 a, 그다음 작은 수 b  =>  a + (b*2)

 {Heap 힙}
 => priority_queue STL 로 풀이     *****
 => 언제나 '가장 작은 수'만 가지고 연산하므로, 늘 정렬 된 priority_queue 의심 

<유의점>
 1. stop 조건)
    1) 남은 원소가 2개 미만일 때      -> 못섞음
    2) 전부 K 이상이 되었을 때        -> 섞을 필요 X
    3) 다 끝나도 K 미만인게 남을 때    -> 걍 -1 return   
 2. edge case 생각 
    1) answer = -1      -> 원소 1개 남을 때까지 섞어도 K이상 안됨 
    2) answer = 0       -> 처음부터 다 K 이상 
    3) answer = 그 외    -> 몇번 하면 됨 
 
<제한사항>
 1. 2 <= scoville <= 1,000,000     -> 최대가 2중 for문 넘으면 안되겠다 
 2. 0 <= K <= 1000,000,000 

<기억사항>  - priority_queue                                            *****
 1. 넣는 순간 항상 정렬되는 queue (pop 연산은 제일 앞에서밖에 안됨 ***)
 2. priority_queue<자료형, {Container}, {비교함수}>                      ***
    ex) priority_queue<int, vector<int>, greater<int>>
        * 3개 parameter중 -> {Container}와 {비교함수}는 늘 같이 써야하는 option -> 둘 중 하나만 사용하면 오류 
        * {Container}와 {비교함수} 사용 시 -> <>내부에 type 꼭 넣어주어야 함 
        * sort 함수 사용 시 {비교함수}를 greater<>() 로 사용하는 것과 차이 **** 
 3. vector to priority_queue 변환 
    => priority_queue<int> pq(vec.begin(), vec.end()); */

#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 1. vector -> priority_queue 변환          
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());       // 오름차순 
    
    // edge case) 0번 섞어도 되는 경우(TC:18) => 처음부터 모두 K이상인 경우 섞을필요 X (while진입 전 검증)*****
    if(pq.top() >= K)
            return answer;
    
    // 2. 섞기 반복 
    while((pq.size() > 1)){        // 요소 2개 미만이면 못섞음 
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
    
        pq.push(a+(b*2));
        answer++;
        
        // 최소값이 K이상 = 모두 K이상 -> return
        if(pq.top() >= K)
            return answer;
    }
    
    return -1;                     // 방법 없을 시 -1 return 
}
