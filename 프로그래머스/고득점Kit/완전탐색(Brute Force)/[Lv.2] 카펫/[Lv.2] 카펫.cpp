/*  x,y 사각형 연립방정식 문제 
사각형의 테두리 한겹 + 내용물 개수 세기 
<유의점>
 1. x+y = br/2 + 2
    x*y = br + yl
     => 1차 반복문을 돌려 두 조건 다 만족하는 x,y찾기 
 2. x > y이므로, y는 항상 sum의 제곱수보다 작음 ***           */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;       // x:가로, y:세로 

    int sum = brown + yellow;
    for(y=3; y*y<=sum; y++){        // x > y 이기 때문에 나올수 있는 조건 ***
        x = brown/2 + 2 - y;        // x + y = br/2 + 2
        // x * y = br + yl 조건이 맞다면 정답! 
        if(x*y == sum)
            answer = {x,y};
    }

    return answer;
}
