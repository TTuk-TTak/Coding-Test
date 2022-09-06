/* 참여자중 완주자 제외 1명 미완주자 골라내는 문제 
<유의점>
 1. participant와 completion 사이의 순서 주의! (더 많은 participant 먼저 map에 입력)
 2. 동명이인 존재 => 이름& 명수까지 함께 저장해야함 => unordered_map(중복불가) 

<제한사항>
 1. 선수 1~100,000 => O(n logn) => 정렬 or 해시 or 그리디 or DP 
  
<기억사항>
 (unordered_map)
 1. .find는 원소 없을 시, .end()를 호출(default: 반복자iterator) *** 
 2. um[elem]에 연산 시, unordered_map의 <key,value> 중 'value'에 계산됨
 3. 모든 원소 출력 시, 반복자는 
        for(auto elem: um)  X
        for(auto elem=um.begin(); elem!=um.end(); elem++)   O
    출력하는 원소는
        cout << elem->first;    ***                        */

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> um;
    
    // 1. 완주자 listing
    for(auto elem: completion){
        // i) 찾는 elem 가 없을 시 
        if(um.find(elem) == um.end())
            um.insert(make_pair(elem,1));
        // ii) 있을 시 
        else    
            um[elem]++;     // value 에 +1 
    }
    
    /*
    // 출력 확인 
    for(auto elem=um.begin(); elem!=um.end(); elem++){  //for(auto elem: um){
        cout<<(elem->first)<<"\n";
    }*/
    
    // 2. 참여자 listing - 제외
    for(auto elem: participant){
        // i) 참여자가 완주자 목록에 없을 시 
        if(um.find(elem) == um.end())   
            return elem;
        // ii) 있을 시 
        else{
            um[elem]--;
            if(um[elem] < 0)    // 동명이인 가능성 
                return elem;
        }
    }

    return answer;
}
