#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[101];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	int T;
	cin >> T;
	while (T--){
		memset(dp, 0, sizeof(dp));
		cin >> N >> M;
		while (M--){
			int p, h, c;
			cin >> p >> h >> c;
			while (c--)
			for (int i = N; i >= p;--i)
			if (dp[i] < dp[i - p] + h)
				dp[i] = dp[i - p] + h;
		}
		cout << dp[N] << endl;
	}
	return 0;
}