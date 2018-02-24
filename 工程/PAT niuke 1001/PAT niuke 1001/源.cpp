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
struct T{
	int to, d;
	T(int _to,int _d){
		to = _to;
		d = _d;
	}
};
int C, N, P, M;
int data[510];
int path[510];
bool vis[510];
vector<T> vi[510];
struct Node{
	int dist, sendbike,receivebike;
}dp[510];

bool judge(int sbike ,int rbike,int idx){
	return sbike < dp[idx].sendbike || sbike == dp[idx].sendbike && rbike < dp[idx].receivebike;
}

void spfa(){
	dp[0].sendbike = dp[0].dist = dp[0].receivebike = 0;
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
			int sendbike = dp[u].sendbike;
			int receivedbike = dp[u].receivebike;
			if (data[v]>0){
				receivedbike += data[v];
			}
			else{
				int need = -data[v];
				int mmin = min(need, receivedbike);
				need -= mmin;
				receivedbike -= mmin;
				sendbike += need;
			}

			if (dp[v].dist > dp[u].dist + d || dp[v].dist == dp[u].dist + d&&judge(sendbike, receivedbike, v)){
				path[v] = u;
				dp[v].dist = dp[u].dist + d;
				dp[v].sendbike = sendbike;
				dp[v].receivebike = receivedbike;
				if (!vis[v]){
					vis[v] = 1;
					qi.push(v);
				}
			}
		}
	}
}

void Init(){
	for (int i = 0; i < 510; ++i){
		vi[i].clear();
		dp[i].dist = 1 << 30;
	}
	memset(vis, 0, sizeof(vis));
}

void dfs(int now){
	if (now == 0)
		cout << 0;
	else{
		dfs(path[now]);
		printf("->%d", now);
	}
}

int main(){
	ifstream in("C:\\input.txt");
	while (in >> C >> N >> P >> M){
		Init();

		for (int i = 1; i <= N; ++i){
			in >> data[i];
			data[i] -= C / 2;
		}
		while (M--){
			int a, b, c;
			in >> a >> b >> c;
			vi[a].push_back(T(b, c));
			vi[b].push_back(T(a, c));
		}

		spfa();
		cout << dp[P].sendbike;
		cout << " ";
		dfs(P);
		cout << " ";
		cout << dp[P].receivebike;
		cout << endl;
	}

	return 0;
}