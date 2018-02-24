#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 99999999
struct Node{
	int to, v, c;
};
vector<Node> vi[10110];
bool vis[10010];
int dist[10010];
int N, M, K;
bool spfa(int M){
	queue<int> qn;
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + N + 2, INF);
	qn.push(1);
	dist[1] = 0;
	vis[1] = 1;
	while (!qn.empty()){
		int temp = qn.front();
		qn.pop();
		vis[temp] = 0;
		if (temp == N&&dist[N] <= K)
			return 1;
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i].to;
			int v = vi[temp][i].v;
			int c = vi[temp][i].c;
			if (v >= M&&dist[son]>dist[temp] + c){
				dist[son] = dist[temp] + c;
				if (!vis[son]){
					vis[son] = 1;
					qn.push(son);
				}
			}
		}
	}
	return 0;
}


int data[50010];

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 0; i < 10010; ++i)
			vi[i].clear();
		cin >> N >> M >> K;
		int size = 0;
		while (M--){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			//scanf("%d%d%d%d", &a, &b, &c, &d);
			data[size++] = c;
			vi[a].push_back(Node{ b, c, d });
			vi[b].push_back(Node{ a, c, d });
		}
		sort(data, data + size);
		int l = 0;
		int r = size - 1;
		int ans = -1;
		while (l <= r){
			int m = (l + r) / 2;
			if (spfa(data[m])){
				l = m+1;
				if (ans < data[m])
					ans = data[m];
			}
			else
				r = m-1;
		}
		cout << ans << endl;
	}
	return 0;
}