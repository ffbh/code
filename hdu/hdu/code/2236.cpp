#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, L, R;
int map[110][110];
bool vis[110];
int link[110];

int dfs(int n){
	for (int i = 1; i <= N;++i)
	if (!vis[i] && map[n][i] >= L&&map[n][i] <= R){
		vis[i] = 1;
		if (link[i] == -1 || dfs(link[i])){
			link[i] = n;
			return 1;
		}
	}
	return 0;
}

bool slove(){
	memset(link, -1, sizeof(link));
	for (int i = 1; i <= N; ++i){
		memset(vis, 0, sizeof(vis));
		if (!dfs(i))
			return 0;
	}
	return 1;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	//cin >> T;
	scanf("%d", &T);
	while (T--){
	//	cin >> N;
		scanf("%d", &N);
		int min, max;
		min = INT_MAX;
		max = INT_MIN;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
		//	cin >> map[i][j];
			scanf("%d", &map[i][j]);
			if (min > map[i][j])
				min = map[i][j];
			if (max < map[i][j])
				max = map[i][j];
		}
		int l = 0;
		int r = max - min;
		int m;
		int ans;
		while (l <= r){
			m = (l + r) / 2;
			bool ok = 0;
			for (L = min; L + m <= max; ++L){
				R = L + m;
				if (slove()){
					ok = 1;
					break;
				}
			}
			if (!ok)
				l = m + 1;
			else{
				r = m - 1;
				ans = m;
			}
		}
		cout << ans << endl;
	}
	return 0;
}