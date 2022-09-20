/* 값의 증감구간(기울기)을 파악하는 문제 _ 스택 ver
<유의점>
 1. [접근방식]
    스택에, 차례로 push하는데, 
    i) top보다 값이 떨어지면 => '넣을값'보다 작은 값 차례로 pop    => 버틴기간(바로끝남) = 넣을값index - 빠질값index
    ii)top보다 값이 오르면  => 그대로 스택에 push                => 버틴기간 = 전부 push 후, 마지막index(=size) - 해당index

<기억사항> ***
 1. 스택&큐 사용 시 coredump error는 거의, 
    empty인 상황에 .top()등의 접근합수를 사용해서가 원인임
 2. 스택&큐 사용 시, 웬만하면 push, pop의 동작은 제외하고
    각 원소의 값이 변경되는 상황은 만들지 않는게 좋음 => 스택&큐 원소값은 항상 고정*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;        // <val,idx>
    answer.resize(prices.size());
    
    st.push(make_pair(prices[0], 0));   // empty인 상황 만들지 않기 위해 초기값 미리 삽입 
    // 1. prices의 원소들을 차례로 넣기 전에 ... 
    for(int i=1; i<prices.size(); i++){
        // 2. 스택의 top값이, 넣으려는 값보다 크다면(가격하락) => answer에 기록 후 빼버림 pop
        while(!st.empty()){             // *** coredump 내지 않기 위해 항상 empty를 먼저 확인! 
            if(st.top().first > prices[i]){
                answer[st.top().second] = i - st.top().second;  // 넣으려는값까지의 차이 = 즉, 버틴 기간 계산 ***
                st.pop();
            }
            else 
                break;
        }
        // 3. 스택의 top값이, 넣으려는 값보다 작다면(상승세) => 큐에 push
        st.push(make_pair(prices[i],i));
    }
    
    // 4. 스택에 남은값들을 하나씩 빼며 {answer에 계산} 후 넣어줌
    while(!st.empty()){                 // answer 벡터에 이미 들어간 애들은, st스택에도 없으므로 신경 x ***
        answer[st.top().second] = prices.size() - st.top().second -1;   // answer[index]에, 기간 계산해 추가***
        st.pop();
    }
    return answer;
}
