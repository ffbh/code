#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M, K;
bool vis[111];
bool map[111][111];
int link[111];
bool dfs(int n){
	for (int i = 1; i < M;++i)
	if (!vis[i]&&map[n][i]){
		vis[i] = 1;
		if (link[i] == -1 || dfs(link[i])){
			link[i] = n;
			return 1;
		}

	}
	return 0;
}




int main(){
	//ifstream in("C:\\temp.txt");
	int a, b, c;
	while (cin >> N &&N){
		cin >> M >> K;
		memset(map, 0, sizeof(map));
		memset(link, -1, sizeof(link));
		for (int i = 0; i < K; ++i){
		//	in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			if (b*c == 0)continue;
			map[b][c] = 1;
		
		}
		int ans = 0;
		for (int i = 1; i < N; ++i){
			memset(vis, 0, sizeof(vis));
			if (dfs(i))ans++;
		}
		cout << ans << endl;

	
	}

	return 0;
}