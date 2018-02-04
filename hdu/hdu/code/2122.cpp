#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999
struct Node{
	int to, v;
};
vector<Node> vn[1001];
bool vis[1001];
int dist[1001];
int dfs(int n){
	int res = 1;
	vis[n] = 1;
	for (int i = 0; i < vn[n].size();++i)
	if (!vis[vn[n][i].to])
		res += dfs(vn[n][i].to);
	return res;
}

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		for (int i = 0; i <1001 ; ++i)
			vn[i].clear();
		while (M--){
			int a, b, c;
			cin >> a >> b >> c;
			//if (a != b){
				vn[a].push_back(Node{ b, c });
				vn[b].push_back(Node{ a, c });
			//}
		}
		memset(vis, 0, sizeof(vis));
		if (dfs(0) != N)
			cout << "impossible" << endl;
		else{
			int ans = 0;
			memset(vis, 0, sizeof(vis));
			fill(dist, dist + N, INF);
			for (int i = 0; i < vn[0].size(); ++i){
				int son = vn[0][i].to;
				if (vn[0][i].v<dist[son])
					dist[son] = vn[0][i].v;
			}
			vis[0] = 1;
			for (int k = 0; k < N - 1; ++k){
				int u, mmin;
				mmin = INT_MAX;
				for (int i = 0; i < N;++i)
				if (!vis[i] && dist[i] < mmin){
					u = i;
					mmin = dist[i];
				}
				ans += mmin;
				vis[u] = 1;
				for (int i = 0; i < vn[u].size(); ++i){
					int son = vn[u][i].to;
					int v = vn[u][i].v;
					if (!vis[son]&&dist[son]>v)
						dist[son] = v;
				}
			}
			cout << ans << endl;
		}
		cout << endl;
	}
	return 0;
}