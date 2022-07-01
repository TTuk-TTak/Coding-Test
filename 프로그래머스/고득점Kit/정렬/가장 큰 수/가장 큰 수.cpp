/* 
<유의점>
* sort의 커스터마이징 compare 함수를 적용 / greater / less함수 구분! 
* 단순 sort 가 아닌 가장 큰 자릿수의 숫자기준으로 sort 해야함
* 3과 30 구분해야 함 !! 

<기억사항>
 문자열도 ASCII 기반이기 때문에 sort 적용 가능
 string 에서 한글은 2자리, 숫자는 1자리, 특수문자 1자리, 대소문자1자리 차지
 string 중 한 자리는 '==' 으로 비교 가능

<issue>
? 2차원 vector 로 구성하면, 가장 처음 원소를 기준으로 sort 가능   ?? 자릿수가 모두 달라도 가능 ??
? string에서 tmp[tmp.size() - 1]  vs tmp.end()  의 차이 ????

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool comp(string i, string j) {	// 비교하는 값과 type 일치! 
	// greater(내림차순) : return i > j
	// less(오름차순) : return j > i

	// <시간초과 나는 풀이> - 0이 없어질 때까지 while문으로 erase 후 비교 (X)

	return j + i < i + j;		//  ex) 300, 3일 경우   3003, 3300 중 뭐가 더 큰지 비교  *****
}


string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;

	// 1. int → string으로 바꿔 vector에 저장 
	for (auto it = numbers.begin(); it != numbers.end(); it++) {		// for (int i : numbers) 로 대체 가능 
		tmp.push_back(to_string(*it));
	} 

	// 2. 큰 숫자부터 정렬 (기본 : 내림차순 - greater)    ** 단, comp 함수 커스터마이징! 
	sort(tmp.begin(), tmp.end(), comp);		// 기본) 오름차순 : less<>(), 내림차순 : greater<>() 함수 사용 / 사용자정의함수 comp로 대체   
											// 사용되는 함수명 or변수명이 애매하면(stl과 겹치면) 가끔 sort의 의미가 모호합니다 error *** 

	// 3. 문자열 이어붙이기 
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		answer += *it;
	}

	// [예외처리] TC 11번 걸림  ***
	if (answer[0] == '0')	// 모든 숫자가 0 일 때 ex) 00000 → 0  
		answer = "0";
	
	return answer;
}



int main() {
	vector<int> numbers = { 3,34,30,5,9 };
	cout << solution(numbers);
	return 0;
}
