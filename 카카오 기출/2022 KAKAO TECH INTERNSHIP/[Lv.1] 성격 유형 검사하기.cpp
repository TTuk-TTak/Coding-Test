/* [성격유형 검사]*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

// 각 성격 유형 미리 map에 초기화 
map<char, int> m = {
    {'R',0}, {'T',0},
    {'C',0}, {'F',0},
    {'J',0}, {'M',0},
    {'A',0}, {'N',0}
};

// 성격유형 결정 => 유형별 점수 count 
string mbti(char a, char b){
    string ans = "";
    if(m[a] >= m[b])
        return ans +a;
    else
        return ans +b;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int score[8] = {0,3,2,1,0,1,2,3};           // 미리 점수를 배열에 표시해두는 것이 편함 *** 
    
    // 순회
    for(int i=0; i<choices.size(); i++){
        // 비동의
        if(choices[i]<4){
            m[survey[i][0]] += score[choices[i]];
        }
        // 모르겠음
        else if(choices[i]==4){
            continue;
        }
        // 동의
        else{
            m[survey[i][1]] += score[choices[i]];   
        }
    }
    
    // 유형 결정 
    answer += mbti('R','T');
    answer += mbti('C','F');
    answer += mbti('J','M');
    answer += mbti('A','N');
    
        
    return answer;
}
