#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int mark[101][101];
bool vis[101];
int link[101];

bool dfs(int x){
	for (int i = 1; i <= M;++i)
	if (mark[x][i]&&!vis[i]){
		vis[i] = 1;
		if (link[i] == -1 || dfs(link[i])){
			link[i] = x;
			return 1;
		}
	}
	return 0;
}

int slove(){
	int ans = 0;
	memset(link, -1, sizeof(link));
	for (int i = 1; i <= N; ++i){
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			ans++;
	}
	return ans;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int K;
	int CASE = 1;
	while (cin >> N >> M >> K){
		memset(mark, 0, sizeof(mark));
		while (K--){
			int x, y;
			cin >> x >> y;
			mark[x][y] = 1;
		}
		int ans = slove();
		int major = 0;
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		if (mark[i][j]){
			mark[i][j] = 0;
			if (slove() != ans)
				major++;
			mark[i][j] = 1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", CASE++, major, ans);
	}
	return 0;
}