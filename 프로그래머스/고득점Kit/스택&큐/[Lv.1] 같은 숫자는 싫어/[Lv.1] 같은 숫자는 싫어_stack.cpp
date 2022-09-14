/* 벡터에서 연속중복값 삭제하는 문제 
<유의점>
 1. 스택, 큐 둘다 clear 함수를 지원하지 않음 ***
    while(~)과 pop()을 함께 사용해 하나씩 비워야 함 
 2. 스택, 큐 둘다 pop 함수의 return 값 없음. 삭제만 함
 3, 스택, 큐 둘다 push, pop 이 삽입,삭제 
    스택은 맨 윗값이 st.top()
    큐는 첫 값이 q.front()*/

#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for(auto elem: arr){
        // 1-1. 비어있을 시 push 
        if(st.empty())
            st.push(elem);
        // 1-2. 스택의 top값과 같을 시 일단 push
        else if(st.top() == elem)
            st.push(elem);
        // 1-3. 스택의 top값과 다를 시 
        else{
            // top값 answer에 넣고 
            answer.push_back(st.top());
            // 스택 비운 후
            while(!st.empty())
                st.pop();
            // 다시 스택에 값 넣기 
            st.push(elem);
        } 
    }
    // 2. 잔여 stack 비우기 
    if(!st.empty())
        answer.push_back(st.top());
    
    return answer;
}
