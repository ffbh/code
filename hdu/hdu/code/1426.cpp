#include <iostream>
#include <fstream>
using namespace std;
char map[10][10];
struct Point{
	int x, y;
};
Point num[100];
int cnt;

bool OK( const Point& p ){
	for (int i = 1; i <= 9; ++i)
	if (i != p.y&&map[p.x][i] == map[p.x][p.y])
		return 0;
	for (int i = 1; i <= 9; ++i)
	if (i != p.x&&map[i][p.y] == map[p.x][p.y])
		return 0;
	int si, ei, sj, ej;
	int ti = (p.x - 1) / 3;
	int tj = (p.y - 1) / 3;
	si = ti * 3 + 1;
	ei = si + 2;
	sj = tj * 3 + 1;
	ej = sj + 2;
	for (int i = si; i <= ei;++i)
	for (int j = sj; j <= ej;++j)
	if (i != p.x&&j != p.y&&map[i][j] == map[p.x][p.y])
		return 0;
	return 1;
}

bool dfs(int n){
	Point pp = num[n];
	for (char c = '1'; c <= '9'; ++c){
		map[pp.x][pp.y] = c;
		if (OK(pp)){
			if (n == cnt - 1){
				for (int i = 1; i <= 9; ++i){
					for (int j = 1; j < 9; ++j)
						printf("%c ", map[i][j]);
					printf("%c\n", map[i][9]);
				}
				return 1;
			}
			else if (dfs(n + 1))
				return 1;
		}

	}
	map[pp.x][pp.y] = 0;
	return 0;
}
int main(){
//	ifstream in("C:\\temp.txt");
	Point pp;
	int ok = 0;
	while (cin >> map[1][1]){
		cnt = 0;
		if (ok)cout << endl;
		ok = 1;
		if (map[1][1] == '?'){
			pp.x = 1;
			pp.y = 1;
			num[cnt++] = pp;
		}
		for (int i = 2; i <= 9; ++i){
			cin >> map[1][i];
			if (map[1][i] == '?'){
				pp.x = 1;
				pp.y = i;
				num[cnt++] = pp;
			}
		}
		for (int i = 2; i <= 9;++i)
		for (int j = 1; j <= 9; ++j){
			cin >> map[i][j];
			if (map[i][j] == '?'){
				pp.x = i;
				pp.y = j;
				num[cnt++] = pp;
			}
		}
		if (cnt == 0){
			for (int i = 1; i <= 9; ++i){
				for (int j = 1; j < 9; ++j)
					printf("%c ", map[i][j]);
				printf("%c\n", map[i][9]);
			}
		}
		else
			dfs(0);
	
	}

	return 0;
}