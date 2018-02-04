#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vi[100010];
int N, M;
bool vis[100010], mark[100010];

bool DFS(int u){
	vis[u] = 1;
	mark[u] = 1;
	for (int i = 0; i < vi[u].size(); ++i){
		int v = vi[u][i];
		if (vis[v] || !DFS(v))
			return 0;
	}
	vis[u] = 0;
	return 1;

}

int main(){
	ifstream in("C:\\input.txt");
	int T;
	in >> T;
	while (T--){
		in >> N >> M;
		for (int i = 1; i <= N; ++i){
			vi[i].clear();
			vis[i] = 0;
			mark[i] = 0;
		}

		while (M--){
			int u, v;
			in >> u >> v;
			vi[u].push_back(v);
		}
		bool f = 0;
		for (int i = 1; i <= N; ++i){
			if (!mark[i]){
				if (!DFS(i)){
					f = 1;
					break;
				}
			}

		}

		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;





	}


	return 0;
}