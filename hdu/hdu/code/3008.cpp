#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int m, p;
}data[110];
int dp[110][110];
bool vis[110][110];

int main(){
//	ifstream in("C:\\temp.txt");
	int N, T, A;
	while (cin >> N >> T >> A&&N+T+A){
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		int mmin = 99999;
		for (int i = 0; i < N; ++i)
			cin >> data[i].p >> data[i].m;
		int TT = int(100.0 / A + 0.99999999);
		vis[0][100] = 1;
		for (int i = 0; i <= TT;++i)
		for (int j = 0; j <= 100; ++j)
		if(vis[i][j]){
			if (dp[i][j] >= 100){
				if (i < mmin)
					mmin = i;
			}
			if (dp[i + 1][j + T] < dp[i][j] + 1){
				dp[i + 1][j + T] = dp[i][j] + 1;
				vis[i + 1][j + T] = 1;
			}
			for (int k = 0; k < N; ++k){
				if (j >= data[k].p){
					if (dp[i + 1][j - data[k].p + T] < dp[i][j] + data[k].m){
						dp[i + 1][j - data[k].p + T] = dp[i][j] + data[k].m;
						vis[i + 1][j - data[k].p + T] = 1;
					}
				}
			}
		}
		if (mmin < 99999)
			cout << mmin << endl;
		else
			cout << "My god" << endl;
	}




	return 0;
}