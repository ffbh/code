#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define INF (1<<29)
int N, M;
bool vis[110][110];
int data[110][110];
int pace[110][110];
int dp[110][110];
void Print(int x, int y){
	if (x == 0 || y == 0)
		return;
	Print(x - 1, pace[x][y]);
	if (x != N)
		printf("%d ", y);
	else
		printf("%d\n", y);
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		cin >> N >> M;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			cin >> data[i][j];
			dp[i][j] = INF;
		}
		for (int i = 1; i <= M; ++i){
			dp[1][i] = data[1][i];
			pace[1][i] = 0;
		}
		for (int i = 0; i <= N; ++i)
			dp[i][0] = dp[i][M + 1] = INF;
		for (int i = 2; i <= N;++i)
		for (int j = 1; j <= M; ++j)
		for (int k = -1; k <= 1;++k)
		if (dp[i][j] >= dp[i - 1][j + k] + data[i][j]){
			dp[i][j] = dp[i - 1][j + k] + data[i][j];
			pace[i][j] = j + k;
		}
		int mmin = INF;
		int u;
		for (int i = 1; i <= M; ++i)
		if(mmin>=dp[N][i]){
			mmin = dp[N][i];
			u = i;
		}
		printf("Case %d\n", CASE++);
		Print(N, u);
	}



	return 0;
}