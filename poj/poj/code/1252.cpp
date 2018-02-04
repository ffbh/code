#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[210];
int data[10];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 0; i <= 200; ++i)
			dp[i] = i;
		int N = 6;
		for (int i = 0; i < 6; ++i)
			cin >> data[i];
		int M = 100;
		while (M--){
			N = 6;
			while (N--){
				int t;
				t = data[N];
				for (int i = 1; i <= 200; ++i){
					if (i >= t&&dp[i] > dp[i - t] + 1)
						dp[i] = dp[i - t] + 1;
					if (i + t <= 200 && dp[i] > dp[i + t] + 1)
						dp[i] = dp[i + t] + 1;
				}
			}
		}
		int sum = 0, mmax = 0;
		for (int i = 1; i <= 100; ++i){
			sum += dp[i];
			if (dp[i] > mmax)
				mmax = dp[i];
		}
		printf("%.2f %d\n", double(sum) / 100, mmax);
	}
	return 0;
}