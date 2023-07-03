/* 문자열 number에서 k개 숫자를 제거해 만들 수 있는 가장 큰 수 구하기 

 {Greedy 탐욕법}
 => 바로 앞/뒤 숫자만 비교해 앞쪽에 큰수를 남기는 방법으로 해결 
 => 눈앞의 이익(여러 경우의 수 X 바로 앞뒤만 비교 후 넘김)만 쫓으므로 그리디 탐욕법 
 => Greedy는 1중 for문 에서 끝내야 효율성 통과 ****** 

<유의점>
 1. 앞자리수가 높을수록 큰수이다.
 2. 단, 쓰여진 수 중 최댓값이 제일 앞에 오지 못할 수도 있다. (제거가능 수 k개 제한)
 3. 끝까지 탐색할 때까지 k개 제거하지 못하면, =어차피 계속 같은 수 or 내림차순 이었단 소리이므로
    가장 마지막의 숫자들을 지우는 것이 최선의 방법 

 
<제한사항>
 1. number 는 2 ~ 1,000,000 자리수
 => 모든 경우의 수 비교해보기에는 너무 큼 -> {Greedy} 힌트 얻기 

<기억사항>
 1. erase(시작idx, 지울char 개수)      // 두번째 parameter주의!! 도착 idx아님! 
 2. vector 순회 시(i++), 중간에 삭제연산이 있을 때 -> index건너 뛸 수 있으므로 주의! *** */

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer;
    int cnt = 0;                        // 제거 횟수 count 
    int i = 0;          
    
    while(cnt<k){                     
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
    
    // 2. 제거된 개수가 부족하다면 => 가장 뒤쪽에서부터 남은개수만큼 지움 (TC:12 조건위반)        
    if(cnt < k)
        number.erase(number.length()-(k-cnt), (k-cnt));
    
    answer = number;
    return answer;
}
