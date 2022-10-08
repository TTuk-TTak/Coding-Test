/* 2차원 지도에서 BFS 최단거리 문제 

- 이건  틀린 풀이 ****

<유의점>
 1. dfs (X)  bfs(O)로 해야지만 효율성 통과됨 
    dfs: 최단거리를 찾더라도, map의 모든 지점을 탐색하기 전까지 끝나지 않음
 2. dfs 정확성 문제 : answer 업데이트 할 때, 
                    최단경로, min 값 알고리즘으로 넣어주지 않으면 정확성에서 부터 틀림  */

#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<vector<int>> map;
int direct[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};   // 상하좌우 
int answer = 10000;

void recur(int y, int x, int level){
    //cout<<"level:"<<level<<" "<<y<<" "<<x<<"\n";
    // level: 도착지점에 도달했을 때
    if((y == n-1)&&(x == m-1))
        answer = min(answer,level +1);

    // branch
    for(int i=0; i<4; i++){
        int ny = y + direct[i][0];
        int nx = x + direct[i][1];
        // 지도 범위 벗어나면 continue
        if(ny<0 || nx<0 || ny>=n || nx >=m || map[ny][nx]==0)
            continue;
        // visited & recur
        map[y][x]=0;  // visited 대신 지도에 표시
        recur(ny, nx, level+1);
        map[y][x]=1; 
    }
}

int solution(vector<vector<int> > maps){
    // 지도파악
    map = maps;
    n = maps.size();
    m = maps[0].size();
    // 재귀 탐색시작
    recur(0,0,0);
    
    // 도착지점에 도달할 수 없다면 -1 리턴
    if(answer == 10000)
        answer = -1;
    return answer;
}
