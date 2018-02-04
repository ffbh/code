#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M, K; 
int bird[10010];
int live[100010];
int dp[110][10010];
int r[110][10010];

int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> M >> K&&N + M + K){
		for (int i = 1; i <= N; ++i)
			in >> bird[i];
		for (int i = 1; i <= K; ++i)
			in >> live[i];
		memset(dp,0, sizeof(dp));
		r[1][0] = r[0][1] = r[0][0] = 0;
		bool flag = 0;
		for (int i = 1; i <= min(N,M+1)&&!flag;++i)
		for (int j = 1; j <= N&&!flag; ++j){
			int n, m, k;
			n = bird[j];
			if (r[i][j - 1] == 0){
				k = dp[i][j - 1] + 1;
				m = live[k];
			}
			else{
				k = dp[i][j - 1];
				m = r[i][j - 1];
			}
			while (k<K&&m == 0){
				k++;
				m = live[k];
			}
			if (k == K){
				flag = 1;
				break;
			}
			if (n < m){
				r[i][j] = m - n;
				dp[i][j] = dp[i][j - 1];
			}
			else{
				while (k<K){
					if (n>m){
						n -= m;
						k++;
						m = live[k];
					}
					else if (n == m){
						r[i][j] = 0;
						dp[i][j] = k;
						break;
					}
					else{
						r[i][j] = 0;
						dp[i][j] = k-1 ;
						break;
					}
				}
				if (k >= K){
					flag = 1;
					break;
				}
			}
			if (M){
				n = bird[j] * 2;
				if (r[i - 1][j - 1] == 0){
					k = dp[i - 1][j - 1] + 1;
					m = live[k];
				}
				else{
					k = dp[i - 1][j - 1];
					m = r[i - 1][j - 1];
				}
				while (k<K&&m == 0){
					k++;
					m = live[k];
				}
				if (k == K){
					flag = 1;
					break;
				}
				if (n < m){
					if (dp[i][j] < dp[i - 1][j - 1]){
						dp[i][j] = dp[i - 1][j - 1];
						r[i][j] = m - n;
					}
				}
				else{
					while (k<K){
						if (n>m){
							n -= m;
							k++;
							m = live[k];
						}
						else if (n == m){
							if (dp[i][j] < k){
								r[i][j] = 0;
								dp[i][j] = k;
							}
							break;
						}
						else{
							if (dp[i][j] < k - 1){
								r[i][j] = 0;
								dp[i][j] = k - 1;
							}
							break;
						}
					}
					if (k >= K){
						flag = 1;
						break;
					}
				}
			}
		}
		if (!flag)
			cout << dp[min(N, M + 1)][N] << endl;
		else
			cout << K << endl;
	}
	return 0;
}