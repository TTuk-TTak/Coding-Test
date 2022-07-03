#include<vector>
#include<algorithm>
//#include<fstream>
#include<cstring>
#include<iostream>

using namespace std;

//ifstream fin("input.txt");
//ofstream fout("output.txt");

int T, n;
char span, dir;
vector<pair<char, char>> input;
char U[10];	// 3*3 대신 10 으로 펴기 
char D[10];
char F[10];
char B[10];
char L[10];
char R[10];
char tmp[3];

// 해당 면 내의 index 돌리기	// UDFBLR 제외하고 모두 같은 logic *** 
void rotatespan(char span, char dir) {
	int tmp[10];
	if (span == 'U') {
		if (dir == '+') {
			tmp[1] = U[7];
			tmp[2] = U[4];
			tmp[3] = U[1];
			tmp[4] = U[8];
			tmp[5] = U[5];
			tmp[6] = U[2];
			tmp[7] = U[9];
			tmp[8] = U[6];
			tmp[9] = U[3];
		}
		else if (dir == '-') {
			tmp[1] = U[3];
			tmp[2] = U[6];
			tmp[3] = U[9];
			tmp[4] = U[2];
			tmp[5] = U[5];
			tmp[6] = U[8];
			tmp[7] = U[1];
			tmp[8] = U[4];
			tmp[9] = U[7];
		}
		copy(&tmp[0], &tmp[0] + 10, &U[0]);
	}
	else if (span == 'D') {
		if (dir == '+') {
			tmp[1] = D[7];
			tmp[2] = D[4];
			tmp[3] = D[1];
			tmp[4] = D[8];
			tmp[5] = D[5];
			tmp[6] = D[2];
			tmp[7] = D[9];
			tmp[8] = D[6];
			tmp[9] = D[3];
		}
		else if (dir == '-') {
			tmp[1] = D[3];
			tmp[2] = D[6];
			tmp[3] = D[9];
			tmp[4] = D[2];
			tmp[5] = D[5];
			tmp[6] = D[8];
			tmp[7] = D[1];
			tmp[8] = D[4];
			tmp[9] = D[7];
		}
		copy(&tmp[0], &tmp[0] + 10, &D[0]);
	}
	else if (span == 'F') {
		if (dir == '+') {
			tmp[1] = F[7];
			tmp[2] = F[4];
			tmp[3] = F[1];
			tmp[4] = F[8];
			tmp[5] = F[5];
			tmp[6] = F[2];
			tmp[7] = F[9];
			tmp[8] = F[6];
			tmp[9] = F[3];
		}
		else if (dir == '-') {
			tmp[1] = F[3];
			tmp[2] = F[6];
			tmp[3] = F[9];
			tmp[4] = F[2];
			tmp[5] = F[5];
			tmp[6] = F[8];
			tmp[7] = F[1];
			tmp[8] = F[4];
			tmp[9] = F[7];
		}
		copy(&tmp[0], &tmp[0] + 10, &F[0]);
	}
	else if (span == 'B') {
		if (dir == '+') {
			tmp[1] = B[7];
			tmp[2] = B[4];
			tmp[3] = B[1];
			tmp[4] = B[8];
			tmp[5] = B[5];
			tmp[6] = B[2];
			tmp[7] = B[9];
			tmp[8] = B[6];
			tmp[9] = B[3];
		}
		else if (dir == '-') {
			tmp[1] = B[3];
			tmp[2] = B[6];
			tmp[3] = B[9];
			tmp[4] = B[2];
			tmp[5] = B[5];
			tmp[6] = B[8];
			tmp[7] = B[1];
			tmp[8] = B[4];
			tmp[9] = B[7];
		}
		copy(&tmp[0], &tmp[0] + 10, &B[0]);
	}
	else if (span == 'L') {
		if (dir == '+') {
			tmp[1] = L[7];
			tmp[2] = L[4];
			tmp[3] = L[1];
			tmp[4] = L[8];
			tmp[5] = L[5];
			tmp[6] = L[2];
			tmp[7] = L[9];
			tmp[8] = L[6];
			tmp[9] = L[3];
		}
		else if (dir == '-') {
			tmp[1] = L[3];
			tmp[2] = L[6];
			tmp[3] = L[9];
			tmp[4] = L[2];
			tmp[5] = L[5];
			tmp[6] = L[8];
			tmp[7] = L[1];
			tmp[8] = L[4];
			tmp[9] = L[7];
		}
		copy(&tmp[0], &tmp[0] + 10, &L[0]);
	}
	else if (span == 'R') {
	if (dir == '+') {
		tmp[1] = R[7];
		tmp[2] = R[4];
		tmp[3] = R[1];
		tmp[4] = R[8];
		tmp[5] = R[5];
		tmp[6] = R[2];
		tmp[7] = R[9];
		tmp[8] = R[6];
		tmp[9] = R[3];
	}
	else if (dir == '-') {
		tmp[1] = R[3];
		tmp[2] = R[6];
		tmp[3] = R[9];
		tmp[4] = R[2];
		tmp[5] = R[5];
		tmp[6] = R[8];
		tmp[7] = R[1];
		tmp[8] = R[4];
		tmp[9] = R[7];
	}
	copy(&tmp[0], &tmp[0] + 10, &R[0]);
	}

}

