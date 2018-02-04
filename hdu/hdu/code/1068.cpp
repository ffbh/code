#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[1010];
bool vis[1001];
int link[1001];

bool dfs(int n){
	int sz = vi[n].size();
	for (int i = 0; i < sz; ++i){
		int son = vi[n][i];
		if (!vis[son]){
			vis[son] = 1;
			if (link[son] == -1 || dfs(link[son])){
				link[son] = n;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int b, n;
	while (cin >> N){
		for (int i = 0; i < 1010; ++i)
			vi[i].clear();
		memset(link, -1, sizeof(link));
		for (int i = 0; i < N; ++i){
			scanf("%d: (%d)", &b, &n);
			//in >> b >> n;
			for (int k = 0; k < n; ++k){
				int dd;
				scanf("%d", &dd);
			//	in >> dd;
				vi[b].push_back(dd);
			//	vi[dd].push_back(b);
			}
		}
		int ans = 0;
		for (int i = 0; i < N; ++i){
			memset(vis, 0, sizeof(vis));
			if (dfs(i))ans++;
		}
		cout << N-ans/2 << endl;
	
	
	}



	return 0;
}