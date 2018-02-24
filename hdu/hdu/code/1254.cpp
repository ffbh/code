#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
struct node{
	int x, y;
	int rx,ry;
	int step;
};
int N, M;
int sx, sy, ex, ey, px, py;
bool map[10][10];
bool vis[10][10];
bool bm[10][10];
int dirs[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
bool IN(const node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

bool bfs_p(const node& t){
	memset(bm, 0, sizeof(bm));
	bm[px][py] = 1;
	node temp1, temp2;
	temp1.x = px;
	temp1.y = py;
	queue<node> qn;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.x == t.x&&temp2.y == t.y)return 1;
			if (IN(temp2) && !bm[temp2.x][temp2.y] && map[temp2.x][temp2.y] == 0){
				bm[temp2.x][temp2.y] = 1;
				if (temp2.x!=t.x||temp2.y!=t.y)
					qn.push(temp2);
			}
		}
	}
	return 0;
}

bool bmove(const node& t1, const node& t2){
	int xx = t1.x - t2.x;
	int yy = t1.y - t2.y;
	node temp = t1;
	temp.x += xx;
	temp.y += yy;
	return bfs_p(temp);

}



int bfs(){
	node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.rx = px;
	temp1.ry = py;
	temp1.step = 0;
	queue<node> qn;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.x == ex&&temp2.y == ey)
				return temp2.step;
			if (IN(temp2) && bmove(temp1, temp2) && map[temp2.x][temp2.y] == 0 && !vis[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = 1;
				temp2.rx = temp1.x;
				temp2.ry = temp1.y;
				qn.push(temp2);
			}
		}
	}
	return -1;
}
int main(){
	ifstream in("C:\\temp.txt");
	int n;
	in >> n;
	int t;
	while (n--){
		in >> N >> M;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
			in >> t;
		//	scanf("%d", &t);
			if (t == 0)
				map[i][j] = 0;
			else if (t == 1)
				map[i][j] = 1;
			else if (t == 2){
				sx = i;
				sy = j;
				map[i][j] = 0;
			}
			else if (t == 3){
				ex = i;
				ey = j;
				map[i][j] = 0;
			}
			else{
				px = i;
				py = j;
				map[i][j] = 0;
			}
		}//end_input
		memset(vis, 0, sizeof(vis));
		cout << bfs() << endl;
			
	
	}//while

	return 0;
}