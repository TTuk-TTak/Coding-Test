/* [DP] 
 - 연산의 가짓수로 목표값 만드는 문제 
 - DP[i] = i를 y(목표값)으로 만들기 위해 필요한 '연산 횟수'! ******

 - DP)
    - 반드시 '배열' 생성 (memoization 용) *****
        - 1) 뭘 저장할 것인가? => 보통 output으로 요구하는 거 ex_ 연산횟수
        - 2) 어느 크기로 만들 것인가? => 보통 주어진 모든 input case만큼 

 - TC)
    - 연산의 가짓수 1,000,000 개 까지 나올 수 있음 => 최대 O(n) ~ O(n^2)
    - 경우의수 문제 즉, dfs, bsf로 풀수는 있으나, 
        - 1) TC 기준 경우의 수가 너무 많으며, => dfs의 경우 '재귀 깊이 제한' 에서 걸릴확률 ↑ 
        - 2) 중복적인 연산이 너무 많으므로, => memoization 활용하면 좋을 듯 
        => 결론 : DP 를 사용해야 한다. 
 
 
 - 배열 초기화 시, 0외의 다른 값으로 일괄 초기화는 불가능 
    - int arr[n] = {0}     =>0으로 초기화 O
    - int arr[n] = {5}     =>5로 초기화 X 불가능       */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define N 1000001                           // *** 

using namespace std;


int solution(int x, int y, int n) {
    int answer;    
    // *** DP 배열에 일괄 1000001을 넣는 작업 추가 필요   
        // 0 이외의 값으로 배열 일괄 초기화 불가능 *** 
        // 최악의 경우(n=1)일 때도, 제한사항 1,000,000 보다는 같거나 작은 횟수의 연산을 할 것임
    int DP[N] = {0};
    for(int i=0; i<=N; i++){                        
        DP[i] = N;
    }
    // 1) DP[y] = y를 y로 만들기 위해 필요한 연산 횟수 => 0 으로 시작
    DP[y] = 0;
    // 2) DP[~] => 기존값 vs 현재기준 연산한번 더 +1 한 값 비교 후, 더 최소연산인 값으로 갱신 **
    for(int i=y; i>=x; i--){                    // 범위설정 **** 
        if(i%3 == 0)
            DP[i/3] = min(DP[i/3], DP[i]+1);
        if(i%2 == 0)
            DP[i/2] = min(DP[i/2], DP[i]+1);
        if(i-n >= 0)
            DP[i-n] = min(DP[i-n], DP[i]+1);
    }
    // 3) DP[x] = x를 y로 만들기 위해 필요한 연산 횟수 => 우리가 찾는 정답
    answer = DP[x];
    // 연산횟수로 도달할 수 없는 값이면 보정변경 
    if(DP[x] == N)
        answer = -1;
    return answer;
}
