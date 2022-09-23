/* 되는데까지 방문해보는 문제 
<기억사항>
 1. 방문던전 수 기준이 일정개수 X, 체력되는데까지 O 이기 때문에 종료조건 애매함 ***
     visited_cnt 를 따로 세도 되지만, 
     사실 최댓값을 구하는 문제이기 때문에 따로 종료조건 없어도 됨. ***
     그냥 매 턴마다 최댓값을 찾으면 됨 !!! 
 2. vector복사는 간단히 a = b로 가능하다                   */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dgs;
vector<int> visited(8,0); 
int answer = -1;

void recur(int cnt, int now_pr){    // (던전방문수, 현재남은 체력)
    // level
    answer = max(answer, cnt);                          // 종료조건 상관 X => 무조건 최대값 찾으면 되기 때문!! ****   
    
    // branch
    for(int i=0; i<dgs.size(); i++){
        if(visited[i] == 0 && (now_pr >= dgs[i][0])){   // 방문x && 현재피로도>최소피로도 
            visited[i] =1;
            recur(cnt+1, now_pr - dgs[i][1]);           // 방문수+1, 체력-
            visited[i] =0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dgs = dungeons;         // vector 복사 이렇게 가능     ***
    recur(0, k);            // (던전방문 개수, 현재남은 체력)
    
    return answer;
}
