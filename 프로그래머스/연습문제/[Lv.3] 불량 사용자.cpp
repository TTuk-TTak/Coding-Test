#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> UID;
vector<string> BID;
vector<int> Visited;
int U;
int LV;
int answer = 0;             // 갯수 세기
vector<string> answerlist;  // 정답 벡터 (중복제거 용도)

void recur(int level, vector<string> ids){
    // level (= banned_id 갯수)
    if(level >= LV){
        // banned_id와 일치하는지 확인 
        for(int i=0; i<LV; i++){
            // 사이즈 모두 일치하는지 우선 확인 
            if(BID[i].size() != ids[i].size())
                return;
            // 사이즈 일치한다면 index 탐색 할 수 있음 
            for(int j=0; j<BID[i].length(); j++){
                if(BID[i][j]=='*')
                    continue;
                if(BID[i][j]!=ids[i][j])
                    return;
            }     
        }
        // 넣을지 확인(중복여부 확인)
        string s="";
        sort(ids.begin(), ids.end());
        for(auto i:ids){
            s+=i;
        }
        if(find(answerlist.begin(), answerlist.end(), s) == answerlist.end()){
            answerlist.push_back(s);
            answer++;
        }
        return;
    }
    
    // branch = user_id 갯수 (남은)
    for(int i=0; i<U; i++){
        if (Visited[i]==1)
            continue;
        Visited[i]=1;
        ids.push_back(UID[i]);
        recur(level+1, ids);
        ids.pop_back();
        Visited[i]=0;
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    UID = user_id;
    BID = banned_id;
    LV = banned_id.size();
    U = UID.size();
    Visited.resize(U);
    
    // 재귀 
    vector<string> v;
    recur(0, v);
    
    return answer;
}
