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
#define INF (1<<25)
struct Node{
	int id, d;
	Node(int a, int b){
		id = a;
		d = b;
	}
	bool operator<(const Node& p)const{
		return d>p.d;
	}
};

int dist[110][110], N, M;
vector<Node> vn[110];
void Init(){
	for (int i = 0; i < 110; ++i)
	for (int j = 0; j < 110; ++j)
		dist[i][j] = INF;
	for (int i = 0; i < 110; ++i)
		vn[i].clear();
}


int dp[110];

int spfa(int k, int start, int d){
	//queue<int> qi;
	priority_queue<Node> qi;
	for (int i = 0; i < 110; ++i)
		dp[i] = INF;
	dp[start] = d;
	qi.push(Node(start, d));
	while (!qi.empty()){
		int u = qi.top().id;
		qi.pop();

		for (int i = 0; i < vn[u].size(); ++i){
			int v = vn[u][i].id;
			int dd = vn[u][i].d;
			if (v == k)
				continue;
			if (dp[u] + dd < dp[v]){
				dp[v] = dp[u] + dd;
				qi.push(Node(v, dp[v]));
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= N; ++i){
		if (i == start)
			continue;
		if (dist[i][k] != INF && dp[i] != INF)
			ans = min(ans, dp[i] + dist[i][k]);
	}
	return ans;
}

int main(){
	ifstream in("C:\\input.txt");
/*	while (cin >> N >> M){
		Init();
		while (M-->0){
			int a, b, c;
		//	cin >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			dist[b][a] = dist[a][b] = min(dist[a][b], c);
		}
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j){
			if (dist[i][j] != INF)
				vn[i].push_back(Node(j, dist[i][j]));
		}
		int ans = INF;
		for (int k = 1; k <= N; ++k){

			for (int i = 1; i <= N; ++i){
				if (dist[k][i] == INF || i == k)
					continue;
				int ret = spfa(k, i, dist[k][i]);
				ans = min(ans, ret);
			}
		}
		if (ans != INF)
			cout << ans << endl;
		else
			cout << "It's impossible." << endl;
	}*/

/*	while (in >> N >> M){
		Init();
		while (M-->0){
			int a, b, c;
			in >> a >> b >> c;
			dist[b][a] = dist[a][b] = min(dist[a][b], c);
		}
		for (int k = 1; k <= N;++k)
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
			if (i==j||i==k||j==k)
				continue;
			if (dist[i][k] + dist[k][j] < dist[i][j])
				dist[i][j] = dist[i][k] + dist[k][j];
		}
		int ans = INF;
		for (int k = 1; k <= N; ++k)
		for (int i = k+1; i <= N; ++i)
		for (int j = i+1; j <= N; ++j){
			ans = min(ans, dist[k][i] + dist[i][j] + dist[k][j]);
		}
		if (ans != INF)
			cout << ans << endl;
		else
			cout << "It's impossible." << endl;

	}*/


	return 0;
}