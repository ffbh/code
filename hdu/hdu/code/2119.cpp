#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int map[101][101];
int N, M;
bool vis[101];
int link[101];
int dfs(int n){
	for (int i = 1; i <= M;++i)
	if (map[n][i] && !vis[i]){
		vis[i] = 1;
		if (link[i] == -1 || dfs(link[i])){
			link[i] = n;
			return 1;
		}
	}
	return 0;
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j)
			//cin >> map[i][j];
			scanf("%d", &map[i][j]);
		int res = 0;
		memset(link, -1, sizeof(link));
		for (int i = 1; i <= N; ++i){
			memset(vis, 0, sizeof(vis));
			if (dfs(i))
				res++;
		}
		cout << res << endl;
	}
	return 0;
}