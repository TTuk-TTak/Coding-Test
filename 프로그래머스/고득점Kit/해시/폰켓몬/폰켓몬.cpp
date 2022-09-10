/* 종류의 개수 세는 문제 
<유의점>
 1. 종류별 폰켓몬 개수는 세지 않아도 됨! 
 
<제한사항>
 1. nums의 길이(N) 1 ~ 10,000 이하
 2. 폰켓몬의 종류 번호 1 ~ 200,000 이하
 => 정렬 or 해시 or 그리디 or DP                        */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int,int> um;  // <포켓몬번호, 개수>
    int max_size;
    
    // 1. 가져갈 수 있는 포켓몬 최대 개수(N/2) 계산
    max_size = nums.size()/2;
   
    // 2. 포켓몬 별 개수 세기 => map에 추가 
    for(auto elem: nums){
        um.insert(make_pair(elem,1));
    }
    
    // 3. [포켓몬 종류 수] VS  [가져갈 수 있는 최대 개수] 비교 후 더 큰 값 return 
    if(max_size < um.size())    // um.size() 는 포켓몬 종류 가짓수
        return max_size;
    else
        return um.size();

}
