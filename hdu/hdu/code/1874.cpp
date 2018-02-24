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
vector<Node> vn[210];
bool vis[210];
int dist[210];
int min(int a, int b){
	return a < b ? a : b;
}


int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
			vn[i].clear();
		while (M--){
			int a, b, c;
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			vn[a].push_back(Node(b, c));
			vn[b].push_back(Node(a, c));
		}
		int S, T;
		cin >> S >> T;
		if (S != T){
			memset(vis, 0, sizeof(vis));
			for (int i = 0; i < N; ++i)
				dist[i] = INT_MAX / 2;
			for (int i = 0; i < vn[S].size(); ++i){
				dist[vn[S][i].to] = min(vn[S][i].v, dist[vn[S][i].to]);
			}
			vis[S] = 1;
			for (int i = 0; i < N; ++i){
				int u = -1;
				int mmin = INT_MAX / 2;
				for (int j = 0; j < N; ++j)
				if (!vis[j] && dist[j] < mmin){
					u = j;
					mmin = dist[j];
				}
				if (u < 0)
					break;
				vis[u] = 1;
				for (int k = 0; k < vn[u].size(); ++k){
					int son = vn[u][k].to;
					int v = vn[u][k].v;
					if (!vis[son] && dist[son]>dist[u] + v)
						dist[son] = dist[u] + v;
				}
			}
			if (dist[T] < INT_MAX / 2)
				cout << dist[T] << endl;
			else
				cout << -1 << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}