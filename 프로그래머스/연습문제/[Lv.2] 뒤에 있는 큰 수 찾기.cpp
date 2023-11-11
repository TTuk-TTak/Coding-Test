/* [STACK]
 - 나보다 앞서있는 것중 가장 가까운 것 찾기 문제 
 - 입력 길이(1,000,000) => O(N) ~ O(N^2) 내에서 해결해야함 
    - 2중 for문으로 하면 => 시간초과(TC 20~23)
    - 1중 for문으로 해결해야함 (스택활용)
 - stack) 
    - empty()랑 top(), 조건문에 &&으로 함께 사용해도 ok (=> top못찾음으로 인한 core dump오류 안남)
 
 - * push_front 는 없음*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    answer.resize(numbers.size());
    // input 의 뒤쪽 원소부터 탐색 
    int i = numbers.size()-1;
    while(i>=0){
        // 1) 비었을 경우 => -1표시 / stack에 넣기 
        if(st.empty()){
            answer[i] = -1;
            st.push(numbers[i]);
            i--;
        }
        // 2) top이 자신보다 클 경우 (뒷큰수 O) => 정답표시 / stack에 넣기
        else if(st.top() > numbers[i]){
            answer[i] = st.top();
            st.push(numbers[i]);
            i--;
        }
        // 3) top이 자신보다 작을 경우 (뒷큰수 X) => 일단 탐색목록(stack)에서 pop해버리고 다시 탐색 
        else{
            st.pop();
        }
    }
    
    return answer;
}
