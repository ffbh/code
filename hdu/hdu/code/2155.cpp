#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF (1<<29)
struct Node{
	int l, r, h;
	bool operator<(const Node& p)const{
		return h > p.h;
	}
}data[1010];
int dp[1010][2];
int N, X, Y, MAX, M;
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> X >> Y >> MAX >> M;
		data[0].h = Y;
		data[0].l = data[0].r = X;
		for (int i = 1; i <= N; ++i){
			cin >> data[i].l >> data[i].r >> data[i].h;
			dp[i][0] = dp[i][1] = INF;
		}
		N++;
		data[N].h = 0;
		data[N].l = -1;
		data[N].r = 1001;
		sort(data, data + N);
		dp[N][0] = dp[N][1] = INF;
		dp[0][0] = dp[0][1] = 0;
		for (int i = 0; i < N; ++i){
			for (int j = i + 1; j <= N && abs(data[j].h - data[i].h) <= MAX; ++j){
				int dh = abs(data[j].h - data[i].h);
				if (data[i].l >= data[j].l&&data[i].l <= data[j].r){
					int wsl = abs(data[i].l - data[j].l);
					int wsr = abs(data[i].l - data[j].r);
					if (j == N)
						wsl = wsr = 0;
					if (dp[j][0] > dp[i][0] + dh + wsl)
						dp[j][0] = dp[i][0] + dh + wsl;
					if (dp[j][1] > dp[i][0] + dh + wsr)
						dp[j][1] = dp[i][0] + dh + wsr;
					break;
				}
			}
			for (int j = i + 1; j <= N && abs(data[j].h - data[i].h) <= MAX; ++j){
				int dh = abs(data[j].h - data[i].h);
				if (data[i].r >= data[j].l&&data[i].r <= data[j].r){
					int wsl = abs(data[i].r - data[j].l);
					int wsr = abs(data[i].r - data[j].r);
					if (j == N)
						wsl = wsr = 0;
					if (dp[j][0] > dp[i][1] + dh + wsl)
						dp[j][0] = dp[i][1] + dh + wsl;
					if (dp[j][1] > dp[i][1] + dh + wsr)
						dp[j][1] = dp[i][1] + dh + wsr;
					break;
				}
			}
		}
		if (dp[N][0] <= M || dp[N][1] <= M)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
