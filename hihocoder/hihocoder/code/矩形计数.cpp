#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long dp[1010][1010];
struct Node{
	int x, y;
}data[11];
void Init(){
	dp[1][1] = 1;
	for (int i = 2; i < 1010; ++i)
		dp[1][i] = dp[i][1] = dp[1][i - 1] + i;
	for (int i = 2; i < 1010;++i)
	for (int j = 2; j < 1010; ++j)
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + i*j;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int N, M, K, lx, ly, rx, ry;
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
		cin >> data[i].x >> data[i].y;
	long long ans = dp[N][M];
	for (int i = 1; i < (1 << K); ++i){
		lx = ly = 2222;
		rx = ry = -1;
		int num = 0;
		for (int j = 0; j < K; ++j){
			int p = 1 << j;
			if (i&p){
				num++;
				lx = min(lx, data[j].x);
				ly = min(ly, data[j].y);
				rx = max(rx, data[j].x);
				ry = max(ry, data[j].y);
			}
		}
		long long L = ly;
		long long U = lx;
		long long R = M - ry + 1;
		long long D = N - rx + 1;
		long long count = L*U*R*D;
		if (num % 2){
			ans -= count;
		}
		else
			ans += count;
	}
	cout << ans << endl;
	return 0;
}