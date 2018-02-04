#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vi[6010];
int data[6010];
int f[6010];
int N;
int dp[6010][2];

void dfs(int u){
	dp[u][0] = 0;
	dp[u][1] = data[u];
	if (!vi[u].empty()){
		for (int i = 0; i < vi[u].size(); ++i){
			int son = vi[u][i];
			dfs(son);
			dp[u][0] += max(dp[son][0], dp[son][1]);
			dp[u][1] += dp[son][0];
		}
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> data[i];
	int a, b;
	while (cin >> a >> b&&a + b){
		vi[b].push_back(a);
		f[a] = b;
	}
	int root = 1;
	while (f[root])root = f[root];
	dfs(root);
	cout << max(dp[root][0], dp[root][1]) << endl;
	return 0;
}