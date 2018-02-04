#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N;
bool map[15][15][15];
bool vis[15][15][15];
int sx, sy, sz, ex, ey, ez;
struct node{
	int x, y, z;
	int step;
};

bool IN(const node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < N&&p.z >= 0 && p.z < N;
}

int dirs[6][3] = {
				1, 0, 0,
				0, 1, 0,
				-1, 0, 0,
				0, -1, 0,
				0, 0, 1,
				0, 0, -1 };


int bfs(){
	queue<node> qn;
	node temp1, temp2;
	temp1.step = 0;
	temp1.x = sx;
	temp1.y = sy;
	temp1.z = sz;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		temp1.step++;
		for (int i = 0; i < 6; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			temp2.z += dirs[i][2];
			if (temp2.x == ex&&temp2.y == ey&&temp2.z == ez)
				return temp2.step;
			if (IN(temp2)&&map[temp2.x][temp2.y][temp2.z]==0&&!vis[temp2.x][temp2.y][temp2.z]){
				vis[temp2.x][temp2.y][temp2.z] = 1;
				qn.push(temp2);
			}
		}
	}
	return -1;
}

int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	while (cin >> s){
		memset(vis, 0, sizeof(vis));
		cin >> N;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j){
			cin >> s;
			for (int k = 0; k < N;++k)
			if (s[k] == 'X')
				map[i][j][k] = 1;
			else
				map[i][j][k] = 0;
		}
		cin >> sz >> sy >> sx;
		cin >> ez >> ey >> ex;
		cin >> s;
		if (sx == ex&&sy == ey&&sz == ez){
			printf("%d %d\n", N, 0);
			continue;
		}
		int ans = bfs();
		if (ans == -1)
			printf("NO ROUTE\n");
		else
			printf("%d %d\n", N, ans);

	}//while
	return 0;
}