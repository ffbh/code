#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int data[110];
int dp[110][32][32][32];
bool vis[110][32][32][32];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		int mmax = 0;
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			char c;
			cin >> c;
			if (c == 'A')
				data[i] = 1;
			else if (c == 'T' || c == 'J' || c == 'Q' || c == 'K')
				data[i] = 10;
			else if (c == 'F')
				data[i] = -1;
			else
				data[i] = c - '0';
		}
		vis[0][0][0][0] = 1;
		for (int t = 0; t < N;++t)
		for (int i = 0; i < 32;++i)
		for (int j = 0; j < 32;++j)
		for (int k = 0; k < 32;++k)
		if (vis[t][i][j][k]){
			int val;
			if (data[t] == -1){
				val = dp[t][i][j][k] + 150;
				if (i < 21){
					vis[t + 1][0][j][k] = 1;
					if (dp[t + 1][0][j][k] < val){
						dp[t + 1][0][j][k] = val;
						if (mmax < val)
							mmax = val;
					}
				}
				val += 100;
				if (j < 21){
					vis[t + 1][i][0][k] = 1;
					if (dp[t + 1][i][0][k] < val){
						dp[t + 1][i][0][k] = val;
						if (mmax < val)
							mmax = val;
					}
				}
				val += 100;
				if (k < 21){
					vis[t + 1][i][j][0] = 1;
					if (dp[t + 1][i][j][0] < val){
						dp[t + 1][i][j][0] = val;
						if (mmax < val)
							mmax = val;
					}
				}
			}
			else{
				if (i < 21){
					if (i + data[t] == 21){
						val = dp[t][i][j][k] + 150;
						vis[t + 1][0][j][k] = 1;
						if (dp[t + 1][0][j][k] < val){
							dp[t + 1][0][j][k] = val;
							if (mmax < val)
								mmax = val;
						}
					}
					else{
						val = dp[t][i][j][k] + 50;
						vis[t + 1][i + data[t]][j][k] = 1;
						if (dp[t + 1][i + data[t]][j][k] < val){
							dp[t + 1][i + data[t]][j][k] = val;
							if (mmax < val)
								mmax = val;
						}
					}
				}
				if (j < 21){
					if (j + data[t] == 21){
						val = dp[t][i][j][k] + 250;
						vis[t + 1][i][0][k] = 1;
						if (dp[t + 1][i][0][k] < val){
							dp[t + 1][i][0][k] = val;
							if (mmax < val)
								mmax = val;
						}
					}
					else{
						val = dp[t][i][j][k] + 50;
						vis[t + 1][i][j + data[t]][k] = 1;
						if (dp[t + 1][i][j + data[t]][k] < val){
							dp[t + 1][i][j + data[t]][k] = val;
							if (mmax < val)
								mmax = val;
						}
					}
				}
				if (k < 21){
					if (k + data[t] == 21){
						val = dp[t][i][j][k] + 350;
						vis[t + 1][i][j][0] = 1;
						if (dp[t + 1][i][j][0] < val){
							dp[t + 1][i][j][0] = val;
							if (mmax < val)
								mmax = val;
						}
					}
					else{
						val = dp[t][i][j][k] + 50;
						vis[t + 1][i][j][k + data[t]] = 1;
						if (dp[t + 1][i][j][k + data[t]] < val){
							dp[t + 1][i][j][k + data[t]] = val;
							if (mmax < val)
								mmax = val;
						}
					}
				}
			}
		}
		cout << mmax << endl;
	}
	return 0;
}