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
	int to, d;
	Node(int a, int b){
		to = a;
		d = b;
	}
};
int N, M, S, F;

vector<Node> vi[510];
bool vis[510];
int dist[510];

void spfa(){
	memset(vis, 0, sizeof(vis));
	queue<int> qi;
	vis[S] = 1;
	qi.push(S);
	dist[S] = 0;
	dist[F] = -1;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		vis[u] = 0;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i].to;
			int d = vi[u][i].d;
			if (dist[v] < dist[u] + d){
				dist[v] = dist[u] + d;
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
	cin >> N >> M;

	for (int i = 0; i < M; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		vi[a].push_back(Node(b, c));
	}



	cin >> S >> F;

	spfa();

	if (dist[F] == -1){
		cout << "No solution" << endl;
	}
	else{
		cout << dist[F] << endl;
	}




	return 0;
}