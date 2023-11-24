/* [그래프] - 플로이드 워셜
- 단방향 그래프 / 승패로 순위메기기 문제 

플로이드 워셜)
 - O(n^3)의 시간 복잡도를 가짐
 - 즉, 선수의 수 n명이 1~100으로 작으므로, n^3 의 시간복잡도로 구현 가능함 **
 - 플로이드 워셜은 edge의 가중치를 보통 더해 비교하지만, 이 문제는 가중치 없으므로 && 조건으로 단순 비교
 
 - ? edg가 계속계속 이어질 경우, 삼단논법에 따른 중간과정까지 모두 더해줘야 하는가? oo
 - ? edge가 새로 생길경우, 새 edge까지 포함해 전부 다 탐색을 다시해야되나? oo
 => 플로이드워셜의 경우 위 두가지 경우가 모두 커버됨 
 
구현)
 - 1->2->3 인 노드 연결이 있다면, 1->3 도 성립되어야 한다. (삼단논법)
 - 즉, 간선(edge) 끼워넣어 체크해본다 
    - 1. 선수의 수 n만큼 순회하며, 각 턴에 숫자 k를 하나 결정
    - 2. 그래프에서 i->j 를 검토 (단, k열, k행, 제외 + 연결이 없는(0) 것이 대상)
        - i->k->j 이런식으로 정한 k를 끼워넣어보며, 간선(edge)추가할지 말지 결정
        - 수식표현은 grp[i,k] ==1 && grp[k,j] => grp[i,j]=1 로 생성해주면 됨
        

주의사항)
 - 이긴사람 =1, 진사람 = -1 로 진사람도 같이 표시!! 
    (단, 이긴사람이 있을 경우 진 사람 자동으로 표시 가능)
 - 그래프의 모든 칸이 관계(1 or -1)가 표시된다면, => 정확히 순위를 매길 수 있는 선수 인 것임. 
 - 벡터 값 count
    - #include <algorithm>
    - count(v.begin(), v.end(), n)                                                  */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // 0. edge간선 => 그래프 변환
    vector<vector<int>> grp(n+1, vector<int>(n+1, 0));
    for(auto i: results){
        grp[i[0]][i[1]] = 1;
        grp[i[1]][i[0]] = -1;                           // 진 것도 표시 ! ** 
    }
    
    // 1. 플로이드 워셜 => 그래프 보정 
    // k(끼워넣어볼 node값) 선정 *** 
    for(int k=1; k<n+1; k++){               
        // 그래프 순회
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                // k열, 행 제외 + 자기자신과의 연결 제외 
                if(i==j || i==k || j==k)
                    continue;
                // 연결 없는 곳중, 삼단논법이 성립한다면 연결(edge) 추가 
                if(grp[i][j]==0 && grp[i][k]==1 && grp[k][j]==1){
                    grp[i][j] =1;
                    grp[j][i] =-1;
                }
            }
        }
    }
    
    // 2. 관계가 모두 있는 경우만 check 
    int cnt1;
    int cntm1;
    for(int k=1; k<n+1; k++){
        cnt1 = count(grp[k].begin(), grp[k].end(), 1);  // vector에서 특정값 count **
        cntm1 = count(grp[k].begin(), grp[k].end(), -1);
        
        if(cnt1 + cntm1 == n-1)
            answer++;
    }
    
    /*
    // 출력확인 
    for(auto j: grp){
        for(auto i:j){
            cout<<i<<" ";
        }
        cout<<"\n";
    }*/
    
    return answer;
}
