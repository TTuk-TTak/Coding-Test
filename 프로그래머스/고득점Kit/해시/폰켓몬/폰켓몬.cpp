/* 종류의 개수 세는 문제 
<유의점>
 1. 종류별 폰켓몬 개수는 세지 않아도 됨! 
 
<제한사항>
 1. nums의 길이(N) 1 ~ 10,000 이하
 2. 폰켓몬의 종류 번호 1 ~ 200,000 이하
 => 정렬 or 해시 or 그리디 or DP       
 
 <기억사항>
 1. hash[key] += 1; 와 같은 방식으로 연산하면, key값이 없어도, 자동으로 insert 후 연산 ***     
 2. min 함수로 최소값 return 가능                                                         */

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
        //um[elem] += 1;      // or 이 방법으로 insert + 연산 바로 
    }
    
    // 3. [포켓몬 종류 수] VS  [가져갈 수 있는 최대 개수] 비교 후 더 큰 값 return 
    if(max_size < um.size())    // um.size() 는 포켓몬 종류 가짓수
        return max_size;
    else
        return um.size();
    //  return min(nums.size() / 2, s.size()); 로 한줄정리 가능

}
