#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long dp[70][70][70];

void Init(){
	dp[1][0][0] = 1;

		for (int i = 0; i <= 60;++i)
		for (int j = 0; j <= i;++j)
		for (int k = 0; k <= j; ++k){
			if (dp[i][j][k]){
				dp[i + 1][j][k] += dp[i][j][k];
				if (j + 1 <= i){
					dp[i][j + 1][k] += dp[i][j][k];
				}
				if (k + 1 <= j){
					dp[i][j][k + 1] += dp[i][j][k];
				}

			}

		}



}

int main(){
	ifstream in("C:\\input.txt");
	//0  de qingkuang

	Init();
	int n;
	while (in >> n){
		cout << dp[n][n][n] << endl << endl;

	}














	return 0;
}