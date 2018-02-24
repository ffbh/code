#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
unsigned long long dp[40][5];
unsigned long long sum[40];
void Init(){
	for (int i = 1; i <= 4; ++i)
		dp[1][i] = 1;
	for (int i = 2; i < 40; ++i){
		dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
		dp[i][2] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
		dp[i][3] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
		dp[i][4] = dp[i - 1][4] + dp[i - 1][2] + dp[i - 1][3];
		sum[i] = 0;
		for (int j = 1; j <= 4; ++j)
			sum[i] += dp[i][j];
	}

	

}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	unsigned long long all = 4;
	unsigned long long illegal = 2;
	for (int N = 2; N <= 31; ++N){
		all *= 4;
		illegal *= 2;
		printf("N=%d: ", N);
		cout << all - sum[N] - (illegal - 2) << endl;
		
	}














	return 0;
}