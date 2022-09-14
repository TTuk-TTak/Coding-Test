/* Queue 사용문제
<기억사항>
int타입의 나누기(/)는, 몫이 2.xx의 경우 자동 [내림]	   → q = x /y
즉, '걸리는 시간'등 [올림] 하고 싶은 경우			   → q = (x+y-1) /y   =  x/y + 1 -1/y	 *****  
queue가 비었을 경우, [front]함수의 반환값이 정의되지 않음 -> error 발생 */

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	int size = progresses.size();
	int works;
	for (int i = 0; i < size; i++) {
		// 1. 각 작업시간 계산 
		works = (100 - progresses[i]) / speeds[i] + 1 - 1 / (speeds[i]);
		//works = (100 - progresses[i]) / speeds[i];	// → 자동내림되어 잔여작업일 반영안됨 

		// 2-1. 비어있을 시 push
		if (q.empty()) 
			q.push(works);
		// 2-2. 새로 들어갈 작업시간이 앞의 작업시간보다 클 시, 앞 작업들 한꺼번에 배포  
		else if (works > q.front()) {
			// 배포될 기능 개수 count 
			answer.push_back(q.size());
			// queue 초기화 
			while (!q.empty())
				q.pop();
			q.push(works);
		}
		// 2-3. 그 외(앞 작업보다 작업시간 작음), 일단 push
		else 
			q.push(works);
	}
	// 3. 마지막 잔여 queue 반영  
	if(!q.empty())
		answer.push_back(q.size());
	return answer;
}

int main() {
	vector<int> progresses, speeds, answer;
	progresses = { 95,90,99,99,80,99 };
	speeds = { 1,1,1,1,1,1 };
	answer = solution(progresses, speeds);	// 벡터복사 
	for (auto it = answer.begin(); it != answer.end(); it++) {
		cout << *it;
	}
	return 0;
}
