#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int ans[600][600];
bool vis[600][1200];

void Init(){
	memset(vis, 0, sizeof(vis));

}

int main(){
	//ifstream in("C:\\input.txt");
	Init();
	int K, N;
	cin >> K;
	N = 1;
	for (int i = 0; i < K; ++i)
		N *= 2;
	int TOP = 2 * N - 1;
	for (int i = 1; i <= N; ++i){
		ans[i][i] = 1;
		vis[i][1] = 1;
	}
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= N; ++j){
		if (i == j)
			continue;
		for (int k = 2; k <= TOP; ++k){
			if (!vis[i][k] && !vis[j][k]){
				vis[i][k] = vis[j][k] = 1;
				ans[i][j] = k;
				break;
			}
		}
	}
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j < N; ++j)
			printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][N]);
	}

	return 0;
}