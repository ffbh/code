#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int x, y, z;
	int step;
};
int N, M, K;
int map[11][11][2];
bool vis[11][11][2];
int sx, sy, sz;
int ex, ey, ez;
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

int bfs(){
	memset(vis, 0, sizeof(vis));
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.z = sz;
	temp1.step = 0;
	vis[sx][sy][sz] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		if (temp1.x == ex&&temp1.y == ey&&temp1.z == ez)
			return temp1.step;
		qn.pop();
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y][temp2.z]
				&&map[temp2.x][temp2.y][temp2.z]!=1){
				vis[temp2.x][temp2.y][temp2.z] = 1;
				if (map[temp2.x][temp2.y][temp2.z] == 2){
					temp2.z ^= 1;
					if (map[temp2.x][temp2.y][temp2.z] != 0)
						continue;
				}
				qn.push(temp2);

			}
		}
	}
	return -1;
}




int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M >> K;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M;++j)
			if (s[j] == '.')
				map[i][j][0] = 0;
			else if (s[j] == '*')
				map[i][j][0] = 1;
			else if (s[j] == '#')
				map[i][j][0] = 2;
			else if(s[j]=='P'){
				ex = i;
				ey = j;
				ez = 0;
				map[i][j][0] = 0;
			}
			else{
				sx = i;
				sy = j;
				sz = 0;
				map[i][j][0] = 0;
			}
		}
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '.')
				map[i][j][1] = 0;
			else if (s[j] == '*')
				map[i][j][1] = 1;
			else if (s[j] == '#')
				map[i][j][1] = 2;
			else if (s[j] == 'P'){
				ex = i;
				ey = j;
				ez = 1;
				map[i][j][1] = 0;
			}
			else{
				sx = i;
				sy = j;
				sz = 1;
				map[i][j][1] = 0;
			}
		}
		int ans = bfs();
		if (ans < 0 || ans > K)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}