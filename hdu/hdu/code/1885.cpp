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
bool vis[110][110][2<<5];
string map[110];
int N, M;
Node start;
bool IN(const Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };



int bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	memset(vis, 0, sizeof(vis));
	vis[start.x][start.y][start.key] = 1;
	qn.push(start);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (map[temp1.x][temp1.y] == 'X')
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2)&&!vis[temp2.x][temp2.y][temp2.key]&&map[temp2.x][temp2.y]>=0){
				vis[temp2.x][temp2.y][temp2.key] = 1;
				if (map[temp2.x][temp2.y] >= 9 && map[temp2.x][temp2.y] <= 16 &&
					!(temp2.key&(map[temp2.x][temp2.y] - 8)))
					continue;
				if (map[temp2.x][temp2.y] >= 1 && map[temp2.x][temp2.y] <= 8&&!(temp2.key&map[temp2.x][temp2.y]))
					temp2.key += map[temp2.x][temp2.y];
				qn.push(temp2);
			}
		}
	}
	return -1;
}





int main(){
	//ifstream in("C:\\temp.txt");
	int ok;
	while (cin >> N >> M&&N+M){
		ok = 0;
		
		for (int i = 0; i < N; ++i){
			cin >> map[i];
			for (int j = 0; j < M;++j)
			if (map[i][j] == '.')
				map[i][j] = 0;
			else if (map[i][j] == '#')
				map[i][j] = -1;
			else if (map[i][j] == 'X')
				ok++;
			else if (map[i][j] == '*'){
				start.x = i;
				start.y = j;
				start.step = 0;
				start.key = 0;
			}
			else if (map[i][j] == 'b')
				map[i][j] = 1;
			else if (map[i][j] == 'B')
				map[i][j] = 9;
			else if (map[i][j] == 'y')
				map[i][j] = 2;
			else if (map[i][j] == 'Y')
				map[i][j] = 10;
			else if (map[i][j] == 'r')
				map[i][j] = 4;
			else if (map[i][j] == 'R')
				map[i][j] = 12;
			else if (map[i][j] == 'g')
				map[i][j] = 8;
			else if (map[i][j] == 'G')
				map[i][j] = 16;
		}
		if (ok){
			int ans = bfs();
			if (ans>=0)
				printf("Escape possible in %d steps.\n", ans);
			else
				cout << "The poor student is trapped!" << endl;
		}
		else
			cout << "The poor student is trapped!" << endl;

	}





	return 0;
}