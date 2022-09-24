/*
unsigned 가 매우 중요 !!!!!!! ***** 
while은 (low<high)일때로 제한 
해당 인원을 커버가능하다고 바로 답 x 그 중 최솟값 찾아야함 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    // 초기값 설정 high, mid, low 
    int max = *max_element(times.begin(), times.end());
    unsigned long long high = max*n; // 최대 걸리는 시간 수 
    unsigned long long low = 0;
    unsigned long long mid;
   
                
    while(low <= high){               // 이분탐색 조건    *** 
        // mid 갱신 
        mid = (high+low)/2;
        
        cout<<high<<" "<<mid<<" "<<low<<"\n";
        
        // sum: 커버할 수 있는 사람 수 계산
        unsigned long long sum = 0;   
        for(int i=0; i<times.size(); i++){
            sum += mid/(times[i]);
        }
        
        // down
        if(sum >= n){   
            if(answer == 0)     // 처음엔 그냥 mid값
                answer = mid;
            else                // 그 이후론 최솟값 
                answer = min(answer, mid);
            high = mid -1;
        }
        
        // up
        else{   // if(sum < n)
            low = mid +1;
        }
    }
    return answer;
}
