#include <iostream>
#include <cstring>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
vector<int> vi[110];
int vis[110];
int S;

bool dfs(int u){
	if (vis[u] != -1)
		return vis[u];
	vis[u] = 2;
	bool flag = 1;
	for (int i = 0; i < vi[u].size(); ++i){
		int son = vi[u][i];
		if (vis[son] == 2||!dfs(son)){
			vis[u] = 0;
			flag = 0;
			break;
		}
	}
	if (flag)
		vis[u] = 1;
	return vis[u];
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (in >> N&&N>=0){
		for (int i = 0; i < 110; ++i)
			vi[i].clear();
		memset(vis, -1, sizeof(vis));
		while (N--){
			int a, b;
			in >> a >> b;
			if (a != b)
				vi[a].push_back(b);
		}
		in >> S;
		if (dfs(S))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}