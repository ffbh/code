#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 dp[30][30];

int main(){
	ifstream in("C:\\temp.txt");
	dp[1][1] = 1;
	for (int i = 2; i < 30;++i)
	for (int j = 1; j <= i; ++j)
		dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		_int64 sum = 0;
		for (int i = 1; i <= N; ++i)
			sum += dp[N][i];
		cout << sum << endl;


	}
	



	return 0;
}