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
vector<Node> vi[1010];
int data[15010];
int N, M;
bool vis[1010];
int pace[1010];
void Init(){
	for (int i = 0; i < 1010; ++i)
		vi[i].clear();
}


bool bfs(int limit){
	memset(vis, 0, sizeof(vis));
	queue<int> qi;
	qi.push(1);
	vis[1] = 1;
	int num = 1;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i].to;
			int d = vi[u][i].d;
			if (d <= limit){
				if (!vis[v]){
					num++;
					pace[v] = u;
					vis[v] = 1;
					qi.push(v);
				}
			}
		}
	}
	return num == N;
}


int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> M){
		Init();
		for(int i=0;i<M;++i){
			int a, b, c;
			cin >> a >> b >> c;
			data[i] = c;
			vi[a].push_back(Node(b, c));
			vi[b].push_back(Node(a, c));
		}

		sort(data, data + M);
		M = unique(data,data + M) - data;
		int L = 0, R = M - 1, ans = 1 << 27;
		while (L <= R){
			int mid = (L + R) / 2;
			if (bfs(data[mid])){
				ans = min(ans, data[mid]);
				R = mid - 1;
			}
			else{
				L = mid + 1;
			}
		}
		cout << ans << endl;
		cout << N - 1 << endl;
		for (int i = 2; i <= N; ++i)
			cout << i << " " << pace[i] << endl;


	}
	return 0;
}