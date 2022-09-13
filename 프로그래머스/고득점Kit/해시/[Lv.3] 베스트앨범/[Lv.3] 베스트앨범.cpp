/* 'hash' map을 또 value기준으로 '정렬'하는 문제
<유의점>
 1. index자체 = 곡 고유번호 이므로, for문 탐색 순서대로 answer 벡터에 넣는게 힘듦
 2. 사용하는 저장소 2개 ***
    (1) <장르명, 총재생횟수> 인 hash map 사용 -> 장르별 재생수 listing 위함 
    (2) <곡번호, 곡재생횟수>를 장르별로 2차원 vector에 저장해 사용 -> 장르별 곡 뽑기 위함 
 
<제한사항> 
 1. 재생횟수 같으면 -> 고유번호 낮은 노래부터 수록
 2. 장르에 속한곡 1개면, 1개곡만 선택  
 
<기억사항>
 1. 기본 map은, key값 기준으로 정렬되어있다.(value X)
 2. map에 그대로 sort함수 사용불가 
 3. map을 value값으로 정렬하는 법
    (1) map -> vector로 바꾸기 
    (2) vector를 'second'값 기준으로 정렬하는 compare 함수 작성
    (3) vector sort
 4. map -> vector로 바꾸는 법 ***
    vector<pair<type,type>> vec(map.begin(), map.end());
 5. compare 함수의 매개변수 = vector의 구성원소(즉, pair가 될수있음) */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 장르 총재생수 비교함수
int compare1(pair<string, int> a, pair<string,int> b){  // vector의 원소 = pair자체가 compare함수의 매개변수로 들어감 *** 
    return a.second > b.second;
}
// 개별곡 재생수 비교함수
int compare2(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        a.first < b.first;  // 곡 재생 수가 같다면, 고유번호가 낮은순 ! 
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> um;   // <장르명, 총재생횟수>
    
    
    // 1.장르별 총 재생횟수 합산
    for(int i=0; i<genres.size(); i++){
        um[genres[i]] += plays[i];
    }
    // 1-1.장르 map -> vector로 변환 ***
    vector<pair<string,int>> vec(um.begin(), um.end()); // 원소의미???
    // 1-2.장르 우선순위 정렬
    sort(vec.begin(),vec.end(),compare1);   // vector의 원소 즉, pair자체가 compare함수의 매개변수로 들어감 *** 
    
    
    // 2.곡 개별 고유변호&재생횟수 저장
    vector<vector<pair<int,int>>> lists(vec.size()); // <곡 고유번호, 재생횟수> pair를 장르별로 나눠 벡터에 저장
                                                     // index = 장르 우선순위 순서
    for(int i=0; i<genres.size(); i++){     // 곡을 돌며
        for(int j=0; j<vec.size(); j++){    // 장르 우선순위 파악
            if(vec[j].first == genres[i])   // j: 장르우선순위, i: 노래고유번호
                lists[j].push_back(make_pair(i,plays[i])); // 해당장르(j)에 pair를 push
        }
    }
    // 2-1.각 장르별, 곡 재생횟수 정렬
    for(int i=0; i<lists.size(); i++){
        sort(lists[i].begin(), lists[i].end(), compare2);   
        // 3. 정답벡터에 곡 고유번호 삽입 
        answer.push_back(lists[i][0].first);    
        if(lists[i].size() >= 2)            // 두곡 이상일 경우, 두곡까지만 수록
            answer.push_back(lists[i][1].first);
    }

    return answer;
}
