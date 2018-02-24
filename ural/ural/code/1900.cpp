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
int N, K;
long long data[510][510];
long long sum[510][510];
long long dp[510][510];
int path[510][510];
bool mark[510];

void Init(){
	memset(data, 0, sizeof(data));
	memset(sum, 0, sizeof(sum));
	memset(mark, 0, sizeof(mark));
	memset(path, 0, sizeof(path));
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	in >> N >> K;
	for (int i = 1; i < N; ++i){
		for (int j = i + 1; j <= N; ++j){
			in >> data[j][i];
		}

	}

	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= i; ++j){
		sum[i][j] = sum[i][j - 1] + data[i][j];
	}

	dp[2][1] = data[2][1];
	path[2][1] = 1;

	for (int i = 3; i <= N;++i)
	for (int j = 1; j < i; ++j){
		dp[i][j] = dp[i - 1][j - 1] + sum[i][i];
		path[i][j] = i - 1;

		if (dp[i][j] < dp[i - 1][j] + sum[i][path[i - 1][j]]){
			dp[i][j] = dp[i - 1][j] + sum[i][path[i - 1][j]];
			path[i][j] = path[i - 1][j];
		}
	}
	cout << dp[N][K] << endl;
	
	int a = N, b = K;
	while (b>0){
		if (dp[a][b] == dp[a - 1][b - 1] + sum[a][a]){
			mark[a - 1] = 1;
			b--;
		}
		a--;
	}

	for (int i = 1; i <= N;++i)
	if (mark[i]){
		cout << i << " ";
	}

	cout << endl;
	return 0;
}