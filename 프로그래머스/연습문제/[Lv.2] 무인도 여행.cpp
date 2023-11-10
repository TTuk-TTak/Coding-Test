/* BFS 
 - [map] 지도상 붙어있는 구역 파악하기 문제 
 - * 그래도 visited는 항상 따로 표시해서 (기존 map변경 X) 해야 구현에 영향 안미치고, 디버깅하기에 무조건 좋음
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int Y = maps.size();
    int X = maps[0].size();
    // 0. 지도의 모든 구간 탐색하며,
    for(int j=0; j<Y; j++){
        for(int i=0; i<X; i++){
            // 1. 탐색할 부분 선택 
            if(maps[j][i]!='X'){
                // 2. bfs 시작 (연결된 땅 다 찾기)
                int sum =0;
                queue<pair<int,int>> q;
                q.push({j,i});
                while(!q.empty()){
                    int y = q.front().first;            // queue안의 pair 사용법 *** 
                    int x = q.front().second;
                    q.pop();
                    // [주의] 위 1에서 X여부 확인했더라도, 
                    // while문 내에 돌면서 queue에 추가된 숫자가 X로 변할 수 있어서 재검토! 
                    if(maps[y][x] == 'X')
                        continue;
                    sum += maps[y][x] - '0';
                    maps[y][x] = 'X';                   // 이미 방문한 곳 visited 표시 
                    
                    // 상/하/좌/우 방향검토
                    for(int a=0; a<4; a++){
                        int ny = y + direction[a][0];
                        int nx = x + direction[a][1];
                        if(ny<0 || nx<0 || ny>=Y || nx>=X || maps[ny][nx] == 'X')
                            continue; 
                        q.push({ny,nx});
                    }
                }
                // 정답 채우기
                answer.push_back(sum);
            }
        }
    }
    
    
    // 정렬 
    sort(answer.begin(), answer.end());
    
    
    // 섬이 없을 경우 
    if(answer.empty())
        answer.push_back(-1);
    
    
    return answer;
}
