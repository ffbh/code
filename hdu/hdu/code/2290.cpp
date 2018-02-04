#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define INF (1<<29)
int N, M;
int map[201][201];
int num[201][201];
int f[201];


void floyd(){
	for (int k = 0; k< N;++k)
	for (int i = 0; i <N;++i)
	for (int j = 0; j < N; ++j){
		int temp = num[i][k] + num[k][j] + f[k];
		if (map[i][j] > map[i][k] + map[k][j]){
			map[i][j] = map[i][k] + map[k][j];
			num[i][j] = temp;
		}
		else if (map[i][j] == map[i][k] + map[k][j] && num[i][j] > temp)
			num[i][j] = temp;
	}
}

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			cin >> f[i];
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
		if (i != j){
			map[i][j] = INF;
			num[i][j] = 0;
		}
		else{
			map[i][j] = 0;
			num[i][j] = 0;
		}
		while (M--){
			int u, v, w;
			cin >> u >> v >> w;
			map[u][v] = map[v][u] = w;
		}
		floyd();
		cin >> M;
		while (M--){
			int u, v, k;
			cin >> u >> v >> k;
			if (map[u][v] < INF&&num[u][v] <= k)
				cout << map[u][v] << endl;
			else
				cout << -1 << endl;
		}
		cout << endl;
	}
	return 0;
}