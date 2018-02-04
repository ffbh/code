#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int c[510][510];
vector<int> vi[510];
bool vis[510];
int pace[510];
bool bfs(int s,int e){
	memset(vis, 0, sizeof(vis));
	queue<int> qi;
	qi.push(s);
	vis[s] = 1;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		if (u == e)
			return 1;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (!vis[v]&&c[u][v]){
				vis[v] = 1;
				pace[v] = u;
				qi.push(v);
			}
		}
	}
	return 0;
}

int maxflow(int s,int e){
	int sum = 0,now, pre;
	while (bfs(s, e)){
		int mmin = (1 << 29);
		now = e;
		while (now != s){
			pre = pace[now];
			mmin = min(mmin, c[pre][now]);
			now = pre;
		}
		sum += mmin;

		now = e;
		while (now != s){
			pre = pace[now];
			c[pre][now] -= mmin;
			c[now][pre] += mmin;
			now = pre;
		}
	}
	return sum;
}





int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	while (M--){
		int u, v, t;
		cin >> u >> v >> t;
		c[u][v] += t;
		vi[u].push_back(v);
		vi[v].push_back(u);
	}
	cout << maxflow(1, N) << endl;
	return 0;
}