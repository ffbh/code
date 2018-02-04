#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int to, d, c;
	Node(int _a, int _b, int _c){
		to = _a;
		d = _b;
		c = _c;
	}
};
int N, M;
vector<Node> vi[100010];
long long dist[100010], cost[100010];
bool vis[100010];
void Init(){
	for (int i = 0; i < 100010; ++i)
		vi[i].clear();
	for (int i = 0; i < 100010; ++i){
		dist[i] = cost[i] =(long long)1e18;
	}
	memset(vis, 0, sizeof(vis));
}

void spfa(){
	dist[0] = cost[0] = 0;
	queue<int> qi;
	qi.push(0);
	vis[0] = 1;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		vis[u] = 0;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i].to;
			int d = vi[u][i].d;
			int c = vi[u][i].c;
			if (dist[v] > dist[u] + d || dist[v] == dist[u] + d && cost[v] > c){
				dist[v] = dist[u] + d;
				cost[v] = c;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}
			}
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T-->0){
		Init();
		cin >> N >> M;
		for (int i = 0; i < M; ++i){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			vi[a].push_back(Node(b, c, d));
			vi[b].push_back(Node(a, c, d));
		}

		spfa();
		long long C, D;
		C = D = 0;
		for (int i = 0; i < N; ++i){
			D += dist[i];
			C += cost[i];
		}
		cout << D << " " << C << endl;

	}
















	return 0;
}