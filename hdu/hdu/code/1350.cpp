#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
bool map[510][510];
bool vis[510];
int match[510];
int M;
struct Car{
	int time;
	int a, b;
	int c, d;
};
Car car[510];
int Isok(int i, int j){
	int t1 = abs(car[i].a - car[i].c) + abs(car[i].b - car[i].d);
	int t2 = abs(car[i].c - car[j].a) + abs(car[i].d - car[j].b);
	return t1 + t2 + car[i].time < car[j].time;
}

bool dfs(int n){
	for (int i = 0; i < M; ++i)
	if (!vis[i]&&map[n][i]){
		vis[i] = 1;
		if (match[i] == -1 || dfs(match[i])){
			match[i] = n;
			return 1;
		}
	}
	return 0;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	int h, m;
	while (N--){
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		cin >> M;
		for (int i = 0; i < M; ++i){
			//in >> h >> m;
			scanf("%d:%d", &h, &m);
			car[i].time = 60 * h + m;
			//in >> car[i].a >> car[i].b;
			//in >> car[i].c >> car[i].d;
			scanf("%d%d%d%d", &car[i].a, &car[i].b, &car[i].c, &car[i].d);
		}
		for (int i = 0; i < M;++i)
		for (int j = i + 1; j < M; ++j)
		if (Isok(i, j))
			map[i][j] = 1;
		int ans = 0;
		for (int i = 0; i < M; ++i){
			memset(vis, 0, sizeof(vis));
			if (dfs(i))
				ans++;
		}
		cout << M - ans << endl;
	}





	return 0;
}