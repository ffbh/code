#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N, M;
struct Node{
	int x, y;
	int step, dir;
};
int sx, sy;
bool vis[81][81][4];
bool map[81][81];
int dirs[4][2] = { 1, 0, 0, -1, -1, 0, 0, 1 };
int bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	memset(vis, 0, sizeof(vis));
	temp1.x = sx;
	temp1.y = sy;
	temp1.step = 0;
	for (int i = 0; i < 4; ++i){
		temp1.dir = i;
		vis[sx][sy][i] = 1;
		qn.push(temp1);
	}
	while (!qn.empty()){
		temp1 = qn.front();
	//	cout << temp1.x << " " << temp1.y << endl;
		qn.pop();
		if (temp1.x == 0 || temp1.x == N - 1 || temp1.y == 0 || temp1.y == M - 1)
			return temp1.step;
		temp1.step++;
		bool flag = 0;
		temp2 = temp1;
		temp2.dir = (temp1.dir + 1) % 4;
		temp2.x += dirs[temp2.dir][0];
		temp2.y += dirs[temp2.dir][1];
		if (map[temp2.x][temp2.y] == 0){
			flag = 1;
			if (!vis[temp2.x][temp2.y][temp2.dir]){
				vis[temp2.x][temp2.y][temp2.dir] = 1;
				qn.push(temp2);
			}
		}
		temp2 = temp1;
		temp2.dir = (temp1.dir + 3) % 4;
		temp2.x += dirs[temp2.dir][0];
		temp2.y += dirs[temp2.dir][1];
		if (map[temp2.x][temp2.y] == 0){
			flag = 1;
			if (!vis[temp2.x][temp2.y][temp2.dir]){
				vis[temp2.x][temp2.y][temp2.dir] = 1;
				qn.push(temp2);
			}
		}
		if (!flag){
			temp2 = temp1;
			temp2.x += dirs[temp2.dir][0];
			temp2.y += dirs[temp2.dir][1];
			if (map[temp2.x][temp2.y] == 0){
				if (!vis[temp2.x][temp2.y][temp2.dir]){
					vis[temp2.x][temp2.y][temp2.dir] = 1;
					qn.push(temp2);
				}
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
		cin >> N >> M;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j){
				if (s[j] == '#')
					map[i][j] = 1;
				else if (s[j] == '.')
					map[i][j] = 0;
				else{
					map[i][j] = 0;
					sx = i;
					sy = j;
				}

			}
		}
		cout << bfs() << endl;
	}
	return 0;
}