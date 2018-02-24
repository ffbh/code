#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

long long dp[50][2], sum[50];

void Init(){
	dp[1][0] = dp[1][1] = 1;
	sum[1] = 2;
	for (int i = 2; i < 50; ++i){
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		sum[i] = dp[i][0] + dp[i][1];
	}

}
int main(){
	ifstream in("C:\\input.txt");
	Init();
	int N, K;
	while (cin >> N >> K){
		if (sum[N] < K)
			cout << -1 << endl;
		else{
			int pos = N;
		//	while (sum[pos] < K)
		//		pos++;
		//	for (int i = pos; i < N; ++i)
		//		putchar('0');
			while (pos >= 1){
				if (K > dp[pos][0]){
					if (pos > 1){
						cout << "10";
						K -= dp[pos][0];
						pos -= 2;
					}
					else{
						cout << "1";
						K -= dp[pos][0];
						pos --;

					}
				}
				else{
					cout << "0";
					pos--;
				}
			}
			cout << endl;
		}
	}


	return 0;
}