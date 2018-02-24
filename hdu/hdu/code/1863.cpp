#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
bool vis[110];
int dist[110];
struct Node{
	Node(int b, int c) :to(b), v(c){}
	int to;
	int v;
};
vector<Node> vn[110];
int dfs(int n){
	vis[n] = 1;
	int num = 1;
	for (int i = 0; i < vn[n].size(); ++i){
		int son = vn[n][i].to;
		if (!vis[son])
			num += dfs(son);
	}
	return num;
}




int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> M >> N&&M){
		for (int i = 0; i < 110; ++i)
			vn[i].clear();
		for (int i = 0; i < M; ++i){
			int a, b, c;
			cin >> a >> b >> c;
			vn[a].push_back(Node(b, c));
			vn[b].push_back(Node(a, c));
		}
		if (M + 1 >= N){
			memset(vis, 0, sizeof(vis));
			if (dfs(1) < N)
				cout << "?" << endl;
			else{
				int ans = 0;
				memset(vis, 0, sizeof(vis));
				for (int i = 0; i < 110; ++i)
					dist[i] = INT_MAX;
				for (int i = 0; i < vn[1].size(); ++i){
					int son = vn[1][i].to;
					int d = vn[1][i].v;
					dist[son] = d;
				}
				vis[1] = 1;
				for (int i = 0; i < N - 1; ++i){
					int u;
					int mmin = INT_MAX;
					for (int j = 1; j <= N; ++j)
					if (!vis[j] && dist[j] < mmin){
						u = j;
						mmin = dist[j];
					}
					if (dist[u] == INT_MAX)
						break;
					ans += dist[u];
					vis[u] = 1;
					for (int k = 0; k < vn[u].size(); ++k){
						int son = vn[u][k].to;
						int d = vn[u][k].v;
						if (dist[son]>d&&!vis[son])
							dist[son] = d;
					}
				}
				cout << ans << endl;
			}
		}
		else
			cout << "?" << endl;



	}





	return 0;
}