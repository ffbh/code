#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> vi[61];
int value[61];
int price[61];
bool major[61];
int dp[20010];
int ddp[20010];
int main(){
	//ifstream in("C:\\temp.txt");
	int m;
	while (cin >> N >> m){
		N /= 10;
		int money, p, pre;
		memset(major, 0, sizeof(major));
		memset(dp, 0, sizeof(dp));
		memset(value, 0, sizeof(value));
		memset(price, 0, sizeof(price));
		for (int i = 0; i < 61; ++i)
			vi[i].clear();
		for (int i = 1; i <= m; ++i){
			cin >> money >> p >> pre;
			money /= 10;
			price[i] = money;
			value[i] = money*p;
			if (pre != 0)
				vi[pre].push_back(i);
			else major[i] = 1;
		}
		for (int i = 1; i <= m; ++i)
		if (major[i]){
			if (vi[i].size() != 0){
				memcpy(ddp, dp, sizeof(ddp));
				//int mmin = INT_MAX;
				for (int k = 0; k < vi[i].size(); ++k){
					int j = vi[i][k];
				//	mmin = min(mmin, price[j]);
					for (int kk = N - price[i]; kk >= price[j]; --kk)
						ddp[kk] = max(ddp[kk], ddp[kk - price[j]] + value[j]);
				}
				for (int k = N; k >= price[i]; --k)
					dp[k] = max(dp[k], ddp[k - price[i]] + value[i]);
			}
			else
			for (int j = N; j >= price[i]; --j)
			if (dp[j] < dp[j - price[i]] + value[i])
				dp[j] = dp[j - price[i]] + value[i];
		}

		cout << dp[N] * 10 << endl;
		int a;
		a = dp[N];
	}


	return 0;
}