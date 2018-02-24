#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int data[110][110];
int dp[110][110];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0,  0, -1 };
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}
int DFS(int x, int y){
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; ++i){
		int nx, ny;
		nx = x + dirs[i][0];
		ny = y + dirs[i][1];
		if (IN(nx, ny)&&data[x][y]<data[nx][ny]){
			int tmp = DFS(nx, ny);
			if (tmp + 1>dp[x][y])
				dp[x][y] = tmp + 1;
		}
	}
	return dp[x][y];
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j)
			cin >> data[i][j];
		int ans = -1;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (dp[i][j] == -1){
			int ret = DFS(i, j);
			if (ret>ans)
				ans = ret;
		}
		cout << ans << endl;
	}
	return 0;
}