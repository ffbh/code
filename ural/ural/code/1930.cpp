#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (1<<28)
struct Node{
	int to;
	bool f;
};
int N, M, S, T;
int dist[10010];
int nowf[10010];
vector<Node> vi[10010];
bool vis[10010];
int spfa(){
	queue<int> qi;
	fill(dist, dist + 10010, INF);
	qi.push(S);
	nowf[S] = -1;
	vis[S] = 1;
	dist[S] = 0;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i].to;
			int f = vi[temp][i].f;
			int cost = dist[temp];
			if (nowf[temp]!=-1&&nowf[temp] != f)
				cost++;
			if (cost < dist[son]){
				dist[son] = cost;
				nowf[son] = f;
				if (!vis[son]){
					vis[son] = 1;
					qi.push(son);
				}
			}
		}
	}
}




int main(){
	ifstream in("C:\\temp.txt");
	cin >> N >> M;
	while (M--){
		int a, b;
		cin >> a >> b;
		vi[a].push_back(Node{ b, 0 });
		vi[b].push_back(Node{ a, 1 });
	}
	cin >> S >> T;
	spfa();
	cout << dist[T] << endl;



	return 0;
}