/* 겹치는 직사각형들의 테두리 경로 (BFS)

<유의점>
  1. 테두리 따는법
        i. x=2 등 함수로 표현 -> X
        ii.점 사이의 겹치는 범위 계산 -> X
        iii. 다 모두 점으로 표시후 찾는게 편함 -> O
  2. 접근방식 
        0. 사각형 좌표는 다 2배로 해서 사용 -> ㄷ자 부분은 테두리 분간이 안되기 때문에! *** 
        1. 각 사각형 범위내를 모두 점으로 채운 후, 
        2. 테두리를 따로 표시 (주위 8개 점을 비교해 0이 있을 경우 테두리)
        3. 테두리 경로 따라가기 (최단경로 => BFS)
  
<제한사항>
  1. 겹치는 부분의 테두리로만 이동할 수 있음. 
  2. 더 짧은 경로 선택.
  
<기억사항>
  1. memcpy
        1. 헤더는 <cstring>
        2. 사용 : memcpy(&destination, &arr, sizeof(arr));        // 반드시 주소(&)로 넣기 *** 
        3. arr의 경우 vector 처럼 = 으로 간단하게 깊은복사 안되므로, memcpy 사용 
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>          // memcpy함수의 헤더 
#define M 101

using namespace std;

int map[M][M] ={0};
int visited[M][M] ={0};
int ddirect[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};    // 테두리 구분용
int ldirect[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};                                // 테두리 경로 파악용

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int N = rectangle.size();
    // 0. 좌표값 2배 하기 (ㄷ자 부분 구분하기 위함) *** 
    for(int j=0; j<N; j++){
        for(int i=0; i<4; i++){
            rectangle[j][i] *=2;
        }
    }
    characterY *=2;
    characterX *=2;
    itemX *=2;
    itemY *=2;
    // 1. 사각형안의 모든 점 채우기 
    for(int k=0; k<N; k++){
        int x1 = rectangle[k][0];
        int y1 = rectangle[k][1];
        int x2 = rectangle[k][2];
        int y2 = rectangle[k][3];
        for(int j=y1; j<=y2; j++){
            for(int i=x1; i<=x2; i++){
                map[j][i] = 1;
            }
        }
    }
    // 2. 테두리 누끼따기 
    for(int j=0; j<M; j++){
        for(int i=0; i<M; i++){
            // 색칠된 점만 탐색
            if(map[j][i] == 0)
                continue;
            // 8방향 탐색
            for(int k=0; k<8; k++){
                int ny = j + ddirect[k][0];
                int nx = i + ddirect[k][1];
                // 하나라도 0 인구간이 있으면 테두리로 표시 
                if(map[ny][nx] == 0){
                    map[j][i] = 2;
                    break;
                }
            }
        }
    }
    // 3. 테두리 따라 탐색하며 경로 찾기 (BFS)
    memcpy(&visited, &map, sizeof(map));      // visited = map(깊은복사)는 벡터 아니라서 안됨  
                                              // memcpy 는 <cstring>헤더에 포함  
    queue<vector<int>> q;                     // q <y,x,lv>
    q.push({characterY, characterX, 0});
    while(!q.empty()){
        int y = (q.front())[0];
        int x = (q.front())[1];
        int lv = (q.front())[2];
        q.pop();
        // 목표지점 도달 시 종료  
        if(y == itemY && x == itemX){
            answer = lv/2;                    // 2배한 좌표길이 원복해서 사용
            break;
        }
        for(int k=0; k<4; k++){
            int ny = y + ldirect[k][0];
            int nx = x + ldirect[k][1];
            if(visited[ny][nx] == 2){
                q.push({ny, nx, lv+1});
                visited[y][x] = 0;
            }
        }
    }
        
    return answer;
}
