#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
int map[30][30];
int vis[30][30];
int N, M;
int sx, sy, ex, ey;
struct Node{
	int x, y;
	int step;
};
bool IN(const Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}


int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };


int bfs(){
	memset(vis, 0, sizeof(vis));
	queue<Node> qn;
	Node temp1, temp2;
	temp1.step = 0;
	temp1.x = sx;
	temp1.y = sy;
	qn.push(temp1);
	while (!qn.empty()){
		bool flag = 0;
		temp1 = qn.front();
		qn.pop();
		if (temp1.x == ex&&temp1.y == ey)
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && vis[temp2.x][temp2.y]<=2){
				if (map[temp2.x][temp2.y] == 1 || map[temp2.x][temp2.y] == 2){
					if (i % 2 != (temp2.step + map[temp2.x][temp2.y]) % 2){
						temp2.x += dirs[i][0];
						temp2.y += dirs[i][1];
						if (IN(temp2) && !vis[temp2.x][temp2.y]){
							vis[temp2.x][temp2.y]++;
							qn.push(temp2);
						}
					}
					else
						flag = 1;
				}
				else{
					vis[temp2.x][temp2.y]++;
					qn.push(temp2);
				}
			}
		}
		if (flag&&vis[temp1.x][temp1.y]<=2)
			qn.push(temp1);
	}
	return -1;
}




int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> M){
		string s;
		for (int i = 0; i < N; ++i){
			in >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == '*')
				vis[i][j] = 1;
			else if (s[j] == '|')
				map[i][j] = 1;
			else if (s[j] == '-')
				map[i][j] = 2;
			else if (s[j] == 'T'){
				ex = i;
				ey = j;
				map[i][j] = 0;
			}
			else{
				sx = i;
				sy = j;
			}
		}
		cout << bfs() << endl;


	}

	return 0;
}