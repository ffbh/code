#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int dp[35];
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= 30; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << dp[N] << endl;
	}

	return 0;
}