// 해당 면 [주위 면] 4개의 일부 index 바꾸기	// index 변화 모두 다름 !!! 주의(빡구현) *** 
void rotate(char span, char dir) {
	// U 일 때 
	if (span == 'U') {
		if (dir == '+') {
			tmp[0] = R[1];
			tmp[1] = R[2];
			tmp[2] = R[3];

			R[1] = B[1];
			R[2] = B[2];
			R[3] = B[3];

			B[1] = L[1];
			B[2] = L[2];
			B[3] = L[3];

			L[1] = F[1];
			L[2] = F[2];
			L[3] = F[3];

			F[1] = tmp[0];
			F[2] = tmp[1];
			F[3] = tmp[2];
		}

		else if (dir == '-') {
			tmp[0] = L[1];
			tmp[1] = L[2];
			tmp[2] = L[3];

			L[1] = B[1];
			L[2] = B[2];
			L[3] = B[3];

			B[1] = R[1];
			B[2] = R[2];
			B[3] = R[3];

			R[1] = F[1];
			R[2] = F[2];
			R[3] = F[3];

			F[1] = tmp[0];
			F[2] = tmp[1];
			F[3] = tmp[2];
		}
	}
	else if (span == 'F') {
		if (dir == '+') {
			tmp[0] = U[7];
			tmp[1] = U[8];
			tmp[2] = U[9];

			U[7] = L[9];
			U[8] = L[6];
			U[9] = L[3];

			L[9] = D[3];
			L[6] = D[2];
			L[3] = D[1];

			D[3] = R[1];
			D[2] = R[4];
			D[1] = R[7];

			R[1] = tmp[0];
			R[4] = tmp[1];
			R[7] = tmp[2];
		}

		else if (dir == '-') {
			tmp[0] = U[7];
			tmp[1] = U[8];
			tmp[2] = U[9];

			U[7] = R[1];
			U[8] = R[4];
			U[9] = R[7];

			R[1] = D[3];
			R[4] = D[2];
			R[7] = D[1];

			D[3] = L[9];
			D[2] = L[6];
			D[1] = L[3];

			L[9] = tmp[0];
			L[6] = tmp[1];
			L[3] = tmp[2];
		}
	}
	else if (span == 'L') {
		if (dir == '+') {
			tmp[0] = U[1];
			tmp[1] = U[4];
			tmp[2] = U[7];

			U[1] = B[9];
			U[4] = B[6];
			U[7] = B[3];

			B[9] = D[1];
			B[6] = D[4];
			B[3] = D[7];

			D[1] = F[1];
			D[4] = F[4];
			D[7] = F[7];

			F[1] = tmp[0];
			F[4] = tmp[1];
			F[7] = tmp[2];
		}

		else if (dir == '-') {
			tmp[0] = U[1];
			tmp[1] = U[4];
			tmp[2] = U[7];

			U[1] = F[1];
			U[4] = F[4];
			U[7] = F[7];

			F[1] = D[1];
			F[4] = D[4];
			F[7] = D[7];

			D[1] = B[9];
			D[4] = B[6];
			D[7] = B[3];

			B[9] = tmp[0];
			B[6] = tmp[1];
			B[3] = tmp[2];
		}
	}
	else if (span == 'R') {
		if (dir == '+') {
			tmp[0] = U[3];
			tmp[1] = U[6];
			tmp[2] = U[9];

			U[3] = F[3];
			U[6] = F[6];
			U[9] = F[9];

			F[3] = D[3];
			F[6] = D[6];
			F[9] = D[9];

			D[3] = B[7];
			D[6] = B[4];
			D[9] = B[1];

			B[7] = tmp[0];
			B[4] = tmp[1];
			B[1] = tmp[2];
		}

		else if (dir == '-') {
			tmp[0] = U[3];
			tmp[1] = U[6];
			tmp[2] = U[9];

			U[3] = B[7];
			U[6] = B[4];
			U[9] = B[1];

			B[7] = D[3];
			B[4] = D[6];
			B[1] = D[9];

			D[3] = F[3];
			D[6] = F[6];
			D[9] = F[9];

			F[3] = tmp[0];
			F[6] = tmp[1];
			F[9] = tmp[2];
		}
	}
	else if (span == 'D') {
		if (dir == '+') {
			tmp[0] = F[7];
			tmp[1] = F[8];
			tmp[2] = F[9];

			F[7] = L[7];
			F[8] = L[8];
			F[9] = L[9];

			L[7] = B[7];
			L[8] = B[8];
			L[9] = B[9];

			B[7] = R[7];
			B[8] = R[8];
			B[9] = R[9];

			R[7] = tmp[0];
			R[8] = tmp[1];
			R[9] = tmp[2];
		}

		else if (dir == '-') {
			tmp[0] = F[7];
			tmp[1] = F[8];
			tmp[2] = F[9];

			F[7] = R[7];
			F[8] = R[8];
			F[9] = R[9];

			R[7] = B[7];
			R[8] = B[8];
			R[9] = B[9];

			B[7] = L[7];
			B[8] = L[8];
			B[9] = L[9];

			L[7] = tmp[0];
			L[8] = tmp[1];
			L[9] = tmp[2];
		}
	}
	else if (span == 'B') {
		if (dir == '+') {
			tmp[0] = U[1];
			tmp[1] = U[2];
			tmp[2] = U[3];

			U[1] = R[3];
			U[2] = R[6];
			U[3] = R[9];

			R[3] = D[9];
			R[6] = D[8];
			R[9] = D[7];

			D[9] = L[7];
			D[8] = L[4];
			D[7] = L[1];

			L[7] = tmp[0];
			L[4] = tmp[1];
			L[1] = tmp[2];
		}

		else if (dir == '-') {
			tmp[0] = U[1];
			tmp[1] = U[2];
			tmp[2] = U[3];

			U[1] = L[7];
			U[2] = L[4];
			U[3] = L[1];

			L[7] = D[9];
			L[4] = D[8];
			L[1] = D[7];

			D[9] = R[3];
			D[8] = R[6];
			D[7] = R[9];

			R[3] = tmp[0];
			R[6] = tmp[1];
			R[9] = tmp[2];
	}
	}
}



void init() {
	input.clear();
	// setting
	memset(U, 'w', sizeof(U));		// 주사위 SETTING 
	memset(D, 'y', sizeof(U));
	memset(F, 'r', sizeof(U));
	memset(B, 'o', sizeof(U));
	memset(L, 'g', sizeof(U));
	memset(R, 'b', sizeof(U));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 입력 
	cin >> T;
	for (int i = 0; i < T; i++) {
		// 초기화 
		init();
		// 입력받음 
		cin >> n;
		for (int i = 0; i < n; i++) {			// TC 입력받고 실행 , 다음 TC 입력받고 실행. ... 이런식으로 해도 됨 ! 
			cin >> span >> dir;
			input.push_back(make_pair(span, dir));	// 입력 받을 시, L - 사이에 띄어쓰기 없어도 잘 입력 받아짐 !! 
		}
		// 실행
		for (int i = 0; i < n; i++) {			
			rotate(input[i].first, input[i].second);
			rotatespan(input[i].first, input[i].second);
		}

		// 출력
		cout << U[1] << U[2] << U[3] << "\n";
		cout << U[4] << U[5] << U[6] << "\n";
		cout << U[7] << U[8] << U[9] << "\n";
	}

	//fin.close();
	//fout.close();
	return 0;
}
