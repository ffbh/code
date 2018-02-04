#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
int map[1010][1010];
int dist[1010];
bool vis[1010];
int dd[1010];
void DJ(int start){
	memset(dist, 0, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= N; ++i)
	if (map[start][i] > 0 && i != start)
		dist[i] = map[start][i];
	else
		dist[i] = INT_MAX;
	dist[start] = 0;
	vis[start] = 1;
	for (int i = 1; i < N; ++i){
		int mmin = INT_MAX;
		int u;
		for (int j = 1; j <= N; ++j)
			if (!vis[j]&&mmin>dist[j]){
				mmin = dist[j];
				u = j;
			}
		vis[u] = 1;
		for (int k = 1; k <= N;++k)
			if (!vis[k] && map[u][k] > 0 && mmin + map[u][k] < dist[k])
				dist[k] = mmin + map[u][k];
	}
}

int dfs(int start){
	if (dd[start]>0)return dd[start];
	if (start == 2)return 1;
	for (int i = 1; i <= N; ++i)
	if (map[start][i] > 0 && dist[start] > dist[i]&&i!=1){
		if (dd[i]>0)dd[start] += dd[i];
		else
			dd[start] += dfs(i);
	}
	return dd[start];
}

int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> M){
		if (N == 0)break;
		memset(map, -1, sizeof(map));
		int a, b, c;
		for (int i = 0; i < M; ++i){
			in >> a >> b >> c;
			//scanf("%d%d%d", &a, &b, &c);
			map[a][b] = c;
			map[b][a] = c;
		}
		DJ(2);
		memset(dd, 0, sizeof(dd));
		cout << dfs(1)<< endl;
	}

	return 0;
}