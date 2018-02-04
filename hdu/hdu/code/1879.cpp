#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Node{
	Node(int a, int b) :to(a), v(b){}
	int to;
	int v;
};
vector<Node> vn[110];
bool vis[110];
int dist[110];
int N;


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; ++i)
			vn[i].clear();
		int M = N*(N - 1) / 2;
		while (M--){
			int a, b, c, d;
		//	in >> a >> b >> c >> d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (d)
				c = 0;
			vn[a].push_back(Node(b, c));
			vn[b].push_back(Node(a, c));
		}
		for (int i = 1; i <= N; ++i)
			dist[i] = INT_MAX;
		for (int i = 0; i < vn[1].size(); ++i)
			dist[vn[1][i].to] = vn[1][i].v;
		vis[1] = 1;
		int ans = 0;
		for (int i = 0; i < N - 1; ++i){
			int u = -1;
			int mmin = INT_MAX;
			for (int j = 1; j <= N; ++j)
			if (!vis[j] && mmin>dist[j]){
				u = j;
				mmin = dist[j];
			}
			if (u < 0)
				break;
			vis[u] = 1;
			ans += dist[u];
			for (int k = 0; k < vn[u].size(); ++k){
				int son = vn[u][k].to;
				int v = vn[u][k].v;
				if (dist[son]>v)
					dist[son] = v;
			}
		}
		cout << ans << endl;
	}
	return 0;
}