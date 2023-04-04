/*
string 재귀문제
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string words[] = {"aya","ye","woo","ma"};
int visit[4] ={};
vector<string> candidates ={};

// 재귀
void recur(int lv, string bab){
    //cout<<bab<<"\n";
    candidates.push_back(bab);
    //level
    if(lv >=4 ){
        return;
    }
    //branch
    for(int i=0; i<4; i++){
        if(visit[i]==1)
            continue;
        visit[i]=1;
        recur(lv+1, bab + words[i]);
        visit[i]=0;
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    // 후보군 생성 
    recur(0, "");
    // input 이 후보군 중에 있나 확인 
    for(int i=0; i<babbling.size(); i++){
        if(find(candidates.begin(), candidates.end(), babbling[i]) != candidates.end())
            answer++;
    }
    return answer;
}
