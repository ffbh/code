#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N, M;

vector<int> vi[220];
int V[220];
int dp[220][220];
void dfs(int n,int m){
	int sz = vi[n].size();
	dp[n][0] = 0;
	for (int i = 1; i <= m; ++i)
		dp[n][i] = V[n];
	for (int i = 0; i < sz; ++i){
		int son = vi[n][i];
		dfs(son, m - 1);
		for (int j = m; j >= 1;j--)
		for (int k = 1; k <= j-1;++k)
		if (dp[n][j] < dp[n][k] + dp[son][j-k])
			dp[n][j] = dp[n][k] + dp[son][j-k];
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int a;
	while (cin >> N >> M&&N+M){
		for (int i = 0; i < 220; ++i)
			vi[i].clear();
		for (int i = 1; i <= N; ++i){
		//	in >> a >> V[i];
			scanf("%d%d", &a, &V[i]);
			vi[a].push_back(i);
		}
		V[0] = 0;
		dfs(0, M+1);
		cout << dp[0][M+1] << endl;


	
	
	}






	return 0;
}