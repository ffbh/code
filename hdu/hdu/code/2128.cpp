#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
	char map[9][9];
	char vis[9][9];
	int boom;
	int step;
	bool operator<(const Node& p)const{
		return step>p.step;
	}
};
int N, M;
int map[9][9];

int sx, sy, ex, ey;

int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}


int bfs(){
	priority_queue<Node> qn;
	Node temp1, temp2;
	memcpy(temp1.map, map, sizeof(map));
	memset(temp1.vis, -1, sizeof(temp2.vis));
	temp1.step = 0;
	temp1.x = sx;
	temp1.y = sy;
	temp1.boom = 0;
	qn.push(temp1);
	temp1.vis[temp1.x][temp1.y] = temp1.boom;
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();
		if (temp1.x == ex&&temp1.y == ey)
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && temp2.boom > temp2.vis[temp2.x][temp2.y]){
				temp2.vis[temp2.x][temp2.y] = temp2.boom;
				if (temp2.map[temp2.x][temp2.y] > 0){
					temp2.boom += temp2.map[temp2.x][temp2.y];
					temp2.map[temp2.x][temp2.y] = 0;
				}
				else if (temp2.map[temp2.x][temp2.y] == -1){
					if (temp2.boom == 0)
						continue;
					temp2.map[temp2.x][temp2.y] = 0;
					temp2.boom--;
					temp2.step++;
				}
				qn.push(temp2);
			}
		}
	}
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> M&&N+M){
		for (int i = 0; i < N; ++i){
			string s;
			in >> s;
			for (int j = 0; j < M;++j)
			if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == 'X')
				map[i][j] = -1;
			else if (s[j] == 'S'){
				map[i][j] = 0;
				sx = i;
				sy = j;
			}
			else if (s[j] == 'D'){
				map[i][j] = 0;
				ex = i;
				ey = j;
			}
			else
				map[i][j] = s[j] - '0';
		}
		cout << bfs() << endl;
	}
	return 0;
}