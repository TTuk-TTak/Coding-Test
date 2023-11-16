/* [DP] - map형 DP문제
 - 격자무늬에서 => 포트x제외 최단거리 찾기 문제
 
 - 주의사항)
 - 초기값 위쪽line, 왼쪽 line 을 모두 일괄 1로 세팅하고 시작하면 오류,
    - 가장자리 line에도 포트 발생할 수 있음 + 포트 옆이라면 1이 아닌 0 으로 세팅해야함 ***
 - 정답이 %N으로 나눈 나머지일 때,
    - 최종정답에서만 나누기 해주는 것 만으로 부족할 수 있다    => 효율성 탈락의 원인 *****
    - 반복문 매 턴마다 %N값을 사용해야함                    => TC4,5,10 탈락원인 *****
 - for문
    - 괄호 {} 생략x 꼭쓰기
    - for문 똑바로 안쓰면 compile 에러 없이 실행안되는 ERROR ****
 - 출력문이 과하면 => 효율성 탈락의 원인 ******                                        */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer =0;
    int direction[2][2] ={{-1,0}, {0,-1}};     // 위, 왼쪽만 탐색  
    
    // 초기값 세팅 
    vector<vector<int>> v(n, vector<int> (m, 0));
    for(auto p: puddles)                        // 포트 위치 표시 
        v[p[1]-1][p[0]-1] = -1;                 // 가로-세로 반대 & index 1부터 시작 보정 **
    
    // 탐색 & 계산 시작
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 초기값(집) 세팅 ***
            if(i==0 && j==0)
                v[i][j] = 1;
            // 포트일 경우 제외
            if(v[i][j] == -1)
                continue;
            // →, ↓ 이동 위해 -> 위쪽, 왼쪽 비교 
            for(int d=0; d<2; d++){
                int cy = i + direction[d][0];
                int cx = j + direction[d][1];
                if(cy<0 || cx<0 || v[cy][cx] == -1)
                    continue;
                // 위쪽, 양쪽으로부터의 경우의 수를 더하는 작업 
                v[i][j] += v[cy][cx];            
            }
            // 매 턴마다 지나치게 큰 값 보정 (1000000007로 나눈 값이 answer) ******
            v[i][j] %= 1000000007;
        }
    }
    
    answer = v[n-1][m-1];          
    
    /*
    // 출력 확인 
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    
    return answer;
}
