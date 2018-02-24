#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;
struct Node{
	int l, r;
}dn[100010], dm[100010];
int num[500010];
long long ans;
map<pair<int, int>, int> mpi;
int dfs(int u){
	if (u == -1)
		return -1;
	pair<int, int> id;
	id.first = dfs(dn[u].l);
	id.second = dfs(dn[u].r);
	int f;
	if (!mpi.count(id))
		f = mpi[id] = mpi.size() + 1;
	else
		f = mpi[id];
	num[f]++;
	return f;
}

int DFS(int u){
	if (u == -1)
		return -1;
	pair<int, int> id;
	id.first = DFS(dm[u].l);
	id.second = DFS(dm[u].r);
	int f = mpi[id];
	ans += num[f];
	return f;
}
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		mpi.clear();
		ans = 0;
		memset(num, 0, sizeof(num));
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			cin >> dn[i].l >> dn[i].r;
		for (int i = 1; i <= M; ++i)
			cin >> dm[i].l >> dm[i].r;
		dfs(1);
		DFS(1);
		cout << ans << endl;
	}







	return 0;
}