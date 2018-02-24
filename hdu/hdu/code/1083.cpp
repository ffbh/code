#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vi[110];
int N, M;
bool vis[310];
int link[310];
int dfs(int n){
	for (int i = 0; i < vi[n].size(); ++i){
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
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		bool flag = 1;
		for (int i = 0; i < 110; ++i)
			vi[i].clear();
		memset(link, -1, sizeof(link));
		cin >> N >> M;
		for (int i=1;i<=N;++i){
			int K;
		//	in >> K;
			scanf("%d", &K);
			if (K == 0)
				flag = 0;
			while (K--){
				int t;
				scanf("%d", &t);
			//	in >> t;
				vi[i].push_back(t);
			}
		}
		if (flag&&N<=M){
			int ans = 0;
			for (int i = 1; i <= N; ++i){
				memset(vis, 0, sizeof(vis));
				if (dfs(i))
					ans++;
				else
					break;
			}
			if (ans == N)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}