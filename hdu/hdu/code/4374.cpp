#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
using namespace std;
#define INF (-888888888)
int N, M, X, T;
struct Node{
	int x, val;
};
int data[110][10010];
int dp[110][100010];
int sum[110][10010];
deque<Node> dn;
int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> X >> T){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
		//	in >> data[i][j];
			scanf("%d", &data[i][j]);
			sum[i][j] = sum[i][j - 1] + data[i][j];
			dp[i][j] = INF;
		}
	/*	for (int i = 0; i <= M; ++i)
			dp[0][i] = INF;
		dp[0][X] = 0;*/
		for (int i = 1; i <= M;++i)
		if (X - i <= T&&X>=i)
			dp[1][i] = sum[1][X] - sum[1][i - 1];
		else if (i - X <= T&&X<i)
			dp[1][i] = sum[1][i] - sum[1][X - 1];
		for (int i = 1; i < N; ++i){
			dn.clear();
			for (int j = 1; j <= M; ++j){
				while (!dn.empty() && (j - dn.front().x) > T) 
					dn.pop_front();
				Node tmp;
				tmp.x = j;
				tmp.val = dp[i][j] - sum[i + 1][j - 1];
				while (!dn.empty() && dn.back().val <= tmp.val)
					dn.pop_back();
				dn.push_back(tmp);
				dp[i+1][j] = dn.front().val +sum[i + 1][j];
			}
			dn.clear();
			for (int j = M; j >= 1; --j){
				while (!dn.empty() && (dn.front().x - j) > T) dn.pop_front();
				Node tmp;
				tmp.x = j;
				tmp.val = dp[i][j] + sum[i + 1][j];
				while (!dn.empty() && dn.back().val <= tmp.val) dn.pop_back();
				dn.push_back(tmp);
				if (dp[i+1][j] < dn.front().val - sum[i + 1][j-1])
					dp[i+1][j] = dn.front().val - sum[i + 1][j-1];
			}
		}
		int mmax = INF;
		for (int i = 1; i <= M;++i)
		if (dp[N][i]>mmax)
			mmax = dp[N][i];
		cout << mmax << endl;
	}



	return 0;
}