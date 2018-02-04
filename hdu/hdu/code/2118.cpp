#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M, K;
int map[201][2101];
int dp[201][2101];
bool ok[210][2101];

int dirs[4][2] = { 1, 0, 0, 1, 1, 2, 2, 1 };
bool IN(int x, int y){
	return x >= N ? 0 : y < 1 + x*M;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int x, y;
	while (cin >> N >> M >> K){
		memset(dp, 0, sizeof(dp));
		memset(ok, 0, sizeof(ok));
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < 1 + i*M; ++j)
			//    in >> map[i][j];
			scanf("%d", &map[i][j]);
		dp[0][0] = map[0][0];
		ok[0][0] = 1;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < 1 + i*M; ++j)
			if (ok[i][j])
			for (int k = 0; k < 4; ++k){
				x = i + dirs[k][0];
				y = j + dirs[k][1];
				if (IN(x, y)){
					if (dp[x][y]<dp[i][j] - K + map[x][y])
						dp[x][y] = dp[i][j] - K + map[x][y];
					if (dp[i][j]>K)
						ok[x][y] = 1;

				}
			}
		}
		int mmin = INT_MAX;
		for (int i = 0; i < 1 + (N - 1)*M; ++i)
		if (ok[N - 1][i] && dp[N - 1][i] < mmin)
			mmin = dp[N - 1][i];
		if (mmin != INT_MAX)
			cout << mmin << endl;
		else
			cout << "what a pity mouse!!" << endl;

	}
	return 0;
}