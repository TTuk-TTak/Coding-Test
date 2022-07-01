/* H-index 논문 인용횟수 문제 
<유의점>
[0,1,3,5,6,7,7] 같은 경우 H-index 는4이므로,
정답이 반드시 vector에 포함된 값일 필요가 없다. 

<제한사항>
vector 크기 : 1이상 1000 이하   →   2중 for문 까진 사용 가능! 
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int size = citations.size() - 1;
	int cnt;
	// 1. 우선 정렬
	sort(citations.begin(), citations.end());
	// 2. 최대값(가장 끝값) 기준으로 check 시작 
	answer = citations[size];
	while (1) {
		cnt = 0;
		// 3. 정렬한 모든 citations를 체크하며 
		for (int i=size; i >= 0; i--) {
			// 지정값 이상인 논문 count 
			if (citations[i] >= answer)
				cnt++;
			// 지정값 이상이 되면 바로 return 
			if (cnt >= answer)
				return answer;
		}
		answer--;		// *** 
	}
	return answer;
}

int main() {
	vector<int> citations = { 3,0,6,1,5 };
	cout << solution(citations);
	return 0;
}
