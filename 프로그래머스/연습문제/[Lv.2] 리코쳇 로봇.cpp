// 주의!!! => 꼭 정사각형 인건 아님. 예시 1이 직사각형이라서 오류남 
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<string> board) {  
    int Y = board.size();           // 게임판 크기 파악
    int X = board[0].size();
    vector< vector<int> > visited;  // 방문한 위치 여부
    queue< vector<int> > q;         // 위치 y, x, 직전방향 d, 단계 lv    
    int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};          // 상하 좌우 
    int y,x,d,lv, ny, nx;           // 여기서 초기화 안하고 while 문 안에서 하면 runtime error 날 수도 있음! ***
    
    visited.resize(Y, vector<int>(X));
    
    // 0-1. R 시작위치 찾기
    int ry, rx;
    for(int i=0; i<board.size(); i++){
        rx = board[i].find('R');
        if(rx != -1){
            ry = i;
            break;
        }
    }
    
    // 0-2. 초기값 세팅 
    q.push({ry, rx, -1, 0});        // y, x, d, lv  // d는 이전 방향이 아무것도 없기 때문에 임의로 -1 ***
    
    // 1. BFS
    while(!q.empty()){
        // 현재 위치 뽑기 
        y = q.front()[0];
        x = q.front()[1];
        d = q.front()[2];
        lv = q.front()[3];
        q.pop();
        
        // visited 방문 표시 
        if(visited[y][x] == 1)
            continue;
        visited[y][x] = 1;
        
        // 2. 가능한 방향 뽑기
        for(int i=0; i<4; i++){           
            // (1) 이전과 같은 방향이면 뱅뱅 돌지 않게 다음 턴    // 직전에 이동한 방향과 '반대방향'으로 이동하려할 때 제지해야함!! ***            
            if((direction[d][0] == -(direction[i][0])) && (direction[i][1] == -(direction[i][1])))      
                continue;                
            
            // (2) 미끄러져 이동하기    // 한칸씩이 아니라 장애물 직전까지 계속 이동하기 때문에 moves++ 로 이동한 칸 수 사용 !!! ****
            int moves =1;
            while(1){
                // 다음 이동 희망경로
                ny = y + direction[i][0] * moves;
                nx = x + direction[i][1] * moves;
                // (3) 벽에 부딪히거나, 장애물 있으면 이동못함 
                if(ny<0 || nx<0 || ny>=Y || nx>=X || board[ny][nx]=='D'){
                    ny -= direction[i][0];      
                    nx -= direction[i][1];
                    // 한칸도 못가고 바로 막혔을 경우! => 위치 그대로이기 때문에 q에 추가하면 안됨! ***
                    if(moves != 1)
                        q.push({ny, nx, i, lv+1});
                    break;
                }
                moves ++;
            }
            
            // 도착지점에 도달 했을 시,   // 어쨋든 벽, 장애물 등에 닿아야 멈추기 때문에 while 문 밖에서 도착여부 체크! ****
            if(board[ny][nx] == 'G')
                return lv+1;
        }
    }
    
    return -1;
}
