#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int N, M;
int link[50][50];
int seg[50][50];
int num;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}
bool Isok(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M;++j)
	if (seg[i][j] >= 0){
		int tx, ty;
		int num = 0;
		for (int k = 0; k < 4; ++k){
			tx = i + dirs[k][0];
			ty = j + dirs[k][1];
			if (link[tx][ty])
				num++;
		}
		if (num != seg[i][j])
			return 0;
	}
	return 1;
}


bool Isconnect(){
	int sx, sy;
	bool flag = 1;
	for (int i = 0; i < N&&flag; ++i)
	for (int j = 0; j < M&&flag; ++j)
	if (link[i][j]){
		sx = i;
		sy = j;
		flag = 0;
	}
	if (flag)
		return 0;
	int tx, ty, nx, ny;
	tx = sx;
	ty = sy;
	int num = -1;
	while (num){
		link[tx][ty] = 0;
		num = 0;
		for (int i = 0; i < 4; ++i){
			int gx, gy;
			gx = tx + dirs[i][0];
			gy = ty + dirs[i][1];
			if (IN(gx,gy)&&link[gx][gy]){
				num++;
				nx = gx;
				ny = gy;
			}
		}
		if (num == 2){
			if (!(tx == sx&&ty == sy))
				return 0;
		}
		else if (num == 3)
			return 0;
		tx = nx;
		ty = ny;
	}
	return (abs(tx - sx) + abs(ty - sy))==1;
}

bool nohasleft(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M;++j)
	if (link[i][j])
		return 0;
	return 1;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(link, 0, sizeof(link));
		memset(seg, -1, sizeof(seg));
		cin >> N >> M;
		N = 2 * N + 1;
		M = 2 * M + 1;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j){
				if (i % 2 == 0){
					if (j % 2){
						if (s[j] == '-')
							link[i][j] = link[i][j - 1] = link[i][j + 1] = 1;
					}
				}
				else{
					if (j % 2 == 0){
						if (s[j] == '|')
							link[i][j] = link[i - 1][j] = link[i + 1][j] = 1;
					}
					else{
						if (s[j] == '?')
							seg[i][j] = -1;
						else
							seg[i][j] = s[j] - '0';
					}
				}
			}
		}
		if (Isok() && Isconnect()&&nohasleft())
			cout << "VALID" << endl;
		else
			cout << "INVALID" << endl;
	}
	return 0;
}