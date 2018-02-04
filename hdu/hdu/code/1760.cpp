#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int map[51][51];

bool dfs(){
	for (int i = 0; i < N - 1;++i)
	for (int j = 0; j < M - 1;++j)
	if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]){
		map[i][j] = map[i + 1][j] = map[i][j + 1] = map[i + 1][j + 1] = 0;
		if (!dfs()){
			map[i][j] = map[i + 1][j] = map[i][j + 1] = map[i + 1][j + 1] = 1;
			return 1;
		}
		map[i][j] = map[i + 1][j] = map[i][j + 1] = map[i + 1][j + 1] = 1;
	}
	return 0;
}

int main(){
//	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '0')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
		if (dfs())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}