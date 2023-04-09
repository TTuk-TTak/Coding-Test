#include <string>
#include <vector>
#include <iostream>
#define N 10000

using namespace std;

int TIKS;
vector<vector<string>> TICKETS;
vector<string> path;  // (TIKS+1)로 resize
vector<int> visited;  // (TIKS)로 resize

void recur(int lv, string city){
    cout<<city<<" "<<lv<<"\n";
    path[lv] = city;
    // level
    if(lv >= TIKS){
        return;
    }
    // branch
    for(int i=0; i<TIKS; i++){
        if((city == TICKETS[i][0])&&(visited[i]==0)){
            visited[i] = 1;
            recur(lv+1, TICKETS[i][1]);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    TIKS = tickets.size();
    TICKETS = tickets;
    visited.resize(TIKS);       // resize 안하면 core dump out 됨 
    path.resize(TIKS+1);
    
    recur(0, "ICN");

    return path;
}
