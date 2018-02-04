#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N, M;
struct Node{
	int x, y;
};
string map[310];
bool vis[310][310];
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int V, O;
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

void _bfs(int x,int y){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = x;
	temp1.y = y;
	vis[x][y] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y] && map[temp2.x][temp2.y] != '#'){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
			}
		}
	}
}

void bfs(int x, int y){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = x;
	temp1.y = y;
	vis[x][y] = 1;
	qn.push(temp1);
	int v = 0, o = 0;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (map[temp1.x][temp1.y] == 'v')
			v++;
		else if (map[temp1.x][temp1.y] == 'o')
			o++;
		for (int i = 0; i < 4; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y]&&map[temp2.x][temp2.y]!='#'){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
			}
		}
	}
	if (v != o){
		if (v>o)
			V += v;
		else
			O += o;
	}
}


void firstInit(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < map[0].length();++i)
	if (!vis[0][i] && map[0][i] != '#')
		_bfs(0, i);
	for (int i = 0; i < map[N-1].length(); ++i)
	if (!vis[N-1][i] && map[N-1][i] != '#')
		_bfs(N-1, i);
	for (int i = 0; i < N;++i)
	if (!vis[i][0] && map[i][0] != '#')
		_bfs(i, 0);
	for (int i = 0; i < N; ++i)
	if (!vis[i][M-1] && map[i][M-1] != '#')
		_bfs(i, M-1);
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		firstInit();
		V = O = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (!vis[i][j] && map[i][j] != '#')
			bfs(i, j);
		printf("%d %d\n",O, V);
	}
	return 0;
}