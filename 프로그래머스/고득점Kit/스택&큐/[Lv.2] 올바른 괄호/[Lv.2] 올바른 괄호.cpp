/* Stack 괄호문제 
<기억사항>
 괄호를 stack에 넣어, 짝지어지면 -> pop 하는 방식 
<유의점>
 1. string도 vector처럼 'size()함수' & '원소참조' 가능함
    string[idx]로 한 원소참조 시 => char 타입됨 (작은따옴표' ' 사용)
 2. 스택이 비었을 때, top() 호출하면 error가 발생 ***
    즉, 스택&큐 사용 시에는 항상 if문으로 empty여부를 먼저 확인해야 함*/

#include <string>
#include <stack>

using namespace std;

bool solution(string s){
    stack<char> st;     // string(X), char(O)로 하나씩 저장 ***
    
    // 1. 괄호를 하나씩 stack에 넣으며,
    for(int i=0; i<s.size(); i++){ 
        // 1-1. 처음부터 ')'가 나오면 -> 무조건 잘못된괄호
        if(st.empty() && s[i]==')')
            return false;
        // 1-2. 그외 빈상태 -> push          // stack이 비었을 시, top()반환값 =error, 즉, 반드시 empty시 if문 필요 *** 
        else if(st.empty())
            st.push(s[i]);
        // 1-3. 괄호 짝이 지어질 시 -> 짝지어서 pop으로 뺌 
        else if(st.top()=='(' && s[i]==')')
            st.pop();
        // 1-4. 그외 push
        else
            st.push(s[i]);
    }
    // 2. stack이 비지 않고 남아있다 = 괄호가 짝지어지지 않았다
    if(!st.empty())
        return false;
    
    return true;
}
