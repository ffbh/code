#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
	int to, v;
};
vector<Node> vn[155];
int dist[155];
bool vis[155];
int S, E;
int spfa(){
	queue<int> qi;
	fill(dist, dist + 155, INT_MAX);
	memset(vis, 0, sizeof(vis));
	qi.push(S);
	dist[S] = 0;
	vis[S] = 1;
	while (!qi.empty()){
		int temp = qi.front();
		vis[temp] = 0;
		qi.pop();
		for (int i = 0; i < vn[temp].size(); ++i){
			int son = vn[temp][i].to;
			int v = vn[temp][i].v;
			if (dist[son]>dist[temp] + v){
				dist[son] = dist[temp] + v;
				if (!vis[son]){
					vis[son] = 1;
					qi.push(son);
				}
			}
		}
	}
	return dist[E] == INT_MAX ? -1 : dist[E];
}


int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	Node t;
	map<string, int> msi;
	string s, e;
	int size;
	while (cin >> N&&N != -1){
		for (int i = 0; i < 155; ++i)
			vn[i].clear();
		size = 1;
		msi.clear();
		cin >> s >> e;
		if (!msi[s])
			msi[s] = size++;
		if (!msi[e])
			msi[e] = size++;
		S = msi[s];
		E = msi[e];
		while (N--){
			cin >> s >> e >> t.v;
			if (!msi[s])
				msi[s] = size++;
			if (!msi[e])
				msi[e] = size++;
			t.to = msi[e];
			vn[msi[s]].push_back(t);
			t.to = msi[s];
			vn[msi[e]].push_back(t);
		}
		cout << spfa() << endl;
	}
	return 0;
}