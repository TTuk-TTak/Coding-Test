/* 2차원 지도에서 BFS 최단거리 문제 

<유의점>
 1. dfs (X)  bfs(O)로 해야함. 
    dfs: 최단거리를 찾더라도, map의 모든 지점을 탐색하기 전까지 끝나지 않음
         즉, min값으로 항상 업데이트 해줘야함. 
    bfs: 바로 근처 블럭들부터, 몇번째 방문인지 check해나가며 기록함 
 2. 방문표시 위치 => 이렇게 안하면 효율성 통과 못함      ****
    queue에서 꺼낼 때 X
    queue에 넣을 때   O
    꺼낼 때 방문 체크를 하면, 그 전 단계에서 q에 넣은 블럭의 사방을 탐색할 때, 
    이미 q에 들어있는 블럭을 또 넣을 수가 있게된다.        ******
    
<기억사항>
 1. bfs는 재귀 X, <while문 + queue>를 사용해 구현한다. 
    queue를 사용하는 만큼, 첫조건을 올바르게 넣어주는 것이 중요 !! **  */

#include<vector>
#include<queue>

using namespace std;

int dir[4][2] ={{-1,0}, {1,0}, {0,-1}, {0,1}};

int solution(vector<vector<int> > maps){
    int answer = -1;
    int now_y, now_x, lev;
    int n = maps.size();
    int m = maps[0].size();
    queue<vector<int>> q;       // v={y좌표, x좌표, level거리} 형태로 q에저장
    
    // 1. 시작위치 미리 넣어놓기
    q.push({0,0,1});   
    // 2. bfs탐색 시작 
    while(!q.empty()){          // while조건 은 q가 빌 때까지 ***
        // 3. q값 꺼낸 후 pop
        now_y = (q.front())[0]; // queue속 vector 접근법 ***
        now_x = (q.front())[1];
        lev = (q.front())[2];
        q.pop();
        //maps[now_y][now_x] = 0;   // 여기에 방문표시 넣으면 안됨 X *** 
        
        // 종료조건 = 종료지점 도착 
        if(now_y == n-1 && now_x == m-1){
            answer = lev;
            break;
        }
            
        // 4. 사방탐색 => 갈수 있는 곳 queue에 추가 
        for(int i=0; i<4; i++){
            int ny = now_y + dir[i][0];
            int nx = now_x + dir[i][1];
            if(ny<0 || nx<0 || ny>=n || nx>=m || maps[ny][nx]==0)
                continue;
            // queue에 입력 
            q.push({ny,nx,lev+1});
            maps[ny][nx] = 0;       // 방문표시 ***
                                    // q에 입력함과 동시에 방문표시하지 않으면 효율성 오류!! ******
        }
    }
    
    return answer;
}
