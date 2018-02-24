#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
bool mark[1100][1100];
double dp[1100][1100];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	double genhao = sqrt(2.0);
	cin >> N >> M;
	int K;
	cin >> K;
	while (K--){
		int a, b;
		cin >> a >> b;
		mark[a][b] = 1;
	}
	N++;
	M++;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j)
		dp[i][j] = 1e18;
	dp[1][1] = 0;
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j){
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
		dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
		if (mark[i][j])
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1] ,dp[i][j] + genhao);
	}
	printf("%d\n", int(dp[N][M] * 100+0.5));
	return 0;
}