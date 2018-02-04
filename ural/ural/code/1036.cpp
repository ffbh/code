#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long  dp[60][1010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, S;
	cin >> N >> S;
	if (S % 2 == 1)
		cout << 0 << endl;
	else{
		S /= 2;
		dp[0][0] = 1;
		for (int i = 1; i <= N;++i)
		for (int k = 0; k < 10;++k)
		for (int j = k; j <= S; ++j)
			dp[i][j] += dp[i - 1][j - k];
		int a;
		cout << dp[N][S] * dp[N][S] << endl;
	}






	return 0;
}