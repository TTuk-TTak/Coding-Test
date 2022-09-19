/* 제한조건이 있는 다리를 지나가는 최단시간 문제 ***
<제한점>
 1. 트럭이 다리를 건너는데 필요한 시간 = bridge_length와 같다. 
    즉, 다리길이만큼의 초가 걸림. (1초당 1/bridge_length 거리만큼 이동)
 2. 다리 위에는, [무게조건_weight이하], [개수조건_bridge_length이하] 가 있으므로, 두 조건을 다 check해야함. 
 
<유의사항>  ***
 1. {한 턴 = 1초} 무조건 한턴에 한칸씩!!! 만 움직일 수 있도록 정의해야 난이도 낮아짐  ***
    한턴에 push, pop, time++ 모두 일어남. => 1중 for문 
 2. 스택&큐는, 임의의 index로 접근 불가능 => 다리위 총 무게의 값은, 일일이 원소를 순회하며 더하지 않고,
    push, pop 될때마다 sum에서 +, -해가며 접근 
 3. (1) pair<무게, 다리위에서보낸 시간>    (X)     => 2중 for문   원소가 가변적
    (2) pair<무게, 시작 후 누적시간>      (O)     => 1중 for문   원소값 불변    ***
    => 1의 경우로 할 경우, 다리위에서 보낸 시간 = bridge_length 일때 pop하려 했으나, 이 경우, 한 턴을 돌때마다 
        다시 다리queue의 모든 원소를 순회하며 각 시간에 +1을 해야해 queue의 원소값에 매번 접근해 값을 바꿔줘야 한다. 
    => 하지만 2처럼 누적시간으로 한다면, time stamp 의 역할을 하기에
        한번 push된 원소의 값을 절대 바꿀 일이 없고, 그러므로 반복문으로 한번 더 순회할 필요도 없이, 
        원소값에서 바로 answer를 유추할 수 있다.
 
<기억사항>
 1. vector의 {원소의총합}
     accumulate(v.begin(), v.end(), 0)    ***            */

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer;
    queue<pair<int,int>> bridge;    // 다리위 <무게, 누적시간>   ***
    int weight_sum = 0;             // 다리위 누적 무게
    int time_now = 0;               // 누적시간 = time stamp  처음부터~지금까지의 시간(O)    다리 위에서의 시간(X) ***
    int i = 0;                      // 트럭목록의 포인터 (truck_weights의 index)
    
    // timer형식, 한 턴씩 돌며 ***
    while(1){
        // 1. 여건이 된다면, push를 한다. 
        if((bridge.size() + 1 <= bridge_length) && (weight_sum + truck_weights[i] <= weight)){  // 개수조건, 무게조건 check 
            bridge.push(make_pair(truck_weights[i], time_now + bridge_length + 1)); // push시, {pueue의 제일 앞부분}={다리를 모두 건너고 나가기 직전}에 바로 들어가므로,  ***
                                                                                    // 해당 원소가 bridge큐의 나가기 직전(front)에 있을 때를 기준으로 timestamp 가 찍힘. 
                                                                                    // 즉, 현재시간(time_now)에 + bridge_length 까지 더해줌
            weight_sum += truck_weights[i];
            i++;    // 트럭목록의 다음 트럭으로 포인터 이동 
        }
        // break문 (=정답발견 시)
        if(i >= truck_weights.size()){      // 모든 트럭이 다 다리위로 올라갔을 시, 
            answer = bridge.back().second;  // 즉시 중단 후, 제일마지막에 나갈 트럭(back)의 time stamp가 정답 
            break;
        }
        else{
            // 2. 시간을 ++ 한다. 
            time_now++;
            // 3. 다 된 애들을 pop한다. 
            if(bridge.front().second == time_now + 1){   // 시간조건 check 
                                                         // push할 때의 time_now와, 지금의 time_now는 다르므로, 둘이 약(bridge_length)만큼 차이날 때가 pop될 때 *** 
                weight_sum -= bridge.front().first;
                bridge.pop();
            }
        }
    }
    
    return answer;
}
