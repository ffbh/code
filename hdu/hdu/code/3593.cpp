#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Node{
	int c, v;
}data[100010];
vector<int> vi[510];
int dp[510][10010];

int N, K;

void dfs(int u, int g){
	for (int k = 0; k < vi[u].size(); ++k){
		int son = vi[u][k];
		if (son <= 500 && !vi[son].empty()){
			for (int i = 0; i <= g - data[son].c; ++i)
				dp[son][i] = dp[u][i];
			dfs(son, g - data[u].c);
			for (int i = g; i >= data[son].c; --i)
			if (dp[u][i] < dp[son][i - data[son].c] + data[son].v)
				dp[u][i] = dp[son][i - data[son].c] + data[son].v;
		}
		else{
			for (int i = g; i >= data[son].c; --i)
			if (dp[u][i] < dp[u][i - data[son].c] + data[son].v)
				dp[u][i] = dp[u][i - data[son].c] + data[son].v;

		}
	}
}



int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> K){
		for (int i = 0; i < 510; ++i)
			vi[i].clear();
		for (int i = 1; i <= N; ++i){
			int f;
			//in >> data[i].c >> data[i].v >> f;
			scanf("%d%d%d", &data[i].c, &data[i].v, &f);
			if (f == i)
				vi[0].push_back(i);
			else
				vi[f].push_back(i);
		}
		memset(dp, 0, sizeof(dp));
		dfs(0, K);
		cout << dp[0][K] << endl;
	}
	return 0;
}