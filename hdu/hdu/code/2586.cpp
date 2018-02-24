#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N, Q;
struct Node{
	int to, v;
};
vector<Node> vi[40010];
vector<Node> qus[40010];
int f[40010];
bool vis[40010];
int ans[210];
int dist[40010];

int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
void Union(int a, int b){//bÊÇaµÄ×æÏÈ
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
		f[fa] = fb;
}


void tarjan(int u, int F,int sum){
	dist[u] = sum;
	f[u] = u;
	for (int i = 0; i < vi[u].size(); ++i){
		int son = vi[u][i].to;
		int v = vi[u][i].v;
		if (son == F)continue;
		tarjan(son, u, sum + v);
		Union(son, u);
	}
	vis[u] = 1;
	for (int i = 0; i < qus[u].size(); ++i){
		int to = qus[u][i].to;
		int res = qus[u][i].v;
		if (vis[to]){
			int father = find(to);
			ans[res] = dist[u] + dist[to] - 2 * dist[father];
		}
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> Q;
		for (int i = 1; i <= N; ++i){
			vi[i].clear();
			qus[i].clear();
		}
		for (int i = 1; i < N; ++i){
			int a, b, c;
			cin >> a >> b >> c;
			vi[a].push_back(Node{ b, c });
			vi[b].push_back(Node{ a, c });
		}
		for (int i = 0; i < Q; ++i){
			int a, b;
			cin >> a >> b;
			qus[a].push_back(Node{ b, i });
			qus[b].push_back(Node{ a, i });
		}
		memset(vis, 0, sizeof(vis));
		tarjan(1, -1, 0);
		for (int i = 0; i < Q; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}