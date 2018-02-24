#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
struct Point{
	int x, y;
	int step;
};
int K, N, M, sx, sy, ex, ey;
int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
bool vis[1010][1010];
int map[1010][1010];
queue<Point> ftemp;

void fbfs(){
	Point temp1, temp2;
	while (!ftemp.empty()){
		temp1 = ftemp.front();
		ftemp.pop();
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2.step = temp1.step;
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (temp2.x >= 0 && temp2.x < N&&temp2.y >= 0 && temp2.y < M
				&& map[temp2.x][temp2.y]>temp1.step){
				map[temp2.x][temp2.y] = temp1.step;
				ftemp.push(temp2);
			}
		}
	}
}
int bfs(int m){
	memset(vis, 0, sizeof(vis));
	queue<Point> qn;
	Point temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.step = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (temp1.x == ex&&temp1.y == ey)
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.x >= 0 && temp2.x < N&&temp2.y >= 0 && temp2.y < M&&!vis[temp2.x][temp2.y]
				&&map[temp2.x][temp2.y]>=m){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
			}
		}
	}
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		while (!ftemp.empty())
			ftemp.pop();
	//	in >> K >> N >> M;
		scanf("%d%d%d", &K, &N, &M);
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j)
			map[i][j] = INT_MAX;
	//	in >> sx >> sy >> ex >> ey;
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		while (K--){
			int x, y;
		//	in >> x >> y;
			scanf("%d%d", &x, &y);
			ftemp.push(Point{ x, y, 0 });
			map[x][y] = 0;
		}
		fbfs();
		int l = 0;
		int r = min(map[sx][sy],map[ex][ey]);
		int ans1, ans2;
		while (l <= r){
			int m = (l + r) / 2;
			int ret = bfs(m);
			if (ret == -1)
				r = m - 1;
			else{
				ans1 = m;
				ans2 = ret;
				l = m + 1;
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}