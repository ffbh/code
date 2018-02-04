#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
vector<int> vi[510];
int N, M;
int link[510];
bool vis[510];
bool find(int u){
	if (vis[u])
		return 0;
	vis[u] = 1;
	for (int i = 0; i < vi[u].size(); ++i){
		int v = vi[u][i];
		if (link[v] == -1 || find(link[v])){
			link[v] = u;
			return 1;
		}

	}
	return 0;
}

int MaxMatch(){
	memset(link, -1, sizeof(link));
	int ans = 0;
	for (int i = 1; i <= N; ++i){
		memset(vis, 0, sizeof(vis));
		if (find(i))
			ans++;
	}
	return ans;
}


int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	while (M--){
		int u, v;
		cin >> u >> v;
		vi[u].push_back(v);
	}
	cout << N - MaxMatch() << endl;
















	return 0;
}