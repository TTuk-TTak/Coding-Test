/* H-index 논문 인용횟수 문제
<유의점>
[0,1,3,5,6,7,7] 같은 경우 H-index 는4이므로,
정답이 반드시 vector에 포함된 값일 필요가 없다.

<제한사항>
vector 크기 : 1이상 1000 이하   →   2중 for문 까진 사용 가능! 

<기억사항>
sorting 후엔, {index} 가 곧 {n개 이상인 수의 개수} => 즉, 2중→1중 for문으로 바꿀 수 있음 *****
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// < 방법 1 >  - 1중 for문 
int solution(vector<int> citations) {
	// 1. 내림차순 정렬
	sort(citations.begin(), citations.end(), greater<int>());
	// 내림차순 (6,5,3,1,0)으로 정렬 됨 
	for (int i = 0; i < citations.size(); ++i) {
		// citations[i] : {7,7,6,5,3,1,0}
		// index(=개수) :  0,1,2,3,4,5,6
		// 역전 되는 순간 의 직전! 이 H-Index 최댓값 !!  *** 
		if (citations[i] < i + 1) {
			return i;	
		}
	}
	return citations.size();	// ***
}


// < 방법 2 >  - 2중 for문 
int solution(vector<int> citations) {
	int answer = 0;
	int size = citations.size() - 1;
	int cnt;
	// 1. 정렬
	sort(citations.begin(), citations.end());
	// 2. 최대값(가장 끝값) 기준으로 check 시작 
	answer = citations[size];
	while (1) {
		cnt = 0;
		// 3. 정렬한 모든 citations를 체크하며 
		for (int i = size; i >= 0; i--) {
			// 지정값 이상인 논문 count 
			if (citations[i] >= answer)
				cnt++;
			// 지정값 이상이 되면 바로 return 
			if (cnt >= answer)
				return answer;
		}
		answer--;	// *** 
	}
	return answer;
}


int main() {
	vector<int> citations = { 3,0,6,1,5 };
	cout << solution(citations);
	return 0;
}
