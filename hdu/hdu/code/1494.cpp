#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define INF (1<<29)
int dp[10010][20];
int L, N;
int A[110], B[110];

void Init(){
	for (int i = 0; i < 10010;++i)
	for (int j = 0; j < 20; ++j)
		dp[i][j] = INF;
}





int main(){
	ifstream in("C:\\input.txt");
	while (cin >> L >> N){
		Init();
		for (int i = 0; i < L; ++i)
			cin >> A[i];
		for (int i = 0; i < L; ++i)
			cin >> B[i];
		N *= L;
		dp[0][0] = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < 20; ++j){
			if (dp[i][j] == INF)
				continue;
			int nextemery = j;
			if (nextemery == 14)
				nextemery -= 4;
			else
				nextemery++;
			if (dp[i + 1][nextemery]>dp[i][j] + A[i%L])
				dp[i + 1][nextemery] = dp[i][j] + A[i%L];
			if (j >= 5){
				if (dp[i + 1][j - 5] > dp[i][j] + B[i%L])
					dp[i + 1][j - 5] = dp[i][j] + B[i%L];
				}
		
		}
	
		int ans = INF;
		for (int i = 0; i < 20; ++i)
			ans = min(ans, dp[N][i]);
		cout << ans << endl;
	
	
	
	}
















	return 0;
}