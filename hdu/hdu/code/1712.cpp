#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[110][110];
int dp[110];

int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N+M){
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j)
			//	in >> data[i][j];
			scanf("%d", &data[i][j]);

		for (int i = 1; i <= N;++i)
		for (int k = M; k >= 1;--k)
		for (int j = 1; j <= k;++j)
		if (dp[k] < dp[k - j] + data[i][j])
			dp[k] = dp[k - j] + data[i][j];
		cout << dp[M] << endl;

	}


	return 0;
}