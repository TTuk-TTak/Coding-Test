/* 프린터 큐에 우선순위가 있는 문제 
<유의점>
 1. que에 출입하며 index가 계속 바뀌므로, '어떻게 몇번째 인지 알지?'를 잘 고민해봐야 함. 
 2. vector  priorities  우선순위저장      - max값 찾는 용       - 순서 안바뀜(고정)
    queue   printer     index위치저장    - pop,push 하는 용    - 위치계속 바뀜(유동)
    => 첫 고정 index를 queue에 계속 pop, push 하며 바뀐 위치를 파악, 
       queue의 value = vector의 index로 접근해, vector에 고정된 우선순위 파악함 ***
       
<기억사항>
 1. queue STL에는 사용가능한 min, max 함수 따로 없음 *** 
    (vector로 해결해야 함)        */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer;
    //vector<int> priorities;   // 우선순위 저장(고정)
    queue<int> printer;     // index 큐에 저장(유동)  ***
    vector<int> results;    // 출력순서 결과저장
    
    // printer 큐 만들기(index 저장) 
    for(int i=0; i<priorities.size(); i++){
        printer.push(i);
    }
    
    
    while(1){
        int now_index = printer.front();    // 따로 꼭 저장해야 pop후 꼬이지 않음 ***
        // 1. 다른 우선순위가 있으면 => 뒤에 다시 넣음 
        if(priorities[now_index] < *max_element(priorities.begin(), priorities.end())){ 
            printer.pop();
            printer.push(now_index);
        }
        // 2. 최고 우선순위면 => pop
        else{
            printer.pop();
            priorities[now_index] = 0;      // pop하고, 우선순위 내려줘야 max값이 오염안됨 *** 
            results.push_back(now_index);   // 결과 저장
            // 찾던 원소가 pop되면 stop
            if(now_index == location)
                break;
        }
    }
    
    // 출력순서 결과저장results에서 몇번째 인지 찾기
    for(int i=0; i<results.size(); i++){
        if(results[i] == location){
            answer = i+1;   // 순서 +1 *** 
            break;
        }
    }

    return answer;
}
