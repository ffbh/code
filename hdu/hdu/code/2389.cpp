#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> vi[3010];
struct Person{
	int x, y;
	int dist;
}data[3010];
bool vis[3010];
int link[3010];
bool dfs(int n){
	for (int i = 0; i < vi[i].size(); ++i){
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
	for (int i = 0; i < M; ++i){
		memset(vis, 0, sizeof(vis));
		sum += dfs(i);
	}
	return sum ;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		int t;
		cin >> t;
		cin >> N;
		for (int i = 0; i < N; ++i){
		//	cin >> data[i].x >> data[i].y >> data[i].dist;
			scanf("%d%d%d", &data[i].x, &data[i].y, &data[i].dist);
			data[i].dist *= t;
		}
		cin >> M;
		int mm = max(N, M);
		for (int i = 0; i < mm; ++i){
			vi[i].clear();
			link[i] = -1;
		}
		for (int i = 0; i < M; ++i){
			double x, y;
		//	cin >> x >> y;
			scanf("%d%d", &x, &y);
			for (int j = 0; j < N;++j)
			if ((data[i].x - x)*(data[i].x - x) + (data[i].y - y)*(data[i].y - y) <= data[i].dist*data[i].dist)
				vi[i].push_back(j);
		}
		printf("Scenario #%d:\n", CASE++);
		cout << MaxMatch() << endl;
		cout << endl;
	}
	return 0;
}