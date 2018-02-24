#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int dp[40];
int dfs(int now){
	if (now > N)return 0;
	if (now == N)return 1;
	if (dp[now] != -1)return dp[now];
	int ans = 0;
	for (int i = now; i <= N&&i - now + 1 <= M; ++i)
		ans += dfs(i + 1);
	return dp[now] = ans;
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N + M){
		memset(dp, -1, sizeof(dp));
		cout << dfs(1) << endl;
	}
	return 0;
}