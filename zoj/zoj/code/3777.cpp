#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int num[15], N, M, data[15][15];
int dp[1 << 13][510];
int gcd(int n, int m){
	if (m == 0)
		return n;
	else
		return gcd(m, n%m);
}
int main(){
	ifstream in("C:\\temp.txt");
	num[1] = 1;
	for (int i = 2; i < 15; ++i)
		num[i] = num[i - 1] * i;
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			cin >> data[i][j];
		for (int i = 1; i < (1 << N); ++i){
			int k = 0;
			for (int j = 0; j < 15;++j)
			if (i&(1 << j)) k++;
			for (int j = 1; j < 15; ++j)
			if (i&(1 << (j-1))){
				int pre = i^(1 << (j-1));
				int v = data[k][j];
				for (int t = 0; t + v < M; ++t)
					dp[i][t + v] += dp[pre][t];
			}
		}
		int sum1 = 0,sum2 = num[N];
		for (int i = 0; i < M; ++i)
			sum1 += dp[(1 << N) - 1][i];
		sum1 = sum2 - sum1;
		if (sum1 == 0){
			cout << "No solution" << endl;
			continue;
		}
		int g = gcd(sum2, sum1);
		printf("%d/%d\n", sum2 / g, sum1 / g);
	}
	return 0;
}