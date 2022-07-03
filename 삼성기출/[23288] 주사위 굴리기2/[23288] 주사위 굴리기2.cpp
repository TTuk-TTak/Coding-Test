#include<vector>
#include<algorithm>
#include<iostream>
//#include<fstream>
#define MAX 21

using namespace std;

// for test file 
//ifstream fin("input.txt");
//ofstream fout("output.txt");

int N, M, K;
int Map[MAX][MAX];
int Dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };	// 동, 남, 서, 북 // 오, 아래, 왼, 위	// 시계, 반시계 방향 회전하므로 이에 순서 맞게 선언하면 편리 !! *** 
int Roll[7] = {0,1,2,3,4,5,6};		//주사위 전개도		// 아랫면 = 6
int Dr=0, Dc=0;		// 처음 주사위 위치 설정 
int dir = 0;	// 시작은 동쪽 

// simulation 용도 
vector<int> path[2];	// 가변 벡터를 2자리수로 가장 효율적으로 넣는 법은 ? 
vector<vector<int>> used;

// 주사위 이동 함수		// 처음 테스트 시, 시작 위치가 0 이라서 서쪽, 북쪽으로 옮기는 test는 방향 반대로 바뀌어서 나옴 !! ***
int move_dice() {
	// 주사위 이동
	int nr = Dr + Dir[dir][0];
	int nc = Dc + Dir[dir][1];
	if (nr < 0 || nc < 0 || nr >= N || nc >= M) {	// 범위 MAX define 해서 받았으므로, N,M 으로 잘 설정!! *** 
		// 갈 곳 없을 시 방향 정반대로 바꾼 후 
		// 동(0) <-> 서(2)
		// 남(1) <-> 북(3)
		if (dir == 0) dir = 2;
		else if (dir == 1) dir = 3;
		else if (dir == 2) dir = 0;
		else if (dir == 3) dir = 1;
		// 바뀐 방향으로 update
		nr = Dr + Dir[dir][0];
		nc = Dc + Dir[dir][1];
	}
	// 주사위 현위치 update
	Dr = nr;
	Dc = nc;

	// 전개도 회전 
	if (dir == 0) {			// 동 
		int tmp = Roll[1];
		Roll[1] = Roll[4];
		Roll[4] = Roll[6];
		Roll[6] = Roll[3];
		Roll[3] = tmp;
	}
	else if (dir == 1) {	// 남
		int tmp = Roll[2];
		Roll[2] = Roll[6];
		Roll[6] = Roll[5];
		Roll[5] = Roll[1];
		Roll[1] = tmp;
	}
	else if (dir == 2) {	// 서
		int tmp = Roll[3];
		Roll[3] = Roll[6];
		Roll[6] = Roll[4];
		Roll[4] = Roll[1];
		Roll[1] = tmp;
	}
	else if (dir == 3) {	// 북
		int tmp = Roll[6];
		Roll[6] = Roll[2];
		Roll[2] = Roll[1];
		Roll[1] = Roll[5];
		Roll[5] = tmp;
	}
	return 0;
}

// 다음 이동방향 정하는 함수 
void select_dir() {	
	int A = Roll[6];	// 아랫면 
	int B = Map[Dr][Dc];// 지도수
	if (A > B) dir++;		// 90도 시계방향
	else if (A < B) dir--;	// 90도 반시계방향
							// 그 외는 그대로 
	// 방향 범위 보정
	dir = (dir + 4) % 4;
}

// 방향탐색 simulation 
void simul_score(int r, int c) {	// simulation 시 주사위의 다음위치 
	// level
		// 안정해짐 개수가 정해진 것이 아니기 때문에 level없고, break 도 없음 !! **** 

	// branch
	for (int i = 0; i < 4; i++) {
		int nr = r + Dir[i][0];			// r,c 대신 Dr, Dc로 써서 오류남!! 계속 이어나가지지 않고 첫위치 기준으로 맴돔 ***
		int nc = c + Dir[i][1];
		if (nr < 0 || nc < 0 || nr>=N || nc>=M ||used[nr][nc]==1) // used 표시 해서 다시 방문 안하는 것이 중요! 
			continue;
		if (Map[nr][nc] != Map[Dr][Dc])	// 같은 숫자가 아니면 방문x
			continue;
		// 경로는 전부저장! (나가면서 삭제 X)
		path[0].push_back(nr);
		path[1].push_back(nc);
		used[nr][nc] = 1;
		simul_score(nr, nc);
		//used[nr][nc] = 0;		// 방문했던 배열 다시 돌며 중복되게 path체크하게 됨 
	}
}

int get_score() {
	int cnt = Map[Dr][Dc];	// 시작 위치는 simulation 시 path에 안적히므로, 현재 시작값도 더해줘야됨!!! ***
	for (int i = 0; i < path[0].size(); i++) {
		cnt += Map[path[0][i]][path[1][i]];
	}
	return cnt;
}



void init() {
	// setting
	path[0].clear();	// 한번에 가능???
	path[1].clear();
	used.clear();		
	used.resize(N, vector<int>(M, 0));	// *** 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int answer = 0;
	// 0. input 입력받기 
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	// 1. 실행 
	for (int i = 0; i < K; i++) {	
		init();
		move_dice();
		used[Dr][Dc] = 1;	// 시작위치 다시 방문할 수도 있으므로, used 표시 하고 들어가기!! *** 
		simul_score(Dr, Dc);
		answer += get_score();
		select_dir();		// simul_score 에서 방향 dir 사용하기 때문에, 모든 작업 끝나고 dir 변화시키기!! *** 
	}
	
	cout <<answer;


	// for test
	//fin.close();
	//fout.close();

	return 0;
}
