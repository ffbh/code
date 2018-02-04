#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[1001][3];


int main(){
	ifstream in("C:\\temp.txt");
	dp[0][0] = 1;
	for (int i = 1; i <= 1000; ++i){
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 10000;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 10000;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 10000;
	}
	int N;
	while (cin >> N&&N)
		cout << dp[N][0] << endl;




	return 0;
}