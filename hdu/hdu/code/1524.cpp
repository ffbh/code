#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[1001];
int dp[1001];
int dfs(int x){
	bool vis[1001] = { 0 };
	if (dp[x] != -1)
		return dp[x];
	if (vi[x].empty())
		return dp[x] = 0;
	for (int i = 0; i < vi[x].size(); ++i)
		vis[dfs(vi[x][i])] = 1;
	for (int i = 0; i < 1001;++i)
	if (!vis[i])
		return dp[x] = i;
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int a;
	while (in >> N){
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i <= N; ++i)
			vi[i].clear();
		int M;
		for (int i = 0; i < N; ++i){
			in >> M;
			while (M--){
				in >> a;
				vi[i].push_back(a);
			}
		}
		while (in >> M&&M){
			int sum = 0;
			while (M--){
				in >> a;
				sum ^= dfs(a);
			}
			if (!sum)
				cout << "LOSE" << endl;
			else
				cout << "WIN" << endl;
		}
	}
	return 0;
}