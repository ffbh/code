#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
_int64 dist[110][110];
int p[110];
int N, M;
#define INF (1e18)
struct Node{
	int L;
	int money;
}data[4];

_int64 GetMoney(int x){
	if (x == 0)return 0;
	for (int i = 0; i < 4;++i)
	if (x <= data[i].L)
		return data[i].money;
	return INF;
}

void floyd(){
	for (int k = 1; k <= N;++k)
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N;++j)
	if (dist[i][j]>dist[i][k] + dist[k][j])
		dist[i][j] = dist[i][k] + dist[k][j];
}



int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		printf("Case %d:\n", CASE++);
		for (int i = 0; i < 4; ++i)
			cin >> data[i].L ;
		for (int i = 0; i < 4; ++i)
			cin >> data[i].money;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			cin >> p[i];
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			dist[i][j] = GetMoney(abs(p[i] - p[j]));
		floyd();
		while (M--){
			int a, b;
			cin >> a >> b;
			if (dist[a][b] < INF)
				printf("The minimum cost between station %d and station %d is %I64d.\n", a, b, dist[a][b]);
			else
				printf("Station %d and station %d are not attainable.\n",a, b);
		}
	}
	return 0;
}