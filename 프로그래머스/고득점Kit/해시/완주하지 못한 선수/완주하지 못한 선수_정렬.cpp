/*
정렬방식 : 전체 선수 중, 완주하지 못한 선수가 단 1명 뿐이라 가능한 풀이 
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i])
			return participant[i];
	}

	return participant[participant.size() - 1];
}

int main() {
	vector<string> participant{ "leo", "kiki", "eden" };
	vector<string> completion{"eden","leo"};
	solution(participant, completion);
	return 0;
}
