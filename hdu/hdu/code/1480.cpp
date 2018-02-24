#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

unsigned long long dp[30][7];
unsigned long long sum[30];
unsigned long long f[30][2];


void Init(){
	for (int i = 1; i <= 6; ++i)
		dp[1][i] = 1;
	sum[1] = 6;
	for (int i = 2; i < 30; ++i){
		for (int j = 1; j <= 6; ++j)
			dp[i][j] = sum[i - 1];
		dp[i][1] -= dp[i - 1][6];
		dp[i][6] -= dp[i - 1][1];
		sum[i] = 0;
		for (int j = 1; j <= 6; ++j)
			sum[i] += dp[i][j];
	}
}



int main(){
	ifstream in("C:\\input.txt");
	Init();
	unsigned long long illegal = 4;
	for (int N = 3; N <= 25; ++N){
		printf("N=%d: ", N);
		illegal *= 2;
		unsigned long long del = 6;
		cout << sum[N] - del - 14 * (illegal - 2) << endl;






	}















	return 0;
}