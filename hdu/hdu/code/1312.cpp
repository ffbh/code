#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int N,M;
bool map[30][30];
int sx, sy;
struct Point{
	int x, y;
};
bool IN(const Point& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}
int dirs[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
int dfs(const Point& p){
	map[p.x][p.y] = 1;
	int ans = 1;
	Point temp;
	for (int i = 0; i < 4; ++i){
		temp = p;
		temp.x += dirs[i][0];
		temp.y += dirs[i][1];
		if (IN(temp) && map[temp.x][temp.y] == 0)
			ans += dfs(temp);
	}
	return ans;
}


int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	while (cin >> M>>N&&N + M){
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == '#')
				map[i][j] = 1;
			else{
				map[i][j] = 0;
				sx = i;
				sy = j;
			}
		}
		Point Start;
		Start.x = sx;
		Start.y = sy;
		cout << dfs(Start) << endl;
	}

	return 0;
}