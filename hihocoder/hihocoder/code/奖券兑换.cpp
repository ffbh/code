#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, M;
int num[11][11];
int dp[100010];

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	//scanf("%d%d", &N, &M);
	while (N--){
		int w, p;
		cin >> w >> p;
		num[w][p]++;
	}
	for (int i = 1; i <= 10;++i)
	for (int j = 1; j <= 10; ++j){
		int k = 1;
		while (k < num[i][j]){
			int w = i*k;
			int p = j*k;
			for (int f = M; f >= w;--f)
			if (dp[f] < dp[f - w] + p)
				dp[f] = dp[f - w] + p;
			num[i][j] -= k;
			k *= 2;
		}
		if (num[i][j]){
			int w = i*num[i][j];
			int p = j*num[i][j];
			for (int f = M; f >= w; --f)
			if (dp[f] < dp[f - w] + p)
				dp[f] = dp[f - w] + p;
		}
	}
	cout << dp[M] << endl;
	return 0;
}