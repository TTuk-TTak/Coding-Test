#include <vector>
#include <algorithm>
#include <iostream>
//#include <fstream>			// txt 출력을 위함 
#define MAX 5				// 최대 크기 +1 지정해서 사용  ***

using namespace std;

int S, M;
int Sx, Sy;
vector<int> fish[MAX][MAX];
vector<int> new_fish[MAX][MAX];
int smell[MAX][MAX];

int fish_dir[8][2] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int shark_dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

// Move Shark 용 변수들 
int path[3][2];
int path_save[3][2];
int maxkill = -1;	// 최대값 할시 -1 설정 유용ㅇ! 

// Test 입력 
//ifstream fin("input.txt");		// 파일 입력 객체 생성
//ofstream fout("output.txt");	// 파일 출력 객체 생성

// 물고기 이동 함수 
int move_fish() {
	int dir;
	int nx, ny;
	// 그냥 3중 for문으로 물고기 전부 탐색  (사실 4중임)
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			for (int k = 0; k < fish[i][j].size(); k++) {	// size없는 곳은 아예 들어가지도 않음
				int dgr = 0;
				while (dgr < 9) {	// 방향 8가지 지만, 한바퀴 돌아도 그대로인 경우위해 하나 더 여유로 +1 추가 ! ***
					// 방향 한바퀴 다돌아도 갈 곳 없을시 그대로 입력 *** 
					if (dgr == 8) {	
						new_fish[i][j].push_back(fish[i][j][k]);	// 방향 그대로인 물고기도 new_fish 에 넣어줘야함 *** 
					}
					// 방향 회전 
					dir = fish[i][j][k] - dgr;
					if (dir < 0)									// 방향이 -인 경우도 고려 *** 
						dir += 8;
					// 위치 이동 
					nx = i + fish_dir[dir][0];
					ny = j + fish_dir[dir][1];
					if (nx < 0 || ny < 0 || nx >= MAX - 1 || ny >= MAX - 1 || (Sx == nx && Sy == ny) || smell[nx][ny]>0 ) {	// +냄새&상어 도 피함
						dgr++;
						continue;
					}
					// 갈 곳이 있을 때, 물고기 [위치/방향] 변경
					new_fish[nx][ny].push_back(dir);
					break;		// whlie문에 필수 !! ***
				}
			}
		}
	}
	return 0;
}

// 조건함수 따로 빼기! 
int count_fish() {
	vector<int> test_fish[MAX][MAX];	// 지나간 부분은 물고기 없애고 count 해야 하기 때문에 test_fish에 복사해서 따로 쓰기 !! ***
	copy(&new_fish[0][0], &new_fish[0][0] + 25, &test_fish[0][0]);
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		// 상어가 지나온 물고기 모두 count 
		cnt += test_fish[path[i][0]][path[i][1]].size();
		test_fish[path[i][0]][path[i][1]].clear();	// 지나온 길 물고기 삭제 ***
	}
	return cnt;
}

// 백트래킹 상어이동 함수 [BackTracking + Direct]
void move_shark(int level, int sx, int sy) {	// 상어의 현재 위치 받기 
	// level =3 
	if (level == 3) {
		int cnt = count_fish();			// 백트래킹 & 조건함수(count_fish) 구분  *** 
		if (cnt > maxkill) {			// 물고기 최대값을 얻는 경로로 저장(path_save)
			maxkill = cnt;
			copy(&path[0][0], &path[0][0] + 6, &path_save[0][0]);	// copy 함수 활용해 배열 복사 *** 
		}
		return;
	}
	// branch = 4
	for (int i = 0; i < 4; i++) {
		int nx = sx + shark_dir[i][0];
		int ny = sy + shark_dir[i][1];
		if (nx < 0 || ny < 0 || nx >= MAX - 1 || ny >= MAX - 1) {   // used 쓰지 말기! 상어는 '지나간 곳 또지나갈 수 있음!' 단, 이미 죽인 물고기는 세면 안됨!! ***
			continue;
		}
		// 상어 경로 정리 
		path[level][0] = nx;
		path[level][1] = ny;

		move_shark(level+1, nx, ny);
	}
}

void setting() {
	// 상어가 지나간 자리 물고기 제거
	for (int i = 0; i < 3; i++) {
		// 물고기 있던 곳만 피 남기기						// if 조건문 없이 지나간 자리 전부 '냄새' 남기면 오류 *** 		
		if(new_fish[path_save[i][0]][path_save[i][1]].size() > 0)
			smell[path_save[i][0]][path_save[i][1]] = 3;	// 바로 2로 두면, 아래 '냄새흐리기' 파트에서 -1 되므로, 하나 높여 3으로 설정 *** 
		new_fish[path_save[i][0]][path_save[i][1]].clear();
	}
	// 물고기 복제 
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			// 냄새 흐리기									// [위치주의] init에 들어가있으면 안되고, 물고기 복제 후 바로 실행해야함 *** 
			if (smell[i][j] > 0)
				smell[i][j]--;
			// 기존 물고기를 복제해넣기 
			fish[i][j].insert(fish[i][j].end(), new_fish[i][j].begin(), new_fish[i][j].end());
		}
	}
	// 상어 위치 update
	Sx = path_save[2][0];
	Sy = path_save[2][1];
}

void init() {
	// 전역변수 초기화 
	maxkill = -1;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			// new_fish 초기화
			new_fish[i][j].clear();
		}
	}
}



int main() {
	// 실행속도 up 
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 0. input 입력							// fx, fy, fd, Sx, Sy input 전부 -1 감소시켜 받기  ***
	int answer = 0;
	int fx, fy, fd;
	cin >> M >> S;	// M: 물고기, S: 실행수 
	for (int i = 0; i < M; i++) {	
		cin >> fx >> fy >> fd;
		fish[fx - 1][fy - 1].push_back(fd-1);
	}
	cin >> Sx >> Sy;
	Sx--;
	Sy--;				

	// 1. 실행
	for (int i = 0; i < S; i++) {	
		// 함수 차례로 실행
		init();					// 변수 초기화 
		move_fish();			// 물고기 이동 
		move_shark(0, Sx, Sy);	// 상어이동 
		setting();				// 물고기 복제 & 변수 update
	}


	// 2. 답 계산
	for (int i = 0; i < MAX - 1; i++) {			// MAX -1 만큼으로 계산하기!! ***
		for (int j = 0; j < MAX - 1; j++) {
			// 물고기 수 count 
			answer += fish[i][j].size();
		}
	}
	cout << answer;


	//fin.close();
	//fout.close();	

	return 0;
}
