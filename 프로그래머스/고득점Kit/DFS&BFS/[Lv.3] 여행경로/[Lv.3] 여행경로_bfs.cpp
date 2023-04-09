#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define N 10000

using namespace std;


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int TIKS = tickets.size();
    vector<string> path(TIKS+1);
    vector<int> visited(TIKS);
    queue<pair<string,int>> q; 
    
    // 정렬
    int j;
    sort(tickets[j].begin(), tickets[j].end());
    
    q.push(make_pair("ICN",0));
    while(!q.empty()){
        // q 첫자료 뽑기 
        string city = q.front().first;
        int lv = q.front().second;
        q.pop();
        // 종료조건
        if(lv >= TIKS+1)
            break;
        // 기록 남기기
        cout<< "lv:"<<lv<<"  city:"<<city<<"\n";
        path[lv] = city;
        // tickets 탐색
        for(int i=0; i<TIKS; i++){
            if(tickets[i][0] == city){
                q.push(make_pair(tickets[i][1],lv+1));
                visited[i] = 1;
            }
        }
        
    }
    
    return path;
}
