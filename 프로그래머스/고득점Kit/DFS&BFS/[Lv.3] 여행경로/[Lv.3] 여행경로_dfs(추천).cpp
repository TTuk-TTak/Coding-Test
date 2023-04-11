/* 모든 항공권 다 사용해, 알파벳 순서로 여행경로 짜기 - string 재귀 

  재귀함수에 path도 (string 형태의) 함수파라미터로 전달하며, 실시간 업데이트 하는 방법 *** 

*/
#include <string>
#include <vector>
#include <iostream>
#define N 10000

using namespace std;

int tries = 0;
int TIKS;
vector<vector<string>> TICKETS;
vector<int> visited;  // (TIKS)로 resize
string PATH;

void recur(int lv, string city, string path){ 
    // level
    if(lv >= TIKS){
        // (알파벳순)으로 앞선 걸로 update
        if(path < PATH)
            PATH = path;
        return;
    }
    
    // branch                   => tickets 벡터 탐색 
    for(int i=0; i<TIKS; i++){
        if((city == TICKETS[i][0])&&(visited[i]==0)){
            visited[i] = 1;
            recur(lv+1, TICKETS[i][1], path + TICKETS[i][1]);   // path 뒤에 추가하기 
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    // 전역변수로 변환 
    TIKS = tickets.size();
    TICKETS = tickets;
    visited.resize(TIKS);    
    // 값 비교위한 PATH 초기화 
    for(int i=0; i<TIKS; i++)
        PATH += "ZZZ";
    
    recur(0, "ICN", "ICN");                 // (level, city, path)
    
    // PATH(스트링) => answer(벡터)로 변환 
    for(int i=0; i<3*(TIKS+1); i+=3){       // 세글자씩 끊어 넣기 
        string str = PATH.substr(i,3);
        answer.push_back(str);
    }
        
    return answer;
}
