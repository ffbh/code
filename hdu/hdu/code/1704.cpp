#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[510];
int N, M;
bool vis[510];

int dfs(int n){
	vis[n] = 1;
	int ans = 1;
	int size = vi[n].size();
	for (int i = 0; i < size; ++i)
	if (!vis[vi[n][i]])
		ans += dfs(vi[n][i]);
	return ans;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 0; i < 510; ++i)
			vi[i].clear();
		cin >> N >> M;
		while (M--){
			int a, b;
		//	in >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
		}
		int ans = 0;
		for (int i = 1; i <= N; ++i){
			memset(vis, 0, sizeof(vis));
			ans += dfs(i)-1;
		}
		cout << N*(N - 1)/2 - ans << endl;
	}
	return 0;
}