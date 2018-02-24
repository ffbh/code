#include <iostream>
using namespace std;

int dp[150];
int main(){
	dp[0] = 1;
	for (int i = 1; i < 130;++i)
	for (int j = i; j < 130; ++j)
		dp[j] += dp[j - i];
	int N;
	while (cin >> N)cout << dp[N] << endl;




	return 0;
}