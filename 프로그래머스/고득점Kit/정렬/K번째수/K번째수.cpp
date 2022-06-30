#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int size = commands.size();
	vector<int> sub;
	int fst, lst;
	for (int i = 0; i < size; i++) {
		// 1. 각 정해진 크기만큼 배열 잘라 복사 
		sub.clear();
		fst = commands[i][0] - 1; 
		lst = commands[i][1] - 1; 
		sub.resize(lst - fst +1);	// 이 과정 꼭필요!! 
		copy(array.begin()+fst, array.begin()+lst + 1, sub.begin());		// 배열복사, 벡터복사, 각각 1차원,2차원 복사가 다름   //copy(&array[0]+commands[i][0], &array[0]+commands[i][1],&sub[0]);랑 다름
		// 2. 각 배열 정렬 
		sort(sub.begin(),sub.end());
		/*
		for (auto itt = sub.begin(); itt != sub.end(); itt++) {
			cout << *itt;
		}
		cout << "\n";*/
		// 3. n번째 원소선택
		answer.push_back(sub[commands[i][2]-1]);

	}
	//answer.push_back(2);
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
