/* [누적합] 매 턴마다 max값을 저장하는 문제 
<유의점>
 1. 문제에따라 위-> 아래로 진행하여 모든 경우의 수를 DP로 저장하려고 하면 안풀림 X
    시각을 바꿔 아래-> 위로 거꾸로 진행해 선택해야함. 
 2. 기본적으로 한 원소는, 바로 윗층의 좌, 우 중 한값을 선택해 물려받을 수 있다.   *** 
     (제일 앞,뒤 원소 제외 - 선택지 하나)
    즉, 원소(y, x)는 (y-1, x-1) or (y-1, x)중 더 큰값을 더해 원소값을 갱신해 저장하면된다. (아래->위로 원소 살피는 방식)
        
    
<기억사항>
 1. 벡터복사는 v1 = v2로 간단히 할 수 있다                           */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 누적합으로 저장 
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // 1. 누적합 벡터(sum)을 위해 미리 trianlge벡터 복사해 넣어둠    ***
    vector<vector<int>> sum = triangle;   
    // 2. 각 층마다 돌며 누적합으로 갱신 
    for(int i=1; i<sum.size(); i++){
        // 제일 앞
        sum[i][0] += sum[i-1][0];   // 선택지 하나 
        // 중간애들 
        for(int j=1 ; j<sum[i].size()-1; j++){
            sum[i][j] += max(sum[i-1][j-1], sum[i-1][j]);   // 양쪽 부모 중 더 큰값 선택가능 
        }
        // 제일 뒤
        sum[i][sum[i].size()-1] += sum[i-1][sum[i].size()-2];   // 선택지 하나 
        
        // 3. 제일 마지막층의 최댓값 반환 
        answer = *max_element(sum[triangle.size()-1].begin(),  sum[triangle.size()-1].end() );
    }
    
    return answer;
}
