/*
<유의점>
  문제가 뭐라는지 모르겠으니 이해하지 말고 하라는 대로 풀기 
  
<기억사항>
  return 타입이 void 가 아닌 '재귀'인 경우 ***
  => 모든 경우의 수에 대해 return 이 있으면 됨 (재귀함수 라도)
  => +로 그저 string 이어서 재귀 사용 가능 

<주의점>
  (x) st.push[i] : non-static member function 에러
  (o) st.push(i) 로 해야지 에러 안뜸 
*/

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<char> st;
string P;

// "균형잡힌 괄호 문자열" 확인 : 각 괄호의 짝이 맞는 경우의 인덱스 반환 (최소 u 분리)
int checkBalanced(string str){
    int cnt =0;
    for(int i=0; i<str.length(); i++){
        if(str[i] =='(')
            cnt++;
        else
            cnt--;
        if(cnt ==0)
            return i;
    }
    return -1;  
}

// "올바른 괄호 문자열" 확인 : 짝 맞는 올바른 괄호인지 확인
bool checkRight(string str){
    stack<char> st;
    
    for(char i: str){
        if(st.empty()){
            if(i==')')
                return false;
            st.push(i);
        } else if(st.top() != i){
            st.pop();
        } else{
            st.push(i);
        }  
    }
    return true;
}

// 모든 괄호의 방향을 바꿔주는 함수
string reverse(string str){
    string ret="";
    for(auto i:str){
        if(i=='(')
            ret+=")";
        else
            ret+="(";
    }
    return ret;
}

// 재귀 (return 타입이 string)
string recur(string A, string w){
    if(w=="")
        return A;
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u,v 로 분리
    int idx = checkBalanced(w);
    string u = w.substr(0, idx+1);
    string v = w.substr(idx+1, w.length()-idx);
    // 3. 문자열 u가 "올바른 괄호 문자열"이라면 문자열 v에 대해 1단계부터 다시 수행
    if(checkRight(u)){
        // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환
        return recur(A+u, v);
    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정 수행
    } else {
        // 4-1,2,3. "(", "v에대해1단계부터재귀적으로수행한결과", ")"를 이어붙임
        string vtemp = "("+ recur("", v) + ")";
        // 4-4. u의 첫번째와 마지막 문자 제거 후, 나머지 문자열의 괄호 방향 뒤집어서 붙임
        string utemp = reverse(u.substr(1, u.length()-2));
        // 4-5. 생성된 문자열을 반환
        return recur(A+vtemp+utemp, "");
    }
}

string solution(string p) {
    P = p;
    // 1. 빈 문자열인 경우 빈 문자열 반환
    if(p=="")
        return "";
    // 재귀 시작
    return recur("", P);
}
