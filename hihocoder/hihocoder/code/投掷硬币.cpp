#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
double p[1010];
int N, M;

double dp[1010][1010];
bool ok[1010][1010];

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> p[i];
	dp[0][0] = 1;
	ok[0][0] = 1;
	for (int i = 0; i <= N;++i)
	for (int j = 0; j <= M; ++j){
		if (ok[i][j]){
			ok[i + 1][j] = 1;
			dp[i + 1][j] += dp[i][j] * (1.0 - p[i + 1]);
			ok[i + 1][j + 1] = 1;
			dp[i + 1][j + 1] += dp[i][j] * p[i + 1];
		}

	}

	printf("%.6f\n", dp[N][M]);














	return 0;
}