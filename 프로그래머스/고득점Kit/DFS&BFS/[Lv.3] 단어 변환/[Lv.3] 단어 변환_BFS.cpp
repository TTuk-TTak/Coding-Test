/* begin -> target으로 단어가 바뀔 때 가장 짧은 변환과정 찾기 문제 

<유의점>
 1. 이문제는 {최단거리} 문제와 같다. 
    하나씩 바뀌는 단어를 찾아가며 변환할 수 있는 단어를 q에 넣음    (words벡터를 돌며 단어탐색)
    = map에서 사방을 탐색하며 갈수있는 길을 한단계씩 q에 넣음     (dir배열을 돌며 사방탐색)

<제한사항>
 1. 단어의 길이 3~10 & 모든 단어의 길이 같음 & 모두 소문자
 2. words벡터는 크기가 3~50
 
<기억사항>
 1. bfs에선, 현재상황이 몇단계인지 level을 
            queue에 항상 같이 넣어 표시해가며 진행해야 한다. (O)        ***
            전역변수로 count 하기 (X)
 2. bfs에선, 간단하다면 3중 for문까지는 나와도 ㄱㅊ          ***         
 3. char는 아스키연산 or 캐스팅 후 int로 간단히 출력가능      
    string은 불가능                                     ***
 4. string 끼리 직접 연산은 되지만, string 변수에 넣어 연산은 불가능 
        ex)
        cout << "hit" - "hot";  // 가능(o) - string을 직접넣기
        cout << begin - target; // 불가능(x) - 변수(string)을 연산하기 */


#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int size = begin.size();                // 한 단어의 길이 
    vector<int> visited(words.size(), 0);   // words벡터와 같은크기의 visited 벡터 만들기(방문표시용) ***
    queue<pair<string,int>> q;              // <단어, level(변형된지 몇단계인지)>
    
    // 0. 초기값 넣기 
    q.push({begin,0});
    // 1. bfs 시작 
    while(!q.empty()){
        // 2. 값 세팅후 pop
        string now = q.front().first;
        int level = q.front().second;
        q.pop();
        // 2-1. 종료조건 = target단어로 변환완료된 경우
        if(now == target){
            answer = level;
            break;
        }
        // 3. bfs탐색하며
        for(int i=0; i<words.size(); i++){
            // 3-1. 이미 방문했으면 pass
            if(visited[i] == 1)
                continue;
            // 3-2. 한 단어에서 같은 글자수 세기 
            int cnt =0;
            for(int j=0; j<size; j++){
                if(words[i][j] == now[j])
                    cnt++;
            }
            // 3-3. 하나빼고 모든 글자가 같다면 변환 가능 
            if(cnt >= size-1){
                visited[i] = 1;
                q.push({words[i], level+1});
            }
        }
    }
    
    return answer;
}
