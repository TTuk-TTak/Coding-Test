/*

2중 vector 출력은 이런식으로
    for(auto i: targets)
        cout<<i[0]<<","<<i[1]<<endl;


*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


bool cmp(vector<int> & t1, vector<int> & t2) {
    return t1[1] < t2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    // 1. 우선 시작점(s) 기준으로 정렬
    sort(targets.begin(), targets.end(),cmp);
    
    int end = -1;
    // 2. (순회) 1중 for문을 도는 Greedy 
    for(int i=0; i<targets.size(); i++){
        //cout<<"s"<<targets[i][0]<<" end:"<<end<<"  "<<"answer:"<<answer<<endl;
        // ii) end범위 안일때 
        if(targets[i][0] < end && targets[i][1]>=end)
            continue;
        // i) end를 넘길때 
        end = targets[i][1];
        answer++;

    }

    
    return answer;
}
