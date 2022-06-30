/* 
1. 배열복사 / 벡터복사 / 1차원복사 / 2차원복사 모두 다름   //copy(&array[0]+commands[i][0], &array[0]+commands[i][1],&sub[0]);랑 다름
2. 벡터 copy는 깊은복사(deep copy)   =>  '='으로 간단히, clear-resize-copy과정을 대체할 수 있음 
3. STL sort로 필요부분만 정렬 가능 */


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> temp;
	int size = commands.size();
	int fst, lst;
	for (int i = 0; i < size; i++) {
		// < 방법 1 >

		// 1. 각 정해진 크기만큼 배열 잘라 복사 
		temp.clear();
		fst = commands[i][0] - 1; 
		lst = commands[i][1] - 1; 
		temp.resize(lst - fst +1);	// 이 과정 꼭필요!! 
		copy(array.begin()+fst, array.begin()+lst + 1, temp.begin());	

		// 2. 각 배열 정렬 
		sort(temp.begin(),temp.end());

		// 3. n번째 원소선택
		answer.push_back(temp[commands[i][2]-1]);


		// < 방법 2 >   ↓ 다음과 같은 세줄로 요약 가능 
		temp = array;																// 1. [벡터복사]로 clear, resize, copy 과정 생략 가능   ***
		sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);		// 2. 필요한 부분만 정렬 
		answer.push_back(temp[commands[i][0] + commands[i][2] - 2]);

	}
	return answer;
}




int main() {
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
	vector<int> answer;
	answer = solution(array, commands);
	for (auto it = answer.begin(); it != answer.end(); it++) {
		cout << *it;
	}
	return 0;
}
