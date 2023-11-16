/* [DP]
 - 숫자 N, 사칙연산만으로 목표값을 만들어내는 문제 
 
 - DP배열 => 단계별로 index나누어 2차원으로 저장 
 - f(i) : N을 i번 사용해서 만들 수 있는 숫자의 모음 
    (모든 f(i)는 합이 i가 되는 두 f() 사이의 사칙연산으로만 이루어진다!!) *****
    
 - f(1) = N
 - f(2) = NN, f(1)□f(1)
 - f(3) = NNN, f(2)□f(1)
 - f(4) = NNNN, f(3)□f(1), f(2)□f(2)
 - f(5) = NNNNN, f(4)□f(1), f(3)□f(2)

 - 구현)
 - vector 내부의 set으로 구성
 - vector<unordered_set<int>> v(10, unordered_set<int>(10))
    - vector : f(1),f(2),f(3)... 각 단계를 v[1],v[2],v[3] 벡터의 각 index에 구분해놓음
    - set    : 중복 x, 중복되는 수 삭제 위해 사용, 각 vector index에 사용 
    
 - 주의사항)
    - map{f(N), lv} 으로 구현도 생각해보았으나, lv을 기준으로 단계나누기 쉽지 않아 채택 X
    - TC - 1,8 => 사칙연산중 '빼기' 구현 안할 경우 ERROR
        반례) nubmer 5 = 6 - (6/6) 이 가장 빠른 구현 
    - 빼기, 나누기 => if조건으로 잘 확인 한 후 사용하기                               */

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;


vector<unordered_set<int>> v(10, unordered_set<int>(10));     // 10: 크기 //구현 ***

// NNNNN ...  함수 
int arrange(int N, int lv){
    int sum = 1;
    for(int i=0; i<lv-1; i++)
        sum = sum*10 +1;
    return sum*N;
}

int solution(int N, int number) {
    int answer = -1;
    // 초기값 설정 
    v[1].insert(N);
    for(int i=2; i<=9; i++){                        // 8 이상이면 -1 return 
        // 0. number 도달 여부 확인 
        if(v[i-1].find(number) != v[i-1].end())
            return i-1;
        
        // 1. NNNN ... 추가
        v[i].insert(arrange(N,i));
        
        // 2. f(N) = f(a) + f(b)   (N = a+b) 추가 
        for(int a=1; a<i; a++){
            // 각 case의 원소들 match의 모든 경우 
            for(auto j: v[i-a]){
                for(auto k: v[a]){
                    // 사칙연산 
                    v[i].insert(j+k);
                    v[i].insert(j*k);
                    if(j>k)
                        v[i].insert(j-k);
                    if(j%k==0 && j/k!=0)
                        v[i].insert(j/k);
                }
            }
        }
    }
    
    // 출력 확인용
    /*
    for(int i=0; i<=9; i++){
        for(auto j:v[i])
            cout<<j<<" ";
        cout<<"\n";
    }*/
    
    return answer;
}
