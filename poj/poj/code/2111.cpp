#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
struct Node{
	int x, y;
}pace[370][370];
int N;
int Ans[100010];
int size;
int dirs[8][2] = { 1, 2, 2, 1, -1, -2, -2, -1, 1, -2, -2, 1, -1, 2, 2, -1 };
long long map[370][370];
long long dp[370][370];
bool vis[370][370];

bool IN(int x, int y){
	return x >= 1 && x <= N&&y >= 1 && y <= N;
}

long long dfs(int x, int y){
	if (vis[x][y])
		return dp[x][y];
	vis[x][y] = 1;
	for (int i = 0; i < 8; ++i){
		int tx = x + dirs[i][0];
		int ty = y + dirs[i][1];
		if (IN(tx, ty) && map[x][y] < map[tx][ty]){
			long long ret = dfs(tx, ty);
			if (pace[x][y].x == -1||ret > dp[x][y]||(ret == dp[x][y]&&map[pace[x][y].x][pace[x][y].y] > map[tx][ty])){
				dp[x][y] = ret;
				pace[x][y].x = tx;
				pace[x][y].y = ty;
			}
		}

	}
	dp[x][y]++;
	return dp[x][y];

}

void getPace(int x, int y){
	if (x == -1)
		return;
	else{
		Ans[size++] = map[x][y];
		getPace(pace[x][y].x, pace[x][y].y);
	}

}
int main(){
	ifstream in("C:\\input.txt");

	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	memset(pace, -1, sizeof(pace));
	size = 0;
	cin >> N;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j)
		cin >> map[i][j];
	long long ans = -1;
	int ansx = -1, ansy;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j){
		long long ret = dfs(i, j);
		if (ansx == -1||ret > ans||(ret == ans&&map[i][j] < map[ansx][ansy])){
			ans = ret;
			ansx = i;
			ansy = j;
		}
	}
	getPace(ansx, ansy);
	cout << size << endl;
	for (int i = 0; i < size; ++i)
		cout << Ans[i] << endl;














	return 0;
}