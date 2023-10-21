/*
 겹치지 않는 Time Table 문제 =>  [우선순위 큐] Priority_queue !!! *****
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> intbooktime;

// [함수] 24시간 표기법 => 분(int)로 바꾸기
int change24toMin(string time){
    int hour, minute;
    hour = 60 * stoi(time.substr(0,2));                         // substr(시작idx, 크기) ***끝 idx 아님 ***
    minute = stoi(time.substr(3,2));
    return hour + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;                                             // 방 초기 개수 = 0아니고 1 *
    priority_queue<int, vector<int>, greater<int>> pq;          // priority_queue 오름차순 선언법! *****
    
    // 1. 입실시간 순으로 정렬 
    sort(book_time.begin(), book_time.end());
    
    // 2. Minute으로 변환 후 재저장 작업 
    for(int i=0; i<book_time.size(); i++){
        int starttime = change24toMin(book_time[i][0]);
        int endtime = change24toMin(book_time[i][1]) + 10;      // 청소시간 10분 더하기 
        intbooktime.push_back({starttime, endtime});
    }
    
    
    // 3. pivot 으로 설정 + 알고리즘,,, => priority_q
    pq.push(intbooktime[0][1]);
    for(int i=1; i<intbooktime.size(); i++){
        // (1) 비는 방이 있다면 (현재 입실시간 >= 제일빠른 퇴실시간) => 퇴실시간 된 애 빼기
        if(intbooktime[i][0] >= pq.top())
            pq.pop();
        // (2) 비는 방이 없다면 (현재 입실시간 < 제일빠른 퇴실시간) => 방 추가
        else
            answer++;
        pq.push(intbooktime[i][1]);
    }
    
    return answer;
}
