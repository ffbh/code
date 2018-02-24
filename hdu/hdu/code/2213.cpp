#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M, T;
bool map[110][110];
_int64 dp[22][110][110];
int sx, sy, ex, ey;
int dirs[5][2] = { 1, 0, 0, 1, 0, -1, -1, 0,0,0 };
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M&&!map[x][y];
}
int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> T){
		for (int i = 0; i < N; ++i){
			string temp;
			cin >> temp;
			for (int j = 0; j < M;++j)
			if (temp[j] == 'X')
				map[i][j] = 1;
			else if (temp[j] == '.')
				map[i][j] = 0;
			else if (temp[j] == 'S'){
				sx = i;
				sy = j;
				map[i][j] = 0;
			}
			else{
				ex = i;
				ey = j;
				map[i][j] = 0;
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][sx][sy] = 1;
		for (int k = 0; k < T;++k)
		for (int x = 0; x < N;++x)
		for (int y = 0; y < M; ++y)
		if(dp[k][x][y]){
			int tx, ty;
			for (int i = 0; i < 5; ++i){
				tx = x + dirs[i][0];
				ty = y + dirs[i][1];
				if (IN(tx, ty))
					dp[k + 1][tx][ty] += dp[k][x][y];
			}
		}
		int t;
		if (dp[T - 1][ex][ey] >0)
			cout << dp[T - 1][ex][ey] << endl;
		else if (dp[T][ex][ey])
			cout << "Oh, my god, bad luck!" << endl;
		else
			cout << "God will bless XX and WisKey!" << endl;
	}
	return 0;
}