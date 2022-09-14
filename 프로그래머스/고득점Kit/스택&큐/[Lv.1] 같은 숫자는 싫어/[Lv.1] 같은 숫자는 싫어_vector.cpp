/* 벡터에서 연속중복값 삭제하는 문제 
<유의점>
 1. 벡터는 stack과 비슷한 구조지만, [중간에 값 삽입&삭제], [원소참조]가 가능하다. 
 2. 벡터 마지막값 접근***
    vector.back()   O
    vector[-1]      X 이거안됨
 3, 벡터 함수
    v.front()   : 첫번째 원소
    v.back()    : 마지막 원소
    v.begin()   : 첫번째원소를 가리키는 iterator
    v.end()     : 마지막 원소의 '다음'을 가리키는 iterator
    
    v.push_back(x)  : 마지막 원소에 x값 삽입
    v.pop_back(x)   : 마지막 원소 제거
    v.insert(n,x)   : n번째 위치에 x값 삽입
    v.erase(iter)   : iterator가 가리키는 원소 삭제*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++){
        // 이미 들어가있는 정답벡터의 마지막값과 같다면, 안넣고 pass
        if(!answer.empty() && (answer.back()==arr[i])    // answer[-1]으로 벡터 마지막값 접근안됨.(0출력됨) => answer.back()사용하기
            continue;
        // 그 외 모두 push 
        answer.push_back(arr[i]);
    }
    
    return answer;
}
