#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
using namespace std;
struct Node{
	int x, y;
};
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

string mp[510];
bool vis[510][510];
int N, M;
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int lx, ly, rx, ry;
void bfs(int x, int y){
	lx = rx = x;
	ly = ry = y;
	Node start;
	start.x = x;
	start.y = y;
	queue<Node> qn;
	qn.push(start);
	vis[x][y] = 1;
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();

		lx = min(lx, u.x);
		ly = min(ly, u.y);
		rx = max(rx, u.x);
		ry = max(ry, u.y);

		for (int i = 0; i < 4; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			if (IN(v.x, v.y) && !vis[v.x][v.y] && mp[v.x][v.y] == '1'){
				vis[v.x][v.y] = 1;
				qn.push(v);
			}
		}
	}

}



int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; ++i)
		cin >> mp[i];
	for (int j = 0; j < M; ++j)
	for (int i = 0; i < N; ++i){
		if (!vis[i][j] && mp[i][j] == '1'){
			bfs(i, j);
			printf("%d %d\n", rx - lx + 1, ry - ly + 1);
			for (int ix = lx; ix <= rx; ++ix){
				for (int iy = ly; iy <= ry; ++iy){
					if (vis[ix][iy] && mp[ix][iy] == '1'){
						putchar('1');
						mp[ix][iy] = '0';
					}
					else{
						putchar('0');
					}
					
				}
				putchar('\n');
			}
		}

	}






	return 0;
}