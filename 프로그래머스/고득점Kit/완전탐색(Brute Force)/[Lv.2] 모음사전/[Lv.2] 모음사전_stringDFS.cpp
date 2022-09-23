/* string DFS - 사전순서 찾기 문제
<기억사항>
 1. case는 예약어임          ***
 2. string DFS는 string에 한글자씩 추가해가며 찾음
 3. DFS case가 몇번째인지 셀 때는 -> 전역변수로 세는게 젤 나음 ***          */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string words = "AEIOU";
int answer =0;                       
int cnt =0;

void recur(string str, string word){ 
    if(str == word)                     // ***
        answer = cnt;
    cnt++;                              // 사전식으로 몇번째인지 count
    // level
    if(str.length() >= 5)               // 5글자 제한   ***
        return;
    // branch
    for(int i=0; i<words.length(); i++){
        recur(str + words[i], word);    // (단어하나씩 추가, 찾는 string고정)
    }
}

int solution(string word) {
    recur("", word);                    // (시작string, 찾는 string)
    
    return answer;
}
