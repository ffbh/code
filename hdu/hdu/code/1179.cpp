#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N, M;
vector<int> vi[110];
int link[110];
bool vis[110];

bool dfs(int n){
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

int MaxMatch(){
	int sum = 0;
	for (int i = 1; i <= M; ++i){
		memset(vis, 0, sizeof(vis));
		sum += dfs(i);
	}
	return sum;
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < 110; ++i)
			vi[i].clear();
		memset(link, -1, sizeof(link));
		for (int i = 1; i <= M; ++i){
			int K;
			cin >> K;
			while (K--){
				int t;
				cin >> t;
				vi[i].push_back(t);
			}
		}
		cout << MaxMatch() << endl;
	}
	return 0;
}