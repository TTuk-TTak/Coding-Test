/* 체육복 도둑맞고 앞뒤사람한테 빌리기 문제 

<유의점>
 1. 모든 사람수 N과 같은크기의 벡터를 기본 1(체육복 한개)로 설정
    도둑맞은 lost벡터의 index의 체육복을 --
    여분의 reserve벡터의 index의 체육복을 ++ 
    이후 한바퀴 돌며 앞->뒷 사람 차례로 체육복을 빌려보기 
 2. 제일 앞, 뒷 사람은 index 주의                             */

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes(n+1, 1);    // index 1부터 시작함, 체육복 기본 1개 세팅
    
    // 1. 체육복 도둑맞기
    for(int i=0; i<lost.size(); i++){
        clothes[lost[i]]--;
    }
    // 2. 체육복 여분받기
    for(int i=0; i<reserve.size(); i++){
        clothes[reserve[i]]++;
    }
    // 3. 체육복 나눠갖기
    for(int i=1; i<clothes.size()-1; i++){
        // 체육복 없다면 
        if(clothes[i] <= 0){
            // 3-1. 앞사람부터 확인 
            if(clothes[i-1] >= 2 && i != 1){
                clothes[i-1]--;
                clothes[i]++;
            }
            // 3-2. 다음에 뒷사람 확인
            else if(clothes[i+1] >= 2){
                clothes[i+1]--;
                clothes[i]++;
            }
        }
    }
    // 체육복 있는사람 count
    for(int i=1; i<=n; i++){
        if(clothes[i] >= 1)
            answer++;
    }

    return answer;
}
