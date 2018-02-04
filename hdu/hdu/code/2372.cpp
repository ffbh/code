#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 dp[110][110];
int data[110];
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N+M){
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; ++i)
			dp[1][i] = 1;
		for (int i = 2; i <= M;++i)
		for (int j = 1; j <= N;++j)
		for (int k = 1; k < j;++k)
		if (data[k] < data[j])
			dp[i][j] += dp[i - 1][k];
		_int64 sum = 0;
		for (int i = 1; i <= N; ++i)
			sum += dp[M][i];
		cout << sum << endl;
	}
	return 0;
}