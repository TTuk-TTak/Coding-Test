/*
<주의사항>
vector에서는 pop_front 안됨 (deque에서만 가능)
vector.erase(vector.begin())으로 대체 

deque는 vector의 단점을 보완하기 위해서 만들어진 container 입니다.
deque도 vector와 마찬가지로 배열기반의 구조입니다.
vector는 새로운 원소가 추가 될때 메모리 재할당 후 이전 원소를 복사하는 방식으로 인하여,  삽입시에 성능이 저하 하는 단점이 있습니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 1. 정렬
    sort(people.begin(), people.end(),greater<>());

    // 2. vector to deque
    deque<int> dq(people.begin(), people.end());       
    
    // 3. 
    int sum = limit; 
    while(!dq.empty()){
        if(sum>=dq.front()){
                sum-=dq.front();
                dq.pop_front();
        }
        else if(sum>=dq.back()){
                sum-=dq.back();
                dq.pop_back();
        }else{
            answer++;
            sum = limit;
        }
    }
    
    return answer+1;
}
