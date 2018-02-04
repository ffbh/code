#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int x, y;
	int movepoint;
	bool operator<(const Node& p)const{
		return movepoint<p.movepoint;
	}
};
string map[110];
int cost[110][110];
bool mark[110][110];
bool vis[110][110];
int N, M, K;
int sx, sy;
int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
bool IN(Node& p){
	return p.x >= 0 && p.x<N&&p.y >= 0 && p.y<M;
}


void InitMark(){
	memset(vis, 0, sizeof(vis));
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i<N; ++i)
	for (int j = 0; j<M; ++j)
	if (map[i][j] == 'E'){
		vis[i][j] = 1;
		Node next;
		for (int k = 0; k<4; ++k){
			next.x = i + dirs[k][0];
			next.y = j + dirs[k][1];
			if (IN(next))
				mark[next.x][next.y] = 1;
		}
	}
	else if (map[i][j] == '#')
		vis[i][j] = 1;
}

void bfs(){
	InitMark();
	priority_queue<Node> qn;
	Node temp1, temp2;
	temp1.movepoint = K;
	temp1.x = sx;
	temp1.y = sy;
	vis[sx][sy] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();
		if (map[temp1.x][temp1.y] == '.' ||
			map[temp1.x][temp1.y] == 'R' ||
			map[temp1.x][temp1.y] == 'T')
			map[temp1.x][temp1.y] = '*';
		if (temp1.movepoint<0)
			continue;
		for (int i = 0; i<4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y] && temp2.movepoint >= cost[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = 1;
				if (mark[temp2.x][temp2.y])
					temp2.movepoint = -1;
				else
					temp2.movepoint -= cost[temp2.x][temp2.y];
				qn.push(temp2);
			}
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M >> K;
		for (int i = 0; i<N; ++i){
			cin >> map[i];
			for (int j = 0; j<M; ++j)
			if (map[i][j] == '.' || map[i][j] == 'P')
				cost[i][j] = 1;
			else if (map[i][j] == '#' || map[i][j] == 'E')
				cost[i][j] = 9999999;
			else if (map[i][j] == 'T')
				cost[i][j] = 2;
			else if (map[i][j] == 'R')
				cost[i][j] = 3;
			else{
				sx = i;
				sy = j;
			}
		}
		bfs();
		for (int i = 0; i<N; ++i)
			cout << map[i] << endl;
		cout << endl;
	}
	return 0;
}
