#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool map[200][200];
int N, M;
int res[200];
int dfs(int x, int y){
	if (x >= N || map[x][y])
		return 0;
	map[x][y] = 1;
	return 1 + dfs(x + 1, y);
}



int main(){
	ifstream in("C:\\temp.txt");
	string s;
	while (cin >> N >> M){
		memset(res, 0, sizeof(res));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '0')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (map[i][j] == 0)
			res[dfs(i, j)]++;
		for (int i = 1; i <= N;++i)
		if (res[i])
			printf("%d %d\n", i, res[i]);
	}
	return 0;
}