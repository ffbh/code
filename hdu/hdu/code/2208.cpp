#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
bool map[15][15];
bool vis[15];
int N, M,mmax;///////
vector<int> V,temp;//////////

bool ok(int u){
	for (int i = 0; i < V.size();++i)
	if (!map[u][V[i]])
		return 0;
	return 1;
}


void dfs(int pos){
	if (V.size()>mmax){
		mmax = V.size();
		temp = V;
	}
	for (int i = pos; i < N;++i)
	if (!vis[i]&&ok(i)){
		vis[i] = 1;
		V.push_back(i);
		dfs(i);
		V.pop_back();
		vis[i] = 0;
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; ++i){
			int k;
			cin >> k;
			while (k--){
				int t;
				cin >> t;
				map[i][t] = 1;
			}
		}
		int num = N, piqiu = 0;
		while (num){
			mmax = 0;
			V.clear();
			int u;
			for (int i = 0; i < N;++i)
			if (!vis[i]){
				u = i;
				break;
			}
			dfs(u);
			num -= temp.size();
			piqiu++;
			for (int i = 0; i < temp.size(); ++i)
				vis[temp[i]] = 1;
		}
		if (piqiu>M)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}