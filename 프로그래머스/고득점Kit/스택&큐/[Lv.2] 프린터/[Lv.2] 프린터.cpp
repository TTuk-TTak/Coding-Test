#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; // 턴 수를 체크하면 몇번째로 나오는지 확인 가능 x안됨 
    int max;
    
    // 똑같은 벡터 만들기
    vector<int> check_v(priorities.size(), 0);
    check_v[location] = 1;

    while(1){
        max = *max_element(priorities.begin(), priorities.end());
        // 1. 다른 우선순위가 있을 시, => 뽑아서 제일 뒤에 넣음 
        if(priorities.front() < max){
            priorities.push_back(priorities.front());   // 뒤에 넣고    // begin 이면 오류남 
            priorities.erase(priorities.begin());       // 앞에 삭제 
            
            check_v.push_back(check_v.front());
            check_v.erase(check_v.begin());
        }
        // 2. 1순위 일 시, => pop
        else{
            priorities.erase(priorities.begin());   
            answer++;
            if(check_v.front() == 1)
                break;
            check_v.erase(check_v.begin());
        }
    }
    
    return answer;
}
