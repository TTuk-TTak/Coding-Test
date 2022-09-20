/* 가로x세로 뒤집는거 가능할 때, 모든 size의 명함을 수납할 수 있는 {가장 작은 직사각형 크기구하기} 문제
<유의점>
 1. [접근방식]
    (가로,세로) 중, 더 큰쪽을 가로로 무조건 고정한다       *** 
    그럼, (가로max * 세로max)값이 모든 size를 커버가능 
 2. 가로,세로라고 굳이 이름 붙여놔서 헷갈리는 거임 
 3. [시도]
    3중 for문으로, 모든 경우를 다 돌며 check하려했는데 edgecase 오류 + 시간초과 
    * min의 default값이 가로x세로로 나올수 없는 값이 되는 경우가 error라 예상
    
<제한조건>
 1. 1~10,000 이 범위이므로, 3중for문 절대안됨 => 조건고정하기
 2. 브루트포스(완전탐색)은 최대한 1중for문 내에서 해결 
 
<기억사항> ***
 1. 브루트포스(완전탐색)은 {한가지 조건을 무조건 고정}하는 것이 중요!!! ****    */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w, max_h = 0;
    // 큰쪽을 무조건 가로로 놓기 
    for(int i=0; i<sizes.size(); i++){
        // 세로가 더 크다면, 가로x세로 순서바꾸기 
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        // 제일 큰값으로 max 갱신 
        max_w = max(sizes[i][0], max_w);
        max_h = max(sizes[i][1], max_h);
        
        // 위 모든 내용 다음과 같이 두줄요약 가능 ***
        //w=max(w,min(sizes[i][0],sizes[i][1]));
        //h=max(h,max(sizes[i][0],sizes[i][1]));
        
    }
    return max_w*max_h;
}
