/* [조합] 경우의 수 세는 문제 
<유의점>
 1. (종류별 개수 + 1)*(종류별 개수 + 1)*(..)*... -1 조합식 사용*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int cases = 1;
    unordered_map<string,int> um; 
    // 1. hash맵에 옷 종류별 개수세서 저장
    for(int i=0; i<clothes.size(); i++){
        um[clothes[i][1]]++;
    }
    // 2. 조합 경우의 수 계산
    for(auto elem=um.begin(); elem!=um.end(); elem++){ 
        cases *= ((elem->second)+1);
    }
    return cases-1;
}
