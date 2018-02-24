#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N, M;
vector<int> vi[100010];
int f[100010];
int deep[100010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
void dfs(int u, int d){
	deep[u] = d;
	for (int i = 0; i < vi[u].size(); ++i){
		int son = vi[u][i];
		dfs(son, d + 1);
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N + M){
		for (int i = 1; i <= N; ++i){
			f[i] = i;
			vi[i].clear();
		}
		for (int i = 1; i < N; ++i){
			int a, b;
			cin >> a >> b;
			vi[a].push_back(b);
			int fa = find(a);
			int fb = find(b);
			if (fa != fb)
				f[fb] = fa;
		}
		int root = find(1);
		dfs(root, 0);
		while (M--){
			int x, y;
			cin >> x >> y;
			if (deep[x] <= deep[y])
				printf("lxh\n");
			else
				printf("pfz\n");
		}
	}
	return 0;
}