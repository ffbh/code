#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
double dp[110][110];
bool vis[110][110];
double map[110][110];
double dfs(int x, int y){
	if (vis[x][y])
		return map[x][y];
	vis[x][y] = 1;
	if (x == N || map[x][y]>0)
		return dp[x][y] = map[x][y];
	int nx, ny;
	nx = x + 1;
	ny = y;
	if (map[nx][ny] == -1)
		map[x][y] = 0.5*dfs(x, y - 1) + 0.5*dfs(x, y + 1);
	else map[x][y] = dfs(nx, ny);
	return map[x][y];
}





int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
	//	memset(dp, 0, sizeof(dp));
	//	memset(vis, 0, sizeof(vis));
	//	memset(map, 0, sizeof(map));
		for (int i = 0; i <= N;++i)
		for (int j = 0; j < M; ++j)
			map[i][j] = vis[i][j] = dp[i][j] = 0;
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j){
				if (s[j] == '.')
					map[i][j] = 0;
				else if (s[j] == '*')
					map[i][j] = -1;
				else
					map[i][j] = s[j] - '0';
			}
		}
		double mmax = 0;
		for (int i = 0; i < M; ++i){
			double t = dfs(0, i);
			if (t>mmax)
				mmax = t;
		}
		printf("%.6f\n", mmax);
	}





	return 0;
}