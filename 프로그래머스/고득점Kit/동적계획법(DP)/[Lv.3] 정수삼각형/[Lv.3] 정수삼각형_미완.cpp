#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 누적합으로 저장 
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> sum = triangle;
    for(int i=1; i<sum.size(); i++){
        // 제일 앞
        sum[i][0] += sum[i-1][0];
        // 중간애들 
        for(int j=1 ; j<sum[i].size()-1; j++){
            sum[i][j] += max(sum[i-1][j-1], sum[i-1][j]);
        }
        // 제일 뒤
        sum[i][sum[i].size()-1] += sum[i-1][sum[i].size()-2];
        
        
        answer = *max_element(sum[triangle.size()-1].begin(),  sum[triangle.size()-1].end() );
    }
    
    return answer;
}
