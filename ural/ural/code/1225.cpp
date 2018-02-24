#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long dp[50][4];

void Init(){
	dp[1][0] = dp[1][3] = 1;
	dp[1][1] = dp[1][2] = 0;
	for (int i = 2; i < 50; ++i){
		dp[i][0] = dp[i - 1][2] + dp[i - 1][3];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][3];
		dp[i][3] = dp[i - 1][0] + dp[i - 1][1];
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	Init();
	int N;
	while (cin >> N){
		cout << dp[N][0] + dp[N][3] << endl;
	}






	return 0;
}