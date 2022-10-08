/* 그래프 연결을 bfs로 네트워크 개수 찾기 문제

<유의점>
 1. 네트워크 개수를 세는 방법 
    1. (X) answer=n으로 놓고, 연결이 있을 때마다 answer-- 하기
           하나의노드에 연결이 여러개 있을 수 있으므로(ex_닫힌그래프 무한연결) 
           이미 하나의 네트워크인 노드들 사이에, 추가 연결이 있을 수 있음. 그래서안됨
    2. (X) flag 세워 연결된 node없을 시 count++ 하기 
            queue에 따라, 노드순서대로 돌지 않기 때문에 flag값이 for문 내에서 바뀜
    3. (O) visited 방문 체크를 따로 해,
            이미 방문한 node면 continue, 아닐 경우 모두 count ++ 로 세기! 

<제한사항>
 1. n은 1~200이므로 상대적으로 널널 => 2중for문 가능       */

#include <string>
#include <vector>
#include <queue>
#define N 200

using namespace std;


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;         // answer count
    int visited[N] = {0};   // 방문한 com 표시 위함 
    queue<int> q;
    
    // 1. 모든 node를 차례로 체크하며 
    for(int i=0; i<n; i++){
        // 1-1.이미 방문한 node라면 pass 
        if(visited[i] == 1)
            continue;
        // 1-2. 아직 방문안했다면, 다른 네트워크이므로 answerr ++ 
        answer++;           // answer을 count 해서 처리 
        q.push(i);
        visited[i] = 1;
        // 2. bfs시작 
        while(!q.empty()){
            int com = q.front();
            q.pop();
            // 3. 연결된 node가 있나 탐색 
            for(int j=0;j<n;j++){
                // 4. 연결된 node는 q에넣기 (본인이 아닌것 중에  ***)
                if(computers[com][j] == 1 && com!=j){
                    q.push(j);
                    visited[j]=1;           // 방문처리
                    computers[com][j]=0;    // 쌍방 연결되어있으므로 둘다 연결해제 *** 
                    computers[j][com]=0;
                }
            }
        }
    }
    
    return answer;
}
