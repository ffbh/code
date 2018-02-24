#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define INF 9999999
struct Node{
	int to, v;
};
vector<Node> vn[50010];
int dist[50010];
bool vis[50010];
int spfa(int s, int t){
	queue<int> qn;
	memset(vis, 0, sizeof(vis));
	for (int i = s; i <= t; ++i)
		dist[i] = INF;
	qn.push(s);
	dist[s] = 0;
	vis[s] = 1;
	while (!qn.empty()){
		int temp = qn.front();
		qn.pop();
		vis[temp] = 0;
		for (int i = 0; i < vn[temp].size(); ++i){
			int son = vn[temp][i].to;
			int v = vn[temp][i].v;
			if (dist[son]>dist[temp] + v){
				dist[son] = dist[temp] + v;
				if (!vis[son]){
					vis[son] = 1;
					qn.push(son);
				}
			}
		}
	}
	return -dist[t];
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < 50010; ++i)
			vn[i].clear();
		int max = -1;
		int min = INF;
		while (N--){
			int a, b, c;
			//cin >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			a++;
			b++;
			vn[a].push_back(Node{ b+1, -c });
			if (max < b)
				max = b;
			if (min>a)
				min = a;
		}
		for (int i = min; i <= max + 1; ++i){
				vn[i].push_back(Node{ i + 1, 0 });
				vn[i].push_back(Node{ i - 1, 1 });
		}
		cout << spfa(min, max + 1) << endl;
	}
	return 0;
}