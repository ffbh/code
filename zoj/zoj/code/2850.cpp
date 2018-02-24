#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int map[20][20];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(int x, int y){
	return x >= 1 && x <= N&&y >= 1 && y <= M;
}

bool judge(){
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j)
	if (map[i][j] == 0){
		int x, y;
		for (int k = 0; k < 4; ++k){
			x = i + dirs[k][0];
			y = j + dirs[k][1];
			if (IN(x, y) && map[x][y] == 0)
				return 0;
		}
	}
	return 1;
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N+M){
		bool flag = 1;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			cin >> map[i][j];
			if (map[i][j] == 0)
				flag = 0;
		}
		if (flag || !judge())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}