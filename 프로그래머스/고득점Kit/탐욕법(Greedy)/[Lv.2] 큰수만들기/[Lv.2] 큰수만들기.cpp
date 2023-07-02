/*
<주의사항>
erase(시작idx, 지울char개수)      // 도착idx 아님 

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer;
    int cnt = 0;        // 제거 횟수 count 
    int i = 0;          
    
    
    while(cnt<k){                       // 제거횟수 미만동안 반복 
        // 끝까지 모두 탐색했을 시 중지 
        if(i > number.length()-2)
            break;
        
        // 1. 앞-뒤 숫자비교  =>  앞글자가 더 작으면 삭제
        if(number[i] < number[i+1]){    
            number.erase(i,1);         
            cnt++;
            // 삭제 시 => index 땡겨서 그 앞부분과 비교할 필요 있음  *****
            if(i != 0)
                i--;
        }
        // 삭제된거 없을 땐 정상적으로 i++ 
        else
            i++;
    }
    
    // 2. 제거된 개수가 부족하다면 => 가장 뒤쪽에서부터 남은개수만큼 지움 (TC:12 조건)          
    // (어차피 지금까지 남은건, 내림차순 아니면 같은 숫자란 소리)
    if(cnt < k)
        number.erase(number.length()-(k-cnt), (k-cnt));
    
    answer = number;
    return answer;
}
