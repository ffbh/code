#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define BALANCE (10000)
int dp[20010];
bool ok[20010];


void Init(){
	memset(ok, 0, sizeof(ok));
}
int main(){
	ifstream in("C:\\input.txt");
	int T, N;
	cin >> T;
	while (T-- > 0){
		cin >> N;
		Init();
		ok[BALANCE] = 1;
		dp[BALANCE] = 0;
		int low, high;
		low = high = BALANCE;
		int ans = 0;
		for (int i = 1; i <= N; ++i){
			int a, b, c;
			cin >> a >> b >> c;
			b += BALANCE;
			if (a > 0){
				for (int j = b; j >=low ;--j)
				if (ok[j]){
					if (!ok[j + a]){
						ok[j + a] = 1;
						dp[j + a] = dp[j] + c;
					}
					else{
						dp[j + a] = max(dp[j + a], dp[j] + c);
					}
				}
				high += a;
			}
			else if(a<0){
				for (int j = b; j <= high; ++j)
				if (ok[j]){
					if (!ok[j + a]){
						ok[j + a] = 1;
						dp[j + a] = dp[j] + c;
					}
					else
						dp[j + a] = max(dp[j + a], dp[j] + c);
					ans = max(ans, dp[j + a]);

				}
				low += a;
			}
		}
		cout << ans << endl;
	}


	return 0;
}