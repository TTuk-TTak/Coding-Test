/* 전화번호끼리 (앞머리로)겹치는게 있는지 확인
<유의점>
 1. 번호끼리 단순 포함되는게 아닌, (.find != -1  X)
    번호의 시작(접두어)인지 확인 (.find == 0 인지 확인 O)   *** 
 2. 중복되는 번호는 안나오므로, 같은 자릿수는 비교해볼 필요도 없음 
 3. '사전식'으로 sort 시, 바로 '앞뒤' 번호만 비교(1중 for문)하면 됨 ***
 4. try1) 자릿수대로 정렬 != 사전식으로 정렬
    자릿수 대로 정렬 => 2중 for문으로 비교하려 했으나, '접두어'가 아닌 '포함'찾는줄 알고 잘못접근한 방법
    '포함'접근 시, '123456788' 과 '88'비교 시 edge case 됨 
 
<제한사항> 
 1. 2중 for문 사용시 => 효율성테스트3 시간초과 
 
<기억사항>
 1. substr < find가 빠르다 함.  (???)  
 2. sort의 compare 함수는 항상 int 값 반환 ***
    1 return 시 => A가 B보다 우선
    0 return 시 => B가 A보다 우선
    ex)
    int compare(string A, string B){    
        if(A.size() < B.size())
            return 1;         
        return 0;
    }*/

#include <string>
#include <vector>
#include <algorithm>    // 정렬 sort 사용 시 필요한 헤더 

using namespace std;



bool solution(vector<string> phone_book) {
    // 1. 정렬 
    sort(phone_book.begin(),phone_book.end());   // 사전순 정렬
    
    // 2. 바로 뒤 원소와 비교 
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i+1].find(phone_book[i]) == 0)    // 접두어 일 경우, 반환
            return false;
    }
        
    return true;
}
