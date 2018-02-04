#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[1010];
bool vis[1010];
int dd[1010];
int N, M;

void dfs(int n){
	vis[n] = 1;
	for (int i = 0; i < vi[n].size(); ++i){
		int son = vi[n][i];
		if (!vis[son])
			dfs(son);
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N){
		for (int i = 1; i <= N; ++i)
			vi[i].clear();
		memset(dd, 0, sizeof(dd));
		memset(vis, 0, sizeof(vis));
		while (M--){
			int a, b;
	//		cin >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			vi[b].push_back(a);
			dd[a]++;
			dd[b]++;
		}
		dfs(1);
		bool flag = 1;
		for (int i = 1; i <= N;++i)
		if (!vis[i] || dd[i] % 2){
			flag = 0;
			break;
		}
		cout << flag << endl;
	}
	return 0;
}