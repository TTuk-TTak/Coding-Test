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
        // map에 아직 추가되지 않았다면
        if(um.find(elem) == um.end())
            um.insert(make_pair(elem,1));
        // map에 이미 추가되어 있다면
        else
            um[elem]++;
    }
    
    // 3. [포켓몬 종류 수] VS  [가져갈 수 있는 최대 개수] 비교 후 더 큰 값 return 
    if(max_size < um.size())    // um.size() 는 포켓몬 종류 가짓수
        return max_size;
    else
        return um.size();

}
