#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int N, M, tmp;
vector<int> vi[510];
bool vis[510];
void Init(){
	for (int i = 0; i < 510; ++i){
		vi[i].clear();
	}

}

void dfs(int p){
	if (vis[p])
		return;
	vis[p] = 1;
	for (int i = 0; i < vi[p].size(); ++i)
		dfs(vi[p][i]);
}
int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N >> M){
		Init();
		int ans = 0;
		for (int i = 1; i <= N; ++i){
			memset(vis, 0, sizeof(vis));
			
			for (int j = 1; j <= M; ++j){
				cin >> tmp;
				if (tmp == i)
					continue;
				ans++;
				if (!vis[tmp]){
					vis[tmp] = 1;
					vi[i].push_back(tmp);
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; ++i){
			if (vis[i] || vi[i].size()==0)
				continue;
			ans++;
			dfs(i);

		}
		cout << max(ans - 1,0) << endl;
	}
	return 0;
}