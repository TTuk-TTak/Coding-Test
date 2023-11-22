/* [그래프]
- 가장 멀리 떨어진 노드 개수 return 문제 
- queue에 {val, level} 같이 저장하는 BFS 형태            */
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> grp(n+1, vector<int>(n+1, 0));  // 간선 => 그래프 기록용도
    vector<int> visited(n+1, 0);                        // 방문 체크
    vector<int> level(n+1, 0);                          // 거리 (1번노드로 부터 떨어진 단계) 기록용도
    queue<pair<int,int>> q;                             // pair{노드, level}
    
    
    // 0. 간선 => 그래프로 옮기기 
    for(int i=0; i<edge.size(); i++){
        grp[edge[i][0]][edge[i][1]] = 1;
        grp[edge[i][1]][edge[i][0]] = 1;
    }
    
    // 1. 턴 돌며 queue 에 넣기 (BFS) 
    int lv, node;
    q.push({1,1});
    visited[1] =1;
    while(!q.empty()){
        node = q.front().first;
        lv = q.front().second;
        q.pop();
        
        // 간선 거리 별 노드개수 기록
        level[lv]++;
        
        // 그래프 row 한 줄 탐색
        for(int i=1; i<=n+1; i++){
            if(grp[node][i]==1 && visited[i]!=1){
                q.push({i,lv+1});
                visited[i]=1;
            }
        }
    }
    
    return level[lv];                                   // 마지막 lv의 노드 개수 반환 
}
