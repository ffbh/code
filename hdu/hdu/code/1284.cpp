#include <iostream>
//#include <fstream>
using namespace std;
int dp[32800];
int num[3] = { 1, 2, 3 };
int main(){
	//ifstream in("C:\\temp.txt");

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int k = 0; k < 3; ++k)
	for (int i = num[k]; i < 32800; ++i)
		dp[i] += dp[i - num[k]];
	int N;
	while (cin >> N)
		cout << dp[N] << endl;
		
	
	

	return 0;
}