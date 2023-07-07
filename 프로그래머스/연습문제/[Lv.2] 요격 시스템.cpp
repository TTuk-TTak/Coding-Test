/*

2중 vector 출력은 이런식으로
    for(auto i: targets)
        cout<<i[0]<<","<<i[1]<<endl;

2차원 vector sort 함수 만드는법

bool cmp(vector<int> & t1, vector<int> & t2) {
    return t1[1] < t2[1];
}

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


int solution(vector<vector<int>> targets) {
    int answer = 0;
    // 1. 우선 시작점(s) 기준으로 정렬          
    sort(targets.begin(), targets.end());
    
    int end = -1;
    // 2. (순회) 1중 for문을 도는 Greedy 
    for(int i=0; i<targets.size(); i++){
        // i)  [s,e]내에 end가 들어올 때   -> 겹치므로 그냥 제낌 
        if(targets[i][0]<end && targets[i][1]>=end)
            continue;
        // ii) end 지나서 [s,e]가 나올 때  -> 아예 새로운 걸로 end갱신 & answer ++ 
        if(targets[i][1]>=end)
            answer++;
        // iii) [s,e] 지나서 end가 나올 때 -> answer++은 안하지만, 놓칠 수 있으므로 end 갱신 
        end = targets[i][1];

    }

    return answer;
}
