#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool map[1010][1010];
struct Node{
	int x, y;
};
Node point[3][110];
int dirs[8][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };
int ma[8][2] = { 1, 2, 2, 1, -1, 2, 2, -1, -2, 1, 1, -2, -1, -2, -2, -1 };
bool mark[1010][1010];
int N, M, k1,k2,k3, x, y;

bool IN(int x, int y){
	return x >= 1 && x <= N&&y >= 1 && y <= M;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int CASE = 1;
	while (cin >> N >> M&&N*M){
		memset(map, 0, sizeof(map));
		memset(mark, 0, sizeof(mark));
		int ans = N*M;
		cin >> k1;
		for (int i = 0; i < k1; ++i){
			cin >> point[0][i].x >> point[0][i].y;
			mark[point[0][i].x][point[0][i].y] = 1;
			map[point[0][i].x][point[0][i].y] = 1;
			ans--;
		}
		cin >> k2;
		for (int i = 0; i < k2; ++i){
			cin >> point[1][i].x >> point[1][i].y;
			mark[point[1][i].x][point[1][i].y] = 1;
			map[point[1][i].x][point[1][i].y] = 1;
			ans--;
		}
		cin >> k3;
		for (int i = 0; i < k3; ++i){
			cin >> point[2][i].x >> point[2][i].y;
			mark[point[2][i].x][point[2][i].y] = 1;
			map[point[2][i].x][point[2][i].y] = 1;
			ans--;
		}
		for (int i = 0; i < k1;++i){
			x = point[0][i].x;
			y = point[0][i].y;
			if (!map[x][y]){
				map[x][y] = 1;
				ans--;
			}
			for (int i = 0; i < 8; ++i)
			for (int j = 1;; ++j){
				int nx, ny;
				nx = x + dirs[i][0] * j;
				ny = y + dirs[i][1] * j;
				if (!IN(nx, ny)||mark[nx][ny])
					break;
				if (!map[nx][ny]){
					map[nx][ny] = 1;
					ans--;
				}
			}
		}
		for (int i = 0; i < k2;++i){
			x = point[1][i].x;
			y = point[1][i].y;
			if (!map[x][y]){
				map[x][y] = 1;
				ans--;
			}
			for (int i = 0; i < 8; ++i){
				int nx, ny;
				nx = x + ma[i][0];
				ny = y + ma[i][1];
				if (IN(nx, ny)&&!map[nx][ny]){
					map[nx][ny] = 1;
					ans--;
				}
			}
		}

		printf("Board %d has %d safe squares.\n",CASE++,ans);
	}









	return 0;
}