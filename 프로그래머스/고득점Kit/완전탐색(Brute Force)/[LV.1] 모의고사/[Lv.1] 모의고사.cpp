/* 주기가 다른 여러 배열끼리 원소 비교하는 문제 
<유의점>
 1. 주기에서 규칙찾아 구현하려 하지말고, 주기 => 그대로 저장 후 사용 !!! ***
 2. 브루트포스(완전탐색) => 1중 for문 이내에서 해결! 
    
<제한조건>
 1. 1~10,000 이 범위이므로 => 브루트포스(완전탐색)  */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ans;
    vector<int> grade = {0,0,0};                // 수포자 1,2,3의 채점 성적표
    vector<int> one = {1,2,3,4,5};              // 수포자 1의 주기        ***
    vector<int> two = {2,1,2,3,2,4,2,5};        // 수포자 2의 주기
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};  // 수포자 3의 주기
    int max = 0;
    
    // 각자 채점 시작
    for(int i=0; i<answers.size(); i++){
        if(one[i%one.size()] == answers[i])   
            grade[0]++;
        if(two[i%two.size()] == answers[i])
            grade[1]++;
        if(three[i%three.size()] == answers[i])
            grade[2]++;
    }
    // 가장 높은 점수 찾기 
    max = *max_element(grade.begin(), grade.end());
    // 가장 높은 점수 받은사람 list
    for(int i=0; i<3; i++){
        if(max == grade[i])
            ans.push_back(i+1);
    }
    
    return ans;
}
