#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N, Q;
struct Node{
	int to, v;
};
vector<Node> vi[110];
int dp[110][110];
void dfs(int u, int f, int g){
	for (int i = 0; i < vi[u].size(); ++i){
		int son = vi[u][i].to;
		int v = vi[u][i].v;
		if (son == f)
			continue;
		if (vi[son].size() != 1){
			for (int j = 0; j < g; ++j)
				dp[son][j] = dp[u][j];
			dfs(son, u, g - 1);
			for (int j = g; j >= 1;--j)
			if (dp[u][j] < dp[son][j - 1] + v)
				dp[u][j] = dp[son][j - 1] + v;
		}
		else{
			for (int j = g; j >= 1;--j)
			if (dp[u][j] < dp[u][j - 1] + v)
				dp[u][j] = dp[u][j - 1] + v;
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	cin >> N >> Q;
	for (int i = 1; i < N; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		vi[a].push_back(Node{ b, c });
		vi[b].push_back(Node{ a, c });
	}
	dfs(1, -1, Q );
	cout << dp[1][Q ] << endl;
	return 0;
}