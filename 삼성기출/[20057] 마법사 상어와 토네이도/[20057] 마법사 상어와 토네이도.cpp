#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
//#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

//ifstream fin("input.txt");
//ifstream fout("output.txt");

int N;
vector<vector<int>> A;

int direct[4][2] = { {0, -1},{1, 0},{0, 1},{-1,0}};
int direct_sand[4][9][3] = { {{-2,0,2},{-1,-1,10}, {-1,0,7}, {-1,1,1},{1,-1,10},{1,0,7},{1,1,1},{2,0,2},{0,-2,5}},
							{{0,-2,2},{-1,-1,1},{-1,1,1},{0,-1,7},{0,1,7},{1,-1,10},{1,1,10},{2,0,5},{0,2,2}},
							{{-2,0,2},{-1,-1,1},{-1,0,7},{-1,1,10},{1,-1,1},{1,0,7},{1,1,10},{2,0,2},{0,2,5}},
							{{-2,0,5},{-1,-1,10},{-1,1,10},{0,-1,7},{0,1,7},{1,-1,1},{1,1,1},{0,-2,2},{0,2,2}} };


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	// N 입력받기 
	cin >> N;
	A.resize(N, vector<int>(N,0));

	// 모래값 입력받기 
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cin >> A[j][i];
		}
	}

	int T = 0;	// testcase 
	int D = 0;	// direction
	int RS = 0;
	int OS = 0;
	int t, d;
	int flag = 0;
	int r = N/2;	// 시작 위치 
	int c = N/2;
	while (1) {
		// t = 해당 방향으로의 이동 횟수 
		t = (T + 1) / 2;
		// 그 이동 횟수 만큼 토네이도 이동 진행 
		for (int cnt = 0; cnt < t; cnt++) {
			// 모래 토네이도 이동하는 로직 시작 
			// cout << t << " " << cnt << " " << (D-1)%4 << " \n";
			// 토네이도 이동 
			d = (D - 1) % 4;
			r = r + direct[d][0];
			c = c + direct[d][1];

			// 모래 이동 
			int remain_sand;
			remain_sand = A[r][c];
			int sr, sc;
			// 전방향 모래 계산 
			for (int i = 0; i < 9; i++) {
				sr = r + direct_sand[d][i][0];
				sc = c + direct_sand[d][i][1];
				int sand = (A[r][c] * direct_sand[d][i][2]) / 100;
				if (sr < 0 || sc < 0 || sr >= N || sc >= N) {
					OS += sand;
				} else {
					A[sr][sc] += sand;
				}
				remain_sand -= sand; 
			}
			// a 구역 모래 계산 
			sr = r + direct[d][0];
			sc = c + direct[d][1];
			if (sr < 0 || sc < 0 || sr >= N || sc >= N) {
				OS += remain_sand;
			}
			else {
				A[sr][sc] += remain_sand;
			};
			A[r][c] = 0;

			/*
			cout << "\n\n";
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < N; i++) {
					cout << A[j][i] << " ";
				}
				cout << "\n";
			}*/

			// 도착 시 바로 break 
			if (r == 0 && c == 0) {
				flag = 1;
				break;
			}


		}
		// break 
		if (flag == 1)
			break;

		// 방향 및 횟수 전환
		D++;	// 방향
		T++;	// 횟수
	}

	cout << OS;

	//fin.close();
	//fout.close();

	return 0;
}
