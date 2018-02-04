#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int N;
string map[40];
_int64 dp[40][40];




_int64 dfs(int x, int y){
	
	_int64 ans = 0;
	if (x == N - 1 && y == N - 1)
		return 1;
	
	if (x > N - 1 || y > N - 1 || map[x][y]==0)
		return 0;
	if (dp[x][y] > -1) return dp[x][y];
	ans += dfs(x + map[x][y], y);
	ans += dfs(x, y + map[x][y]);
	return dp[x][y]=ans;
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N > 0){
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			map[i][j] -= '0';

		cout << dfs(0, 0) << endl;

	}

	return 0;
}