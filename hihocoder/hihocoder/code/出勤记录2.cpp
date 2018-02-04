#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
const long long mod = (1e9) + 7;

long long dp[100011][4][2];//0 L 1 ~L 
void Init(){
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
	for (int i = 1; i < 100010; ++i)
		for (int j = 0; j < 4;++j)
		for (int k = 0; k < 2; ++k){
			if (dp[i][j][k]){
				dp[i + 1][0][k] = (dp[i + 1][0][k] + dp[i][j][k]) % mod;// O
				if (j < 2){
					dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % mod;
				}
				if (k < 1){
					dp[i + 1][0][k + 1] = (dp[i + 1][0][k + 1] + dp[i][j][k]) % mod;
				}
			}
		}


	

}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int N;
	while (cin >> N){
		long long sum = 0;
		for (int i = 0; i < 3;++i)
		for (int j = 0; j < 2; ++j)
			sum = (sum + dp[N][i][j]) % mod;
		cout << sum << endl;
	}
















	return 0;
}