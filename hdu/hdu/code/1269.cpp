#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[10001];
vector<int> tvi[10001];
bool vis[10001];
int dfs(vector<int>* v,int n){
	vis[n] = 1;
	int res = 1;
	for (int i = 0; i < v[n].size(); ++i){
		int son = v[n][i];
		if (!vis[son])
			res += dfs(v,son);
	}
	return res;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N + M){
		for (int i = 1; i <= N; ++i){
			vi[i].clear();
			tvi[i].clear();
		}
		while (M--){
			int a, b;
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			tvi[b].push_back(a);
		}
		memset(vis, 0, sizeof(vis));
		int k = dfs(vi, 1);
		if (k < N)
			cout << "No" << endl;
		else{
			memset(vis, 0, sizeof(vis));
			int k = dfs(tvi, 1);
			if (k < N)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
	}
	return 0;
}