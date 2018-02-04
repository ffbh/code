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
#define INF (1<<22)
int T, N, M;
vector<int> vi[1010];
bool vis[1010];
int dist[1010];
void Init(){
	for (int i = 0; i < 1010; ++i)
		vi[i].clear();
}

int bfs(int s){
	memset(vis, 0, sizeof(vis));
	queue<int> qi;
	vis[s] = 1;
	dist[s] = 0;
	qi.push(s);
	while (!qi.empty()){
		int u = qi.front(), v;
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			v = vi[u][i];
			if (!vis[v]){
				vis[v] = 1;
				dist[v] = dist[u] + 1;
				qi.push(v);
			}
			else{
				int d = dist[v] + dist[u] + 1;
				if (d % 2 == 1){
					return d;
				}
			}
		}
	}
	return INF;

}

int main(){
	ifstream in("C:\\input.txt");
	int CASE = 1;
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> N >> M;
		while (M-- > 0){
			int a, b;
			cin >> a >> b;
		//	scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			vi[b].push_back(a);
		}



		int ret = INF;
		for (int i = 1; i <= N; ++i)
			ret = min(ret, bfs(i));
		if (ret == INF){
			printf("Case %d: Poor JYY.\n", CASE++);

		}
		else{
			printf("Case %d: JYY has to use %d balls.\n", CASE++, ret);
		}


	}
















	return 0;
}