#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double data[7];
int num[10] = { 5, 12, 22, 29, 33, 38, 42, 46, 50, 55 };
double dp[70], _dp[70];
double ans[70];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int ok = 0;
	while (T--){
		if (ok)cout << endl;
			ok = 1; 
		memset(dp, 0, sizeof(dp));
		memset(_dp, 0, sizeof(_dp));
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i < 7; ++i)
			cin >> data[i];
		dp[0] = 1;
		int K = 10;
		while (K--){
			for (int i = 0; i <= 55;++i)
			for (int j = 1; j <= 6; ++j)
				_dp[i + j] += dp[i] * data[j];
			for (int i = 0; i <= 55; ++i){
				ans[i] += _dp[i];
				dp[i] = _dp[i];
				_dp[i] = 0;
			}
		}
		for (int i = 0; i < 10; ++i)
			printf("%d: %.1f%%\n", num[i], ans[num[i]]*100.0);
	
	}
	return 0;
}