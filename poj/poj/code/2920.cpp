#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int x, y;
};
int map[310][310];
bool vis[310][310];
int N, M;
int dirs[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
bool IN(int x, int y){
	return x >= 1 && x <= N&&y >= 1 && y <= N;
}


void bfs(){
	memset(vis, 0, sizeof(vis));
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = N / 2 + 1;
	temp1.y = N / 2 + 1;
	vis[temp1.x][temp1.y] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (map[temp1.x][temp1.y] != 0)
			continue;
		for (int i = 0; i < 8; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2.x, temp2.y) && !vis[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
			}
		}
	}
}


int main(){
	//ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		memset(map, 0, sizeof(map));
		cin >> N >> M;
		while (M--){
			int x, y;
			cin >> x >> y;
			map[x][y] = -1;
		}
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
		if (map[i][j] != -1){
			int nx, ny, num = 0;
			for (int k = 0; k < 8; ++k){
				nx = i + dirs[k][0];
				ny = j + dirs[k][1];
				if (IN(nx, ny) && map[nx][ny] == -1)
					num++;
			}
			map[i][j] = num;
		}
		bfs();
		printf("Scenario #%d:\n", CASE++);
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= N; ++j){
				if (map[i][j] == -1)
					putchar('*');
				else if (vis[i][j]){
					if (map[i][j] == 0)
						putchar('.');
					else
						putchar('#');
				}
				else
					putchar('?');
			}
			putchar('\n');
		}
		cout << endl;
	}
	return 0;
}