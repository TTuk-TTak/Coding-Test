/* 프린터 큐에 우선순위가 있는 문제 
<유의점>
 1. que에 출입하며 index가 계속 바뀌므로, '어떻게 몇번째 인지 알지?'를 잘 고민해봐야 함. 
 2. => 여기선 한 큐에, <index, 우선순위>를 pair로 함께 저장함.  
    => priority_queue로 정렬된 우선순위와 matching 해보며 pop,push
       
<기억사항>
 : priority_queue
 1. 우선순위가 높은 데이터가 먼저나오고, 
    같을 시, queue처럼 삽입순서대로 나온다. 
 2. 기본함수 push, pop, top, empty, size등 모두 queue와 같음 
 3. 단, 입력과 동시에 우선순위대로 정렬된다.                     */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;  // <index, 우선순위> 저장용
    priority_queue<int> pq;  // 정렬용 우선순위 que        // 이거 사용하면 max값 활용안해도 됨
    pair<int,int> tmp;         
    
    // 기본 que 만들기 (pair 저장) 
    for(int i=0; i<priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]); // 넣자마자 우선순위 정렬됨(내림차순)
    }
    
    while(1){
        // 1. 최우선 순위이며 && print되는게 찾는 index일 경우
        if((q.front().second == pq.top()) && (q.front().first == location))
            break;
        // 2. 그 외 최우선순위인 경우
        else if(q.front().second == pq.top()){
            answer++;       // answer을 count하며 check
            q.pop();
            pq.pop();       // max값도 바뀌므로 우선순위queue에서도 pop되어야 함 *** 
        }
        // 3. 다른 우선순위가 있는 경우 => 뒤에 다시 넣음 
        else{
            tmp = q.front();    // tmp는 pair
            q.pop();
            q.push(tmp);
        }
    }
    
    return answer + 1;
}
