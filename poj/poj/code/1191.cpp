#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int N, data[10][10] ;
double dp[16][10][10][10][10], avgx;
int sum[10][10];
bool vis[16][10][10][10][10];


void Init(){
	memset(sum, 0, sizeof(sum));
	memset(vis, 0, sizeof(vis));
	avgx = 0;
}

double dfs(int n,int lx,int ly,int rx,int ry){
	if (vis[n][lx][ly][rx][ry]){
		return dp[n][lx][ly][rx][ry];
	}
	vis[n][lx][ly][rx][ry] = 1;
	double ans = 1e18;
	if (n == 1){
		double xi = sum[rx][ry] - sum[rx][ly-1] - sum[lx-1][ry] + sum[lx - 1][ly - 1];
		ans = pow(xi - avgx,2.0);
	}
	else{
		for (int i = lx; i + 1 <= rx; ++i){
			double lmin = dfs(1, lx, ly, i, ry) + dfs(n - 1, i + 1, ly, rx, ry);
			double rmin = dfs(n - 1, lx, ly, i, ry) +dfs(1, i + 1, ly, rx, ry);
			ans = min(ans, min(lmin, rmin));
		}

		for (int i = ly; i + 1 <= ry; ++i){
			double lmin = dfs(1, lx, ly, rx, i)+dfs(n - 1, lx, i + 1, rx, ry);
			double rmin = dfs(n - 1, lx, ly, rx, i)+dfs(1, lx, i + 1, rx, ry);
			ans = min(ans, min(lmin, rmin));
		}
	}

	return dp[n][lx][ly][rx][ry] = ans;
}
int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 1; i <= 8;++i)
	for (int j = 1; j <= 8; ++j)
		cin >> data[i][j];
	Init();

	for (int i = 1; i <= 8; ++i)
	for (int j = 1; j <= 8; ++j){
		avgx += data[i][j];
		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + data[i][j];
	}
	avgx /= N;

	double ans = dfs(N, 1, 1, 8, 8);
	printf("%.3f\n", sqrt(ans/N));













	return 0;
}