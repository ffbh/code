#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> vi[505];
struct Node{
	int stime,etime;
	int a, b, c, d;
};
Node data[505];

bool vis[505];
int link[505];

bool OK(int a, int b){
	int c = abs(data[a].d - data[b].b) + abs(data[a].c - data[b].a);
	return c + data[a].etime < data[b].stime;
}
bool dfs(int n){
	for (int i = 0; i < vi[n].size();++i)
	if (!vis[vi[n][i]]){
		int son = vi[n][i];
		vis[son] = 1;
		if (link[son] == -1 || dfs(link[son])){
			link[son] = n;
			return 1;
		}

	}
	return 0;
}


int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		for (int i = 0; i < 505; ++i)
			vi[i].clear();
		for (int i = 1; i <= N; ++i){
			int h, m;
			scanf("%d:%d", &h, &m);
		//	cin >> h >> m;
			data[i].stime = 60 * h + m;
			cin >> data[i].a >> data[i].b >> data[i].c >> data[i].d;
			data[i].etime = data[i].stime+ abs(data[i].c - data[i].a) + abs(data[i].d - data[i].b);
		}
		memset(link, -1, sizeof(link));
		for (int i = 1; i <= N;++i)
		for (int j = i + 1; j <= N;++j)
		if (OK(i, j))
			vi[i].push_back(j);
		int ans = 0;
		for (int i = 1; i <= N; ++i){
			memset(vis, 0, sizeof(vis));
			ans += dfs(i);
		}
		cout << N - ans << endl;
	}
	return 0;
}