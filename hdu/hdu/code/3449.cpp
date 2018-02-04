#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[100010];
int temp[100010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M, W,K;
	while (cin >> N >> M){
		memset(dp,0, sizeof(dp));
		while (N--){
			memcpy(temp, dp, sizeof(temp));
			cin >> W >> K;
			while (K--){
				int v, w;
				cin >> v >> w;
				for (int i = M-W; i >= v;--i)
				if (temp[i] < temp[i - v] + w)
					temp[i] = temp[i - v] + w;
			}
			for (int i = M; i >= W;--i)
			if (dp[i] < temp[i - W])
				dp[i] = temp[i - W];
		}
		cout << dp[M] << endl;
	}
	return 0;
}