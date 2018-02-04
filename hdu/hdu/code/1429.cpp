#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
	int step;
	int key;
};

bool vis[21][21][2050];
int map[21][21];
int N, M, T;
int sx, sy, ex, ey;

bool IN(const Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };



int bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.key = 0;
	temp1.step = 0;
	temp1.x = sx;
	temp1.y = sy;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (temp1.step >= T)
			continue;
		if (temp1.x == ex&&temp1.y == ey){
			return temp1.step;
		}
		temp2.step = temp1.step + 1;
		for (int i = 0; i < 4; ++i){
			temp2.key = temp1.key;
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y][temp2.key] && map[temp2.x][temp2.y] >= 0){
				vis[temp2.x][temp2.y][temp2.key] = 1;
				if (map[temp2.x][temp2.y] >= 1 && map[temp2.x][temp2.y] <= 2048){
					if (!(temp2.key&map[temp2.x][temp2.y])){
						temp2.key += map[temp2.x][temp2.y];
						vis[temp2.x][temp2.y][temp2.key] = 1;
					}
				}
				else if (map[temp2.x][temp2.y]>2048){
					if (!(temp2.key&(map[temp2.x][temp2.y] - 2048)))
						continue;
				}
				qn.push(temp2);
			}
		}
	}
	return -1;
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M >> T){
		string s;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == '*')
				map[i][j] = -1;
			else if (s[j] >= 'a'&&s[j] <= 'j')
				map[i][j] = 1 << (s[j] - 'a');
			else if (s[j] >= 'A'&&s[j] <= 'J')
				map[i][j] = ((1 << (s[j] - 'A')) + 2048);
			else if (s[j] == '@'){
				sx = i;
				sy = j;
				map[i][j] = 0;
			}
			else {
				ex = i;
				ey = j;
				map[i][j] = 0;
			}
		}
		cout << bfs() << endl;
	}
	return 0;
}