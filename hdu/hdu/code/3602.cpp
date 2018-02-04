#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int T, N, M, K;
int a[110], b[110];
int dp[110][100010];

void Init(){
	memset(dp, 0, sizeof(dp));
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> N >> M >> K;
		for (int i = 1; i <= N; ++i){
			cin >> a[i] >> b[i];
			a[i]++;
		}
		for (int k = 1; k <= N; ++k){
			if (a[k] > K || b[k] == 0)
				continue;

			for (int i = M; i >= 1; --i)
			for (int j = K; j >= 0; --j){
				if (j + a[k] <= K){
					if (dp[i][j + a[k]] < dp[i][j] + b[k])
						dp[i][j + a[k]] = dp[i][j] + b[k];
				}
				else{
					for (int d = a[k]; d <= K;++d)
					if (dp[i + 1][d] < dp[i][j] + b[k])
						dp[i + 1][d] = dp[i][j] + b[k];
				}
			}
		}
		cout << dp[M][K] << endl;


	}



	return 0;
}