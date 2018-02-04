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

#define Exp (1e-8)

struct Node{
	int to;
	double p;

	Node(int a, double b){
		to = a;
		p = b;
	}

};
int N, M, S, T;
vector<Node> vi[100010];
int path[100010];
double P[100010];
int  dist[100010];
bool vis[100010];
void spfa(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 100010; ++i){
		dist[i] = (1 << 29);
		P[i] = -1;
	}
	P[S] = 1;
	dist[S] = 0;
	vis[S] = 1;
	queue<int> qi;
	qi.push(S);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		vis[u] = 0;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i].to;
			double p = vi[u][i].p;
			if (dist[v] > dist[u] + 1 || dist[v] == dist[u] + 1 && P[v] - P[u]*p < Exp){
				dist[v] = dist[u] + 1;
				P[v] = P[u] * p;
				path[v] = u;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}
			}
		}
	}
}

void dfs(int p){
	if (p == S){
		cout << S;
	}
	else{
		dfs(path[p]);
		cout << " " << p;
	}
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M >> S >> T;
	for (int i = 1; i <= M; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		vi[a].push_back(Node(b, 1.0 - 0.01*c));
		vi[b].push_back(Node(a, 1.0 - 0.01*c));
	}
	spfa();
	printf("%d %.6f\n", dist[T] + 1, 1.0 - P[T]);

	dfs(T);
	cout << endl;



	return 0;
}