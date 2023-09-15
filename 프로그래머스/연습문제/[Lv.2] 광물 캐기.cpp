#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

vector<int> PICKS;
vector<int> MINERALS;
int DMG = 25*50;         
int NPICK = 0;      // 광물 다캐는데 필요한 곡괭이 개수
int damage[3][3] ={     // [picks] [mineral]
    {1,1,1}, 
    {5,1,1}, 
    {25,5,1}
}; 


void dfs(int lv, int damages){    // branch = 곡괭이 종류 3개 , 누적데미지
    // 곡괭이or광물 고갈 시, 
    if(lv == NPICK){
        DMG = min(DMG, damages);
        return;
    }
    // 곡괭이 종류 중 고르기 
    for(int i=0; i<3; i++){
        // 곡괭이 해당 종류가 남았을 시, 
        if(PICKS[i]>0){
            PICKS[i]--;
            // 피로도 적산
            int p =0;
            int j = lv*5;       // 5광물 per 1곡괭이 
            while(j<lv*5+5 && j<MINERALS.size()){
                p += damage[i][MINERALS[j]];
                j++;
            }
            // 재귀 
            dfs(lv+1, damages+p);
            PICKS[i]++;
        }
    }
    
}

int solution(vector<int> picks, vector<string> minerals) {
    // set GLOBAL VARIABLE
    PICKS = picks;
    // set minerals (string -> int)
    for(auto n: minerals){
        if(n == "diamond") MINERALS.push_back(0);
        else if(n == "iron") MINERALS.push_back(1);
        else MINERALS.push_back(2);
    }
    
    // set NPICK = needpicks
    int np = (minerals.size() + 5 - 1)/5;               // 광물 다캐는데 필요한 곡괭이 개수 
    int sp = accumulate(picks.begin(), picks.end(), 0); // 준비된 곡괭이 개수 
    NPICK = min(np,sp);
    
    // find min 
    dfs(0, 0);  
    
    return DMG;
}
