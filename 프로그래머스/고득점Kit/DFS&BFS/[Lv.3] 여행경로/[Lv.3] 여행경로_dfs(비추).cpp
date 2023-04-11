/* 모든 항공권 다 사용해, 알파벳 순서로 여행경로 짜기 

<유의점>
  1. +visited +path
  2. 외에도, 재귀함수에 path도 (string 형태의) 함수파라미터로 전달하며, 실시간 업데이트 할 수 있음 (모든 공항이름이 3글자라서 가능) *****
  
<제한사항>
  1. 모든 항공권 다 사용 (갔던 도시 다시가도 ㄱㅊ)
  2. 가능한 경로 여러개일 경우 알파벳 순 앞선 것으로 return => 경로path 갱신여부 판단이 중요 *** 
  3. 공항수는 3 ~ 10,000
  
<기억사항>
  1. vector 전역 변수로 사용할거면, 함수 내에서 resize해서 반드시 초기화 후 사용! => 아니면 core dump! 



*/
#include <string>
#include <vector>
#include <iostream>
#define N 10000

using namespace std;

int tries = 0;
int TIKS;
vector<vector<string>> TICKETS;
vector<string> path;  // (TIKS+1)로 resize
vector<string> path_re;
vector<int> visited;  // (TIKS)로 resize

void recur(int lv, string city){
    // 경로 저장 
    path_re[lv] = city;
    
    // level
    if(lv >= TIKS){
        // path 갱신 횟수 저장 
        tries++;
        
        // 처음 path 저장이면 바로 저장 
        if(tries == 1){
            path = path_re;
            return;
        }
        
        // 처음 path 저장이 아니라면 갱신여부 판단 
        for(int i=0; i<TIKS; i++){
            // 1. 같은 도시인 경우, 다음 거 check 
            if(path[i]==path_re[i])
                continue;
            // 2. 다른 도시인 경우, 순서 앞설경우 path 갱신
            else if(path[i] > path_re[i]){
                path = path_re;
                return;
            }
            // 3. 다른 도시인 경우, 순서 뒤일경우 갱신 X 바로 버림 
            else
                return;
        }
    }
    
    // branch                   => tickets 벡터 탐색 
    for(int i=0; i<TIKS; i++){
        if((city == TICKETS[i][0])&&(visited[i]==0)){
            visited[i] = 1;
            recur(lv+1, TICKETS[i][1]);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 전역변수로 변환 
    TIKS = tickets.size();
    TICKETS = tickets;
    // 전역 vector Resize         => resize 안하면 core dump!
    visited.resize(TIKS);      
    path.resize(TIKS+1);
    path_re.resize(TIKS+1);
    
    recur(0, "ICN");

    return path;
}
