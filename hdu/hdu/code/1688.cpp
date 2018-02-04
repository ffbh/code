#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int to;
	int v;
};
struct DP{
	int min_dist;
	int min_time;
	int next_dist;
	int next_time;
};
vector<Node> vi[1010];
DP dp[1010];
bool vis[1010];
int N, M;
int S, E;

int spfa(){
	for (int i = 1; i <= N; ++i){
		vis[i] = 0;
		dp[i].min_dist=dp[i].next_dist = INT_MAX;
		dp[i].min_time = dp[i].next_time = 0;
	}
	queue<int> qi;
	vis[S] = 1;
	qi.push(S);
	dp[S].min_dist = 0;
	dp[S].min_time = 1;
	while (!qi.empty()){
		int temp = qi.front();
		vis[temp] = 0;
		qi.pop();
		for (int i = 0; i < vi[temp].size(); ++i){
			int son = vi[temp][i].to;
			int v = vi[temp][i].v;
			int tempV = dp[temp].min_dist + v;
			if (tempV <= dp[son].next_dist){
				if (tempV < dp[son].min_dist){
					dp[son].next_dist = dp[son].min_dist;
					dp[son].next_time = dp[son].min_time;
					dp[son].min_dist = tempV;
					dp[son].min_time = dp[temp].min_time;
				}
				else if (tempV == dp[son].min_dist)
					dp[son].min_time += dp[temp].min_time;
				else if (tempV < dp[son].next_dist){
					dp[son].next_dist = tempV;
					dp[son].next_time = dp[temp].min_time;
				}
				else if (tempV == dp[son].next_dist)
					dp[son].next_time += dp[temp].min_time;
				if (!vis[son]){
					vis[son] = 1;
					qi.push(son);
				}
			}
		}
	}
	return dp[E].min_dist + 1 == dp[E].next_dist ? dp[E].min_time + dp[E].next_time : dp[E].min_time;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	in >> T;
	while (T--){
		in >> N >> M;
		for (int i = 1; i <= N; ++i)
			vi[i].clear();
		while(M--){
			int a;
			Node d;
			in >> a >> d.to >> d.v;
			vi[a].push_back(d);
		}
		in >> S >> E;
		cout << spfa() << endl;
	}
	return 0;
}