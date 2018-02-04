#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 dp[101];
int N;



int main(){
	ifstream in("C:\\temp.txt");
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 100; ++i){
		for (int j = 1; j <= i; ++j)
			dp[i] += (dp[i - j] * dp[j - 1]);
	}
	while (cin >> N&&N>0){
		cout << dp[N] << endl;

	}
	return 0;
}