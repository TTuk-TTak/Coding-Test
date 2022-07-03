#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
//#include<fstream>
#define MAX 51

using namespace std;

//for test
//ifstream fin("input.txt");
//ofstream fout("output.txt");

int N, M;
int Map[MAX][MAX];
int Cloud[MAX][MAX];
int newCloud[MAX][MAX] = {0};
vector<int> Plan[2];	// 구름이 움직일 계획 ds 저장 
int direct[8][2] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int diag_direct[4][2] = { {-1,-1},{-1,1},{1,1},{1,-1} };




void move_cloud(int n) {	// n : 몇번째 움직임 인지 알기 위함 
	memset(newCloud, 0, sizeof(newCloud));	// newCloud 초기화 *** 
	int dir = Plan[0][n];	// 방향
	int recur = Plan[1][n];	// 횟수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Cloud[i][j] == 1) {
				int nr = i + recur * direct[dir][0];
				int nc = j + recur * direct[dir][1];
				nr = (nr + N*100) % N;		// 나머지 계산에 오류 나올 수 있으므로 *100 최대 횟수로 해준 후 나누기 !! *** 
				nc = (nc + N*100) % N;
				newCloud[nr][nc] = 1;
				// 비내림 
				Map[nr][nc] += 1;
			}
			
		}
	}
}

int check(int r, int c) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + diag_direct[i][0];
		int nc = c + diag_direct[i][1];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)
			continue;
		if (Map[nr][nc] > 0)
			cnt++;
	}
	return cnt;
}

void copy_water() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (newCloud[i][j] == 1) {
				Map[i][j] += check(i,j);
			}
		}
	}
}

void create_cloud() {
	memset(Cloud, 0, sizeof(Cloud));	// 배열 초기화 하는법 !! **** memset 이 for문 보다 빠름 !  *** 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 구름이 없었고, 물이 2 이상인 곳 
			if (newCloud[i][j] == 0 && Map[i][j] >= 2) {
				Cloud[i][j] = 1;
				Map[i][j] -= 2;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	// 0. input 받기 
	int answer = 0;
	int d, s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		d--;			// 방향만 값 보정!! *** 
		Plan[0].push_back(d);
		Plan[1].push_back(s);
	}

	// 1. setting		// index 하나씩 더 빼는거 주의!! 
	Cloud[N - 1][0] = 1;		// 버퍼 오버런 발생 ?????????? 
	Cloud[N - 1][1] = 1;
	Cloud[N - 2][0] = 1;
	Cloud[N - 2][1] = 1;


	// 2. 실행 
	for (int i = 0; i < M; i++) {
		//play
		move_cloud(i);	// newCloud 초기화 시점		// 0 이 아닌 i넣어줘야 옳게 풀림! *** 
		copy_water();
		create_cloud();	// Cloud 초기화 시점 
	}

	// 3. 정답 계산 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += Map[i][j];
		}
	}
	cout << answer;

	//for test
	//fin.close();
	//fout.close();

	return 0;
}
