#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
int map[110][110];
int pace[110][110];
int dp[110][110];

int MAX(int a, int b, int c, int j){
	int m;
	if (dp[a][j] < dp[b][j])
		m = a;
	else if (dp[a][j] == dp[b][j])
		m = min(a, b);
	else
		m = b;
	if (dp[m][j] < dp[c][j])
		return m;
	else if (dp[m][j] == dp[c][j])
		return min(m, c);
	else
		return c;
}

void Print_path(int x,int y){
	if (pace[x][y] >= 0){
		Print_path(pace[x][y],y-1 );
		printf(" %d", x+1);
	}
	else
		printf("%d", x+1);
}

int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			//in >> map[i][j];
			scanf("%d", &map[i][j]);
		for (int i = 0; i < 110;++i)
		for (int j = 0; j < 110; ++j){
			pace[i][j] = -1;
			dp[i][j] = map[i][j];
		}
	//	memset(pace, -1, sizeof(pace));
	//	memcpy(dp, map, sizeof(dp));
		for (int k = 1; k < M; ++k){
			for (int i = 0; i < N; ++i){
				int ma, mb, mc,mm;
				ma = (i - 1 + N) % N;
				mb = i;
				mc = (i + 1 + N) % N;
				mm = MAX(ma, mb, mc,k-1);
				pace[i][k] = mm;
				dp[i][k] += dp[mm][k - 1];
			}
		}
		int mmin = (1<<30)+10;
		int u;
		for (int i = 0; i < N;++i)
		if (dp[i][M - 1] < mmin){
			mmin = dp[i][M - 1];
			u = i;
		}
		Print_path(u, M - 1);
		cout << endl;
		cout << dp[u][M - 1] << endl;
	}


	return 0;
}