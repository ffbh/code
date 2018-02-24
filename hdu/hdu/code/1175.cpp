#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;
int map[1010][1010];
bool vis[1010][1010];
int N, M,Q;
int sx, sy, ex, ey;
struct Point{
	int x, y;
	int time;
	int dir;
};
bool IN(const Point& p){
	return p.x > 0 && p.x <= N&&p.y > 0 && p.y <= M;
}

int dirs[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
bool bfs(){
	Point temp1, temp2;
	memset(vis, 0, sizeof(vis));
	queue<Point> pp;
	temp1.x = sx;
	temp1.y = sy;
	temp1.time = 0;
	temp1.dir = -1;
	pp.push(temp1);
	vis[temp1.x][temp1.y] = 1;
	while (!pp.empty()){
		temp1 = pp.front();
		pp.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			if (temp2.dir != i){
				temp2.time++;
				temp2.dir = i;
			}
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (!IN(temp2))
				continue;
			if (vis[temp2.x][temp2.y]||temp2.time>3)
				continue;
			vis[temp2.x][temp2.y] = 1;
			if (temp2.x == ex&&temp2.y == ey)
				return true;
			if (map[temp2.x][temp2.y] == 0)
				pp.push(temp2);
		
		}
	}
	return false;
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		if (N == 0 || M == 0)break;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j)
			//in >> map[i][j];
			scanf("%d", &map[i][j]);
		cin >> Q;
		while (Q--){
			//in >> sx >> sy >> ex >> ey;
			scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
			Point p1, p2;
			p1.x = ex;
			p1.y = ey;
			p2.x = sx;
			p2.y = sy;
			if (!IN(p1) || !IN(p2)){
				cout << "NO" << endl;
				continue;
			}
			if (map[sx][sy] != map[ex][ey] || map[sx][sy] == 0){
				cout << "NO" << endl;
				continue;
			}
			if (bfs())cout << "YES" << endl;
			else
			cout << "NO" << endl;
		}
	
	
	}

	return 0;
}