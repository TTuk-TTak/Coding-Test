/* 그래프 탐색문제 (edge 개수 비교)
<유의사항>
 1. 그래프 문제 -> {인접행렬}로 바꾸어, {DFS}로 접근해 풀기         ***
    특히, 무한루프 돌 가능성 있으므로 visited(중복제거)에 신경쓰기    ***
 2. 그래프 문제에선 항상,   {edge개수 != node개수}       *** 
    edge(연결)개수 = wires.size()
    node(송전탑)개수 = n                 가 서로 다르므로, 반복문 사용 시 항상 주의해서 사용해야함.
 3. 송전탑번호 #1,#2, ... 은 1부터 시작하기에 
    인접graph의 index도 맞춰서 0제외하고 시작    ***
 4. 연결 하나씩 제거할 때, vector, 인접graph 둘다에 작업하는 것 잊지말기 ***
    
<기억사항>
 1. size는 예약어라 전역변수로 사용못함 X
 2. .size()함수를 복잡한 계산식에 직접넣어 하면 주소값찍히며 오염됨 => 따로 변수에 저장 후 사용 ***
 3. set은 중복제거 용도 
 4. vector 함수 
    (삭제) v.erase(v.begin() + i);
    (삽입) v.insert(v.begin() + i, k);                        */

#include <string>
#include <vector>
#include <algorithm>
#include <set>  
using namespace std;

int graph[101][101] = {0}; // tree -> 인접graph  
int visited[101] = {0};     
set<int> group1;           // 한쪽 전력망에 속하는 송전탑 목록 
int gap =0;                // 두 전력망의 송전탑 수 차이 


// 재귀함수 
void recur(int n, int num){     // n: 총 송전탑 갯수, num: 현재 송전탑 번호 
    // 인접graph를 탐색하며 (num -> i)
    for(int i=1; i<n; i++){     // index =0 인곳은 배부된 송전탑 번호 없어서 안씀 *** 
        if(graph[num][i] == 1 && visited[i] == 0){  
            // 두 송전탑 다 방문한 것이므로 이어진 송전탐들 다 한쪽그룹에 넣음. (set => 중복x)
            group1.insert(num);
            group1.insert(i);
            // 방문check & 그래프 탐색 
            visited[i] = 1;
            recur(n, i);
            visited[i] = 0;
        }  
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;       
    // 1. 인접행렬에 그래프 입력 
    for(int i=0; i<wires.size(); i++){
        graph[wires[i][0]][wires[i][1]] = 1;
        graph[wires[i][1]][wires[i][0]] = 1;    // 두쪽 다 해야지 완전 탐색 됨 ***
    }
    // 2. 완전탐색 - 직접 하나씩 연결 끊어보며 직접 연결된 수 세기     *****
    for(int i=0; i<wires.size(); i++){
        vector<int> tmp;
        tmp = wires[i];
        // 하나씩 연결 끊어봄 (행렬&벡터 둘다)    
        graph[wires[i][0]][wires[i][1]] = 0;    // 순서주의 !   *** 
        graph[wires[i][1]][wires[i][0]] = 0;
        wires.erase(wires.begin()+i);

        // 탐색시작
        recur(n+1, wires[0][0]);                // n+1 => index와 문제의#번호 일치시키기!         ***
                                                // 첫 시작원소부터 탐색시작.       // visited check 하고 들어가면 오류 *** 
        // 연결 다시 붙이기 
        wires.insert(wires.begin()+i, tmp);     // 미리 tmp로 저장해둔 1차원vector 원래 위치에 삽입 *** 
        graph[wires[i][0]][wires[i][1]] = 1;    // 순서주의 !   *** 
        graph[wires[i][1]][wires[i][0]] = 1;
        
        // 답 찾기 (차잇값 구하기)
        int cnt = group1.size();       // .size()함수를 복잡한 계산식에 직접넣어 하면 주소값찍히며 오염됨 => 따로 변수에 저장 후 사용 ***
        if(cnt - (n-cnt) < 0)          // (-) -> (+) 
            gap = -(cnt - (n-cnt));
        else
            gap = cnt - (n-cnt);
        answer = min(answer, gap);     // 더 작은 차잇값이 답 
        group1.clear();
    }
    
    return answer;
}
