#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N, M;
struct Node{
	int x, y, h;
	bool operator<(const Node& p)const{
		return h>p.h;
	}
};
int map[501][501];
bool vis[501][501];
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y<M;
}
int dirs[4][2] = { 1, 0, 0, 1, 0 ,- 1, -1, 0 };

int slove(){
	priority_queue<Node> qn;
	memset(vis, 0, sizeof(vis));
	Node temp;
	for (int i = 0; i < M; ++i){
		temp.y = i;
		temp.x = 0;
		if (!vis[temp.x][temp.y]){
			vis[temp.x][temp.y] = 1;
			temp.h = map[temp.x][temp.y];
			qn.push(temp);
		}
		temp.x = N - 1;
		if (!vis[temp.x][temp.y]){
			vis[temp.x][temp.y] = 1;
			temp.h = map[temp.x][temp.y];
			qn.push(temp);
		}
	}
	for (int i = 0; i < N; ++i){
		temp.x = i;
		temp.y = 0;
		if (!vis[temp.x][temp.y]){
			vis[temp.x][temp.y] = 1;
			temp.h = map[temp.x][temp.y];
			qn.push(temp);
		}
		temp.y = M - 1;
		if (!vis[temp.x][temp.y]){
			vis[temp.x][temp.y] = 1;
			temp.h = map[temp.x][temp.y];
			qn.push(temp);
		}
	}
	int res = 0;
	while (!qn.empty()){
		temp = qn.top();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			int x, y, h;
			x = temp.x + dirs[i][0];
			y = temp.y + dirs[i][1];
			h = temp.h;
			if (IN(x,y)&&!vis[x][y]){
				vis[x][y] = 1;
				if (map[x][y] < temp.h)
					res += (temp.h - map[x][y]);
				else
					h = map[x][y];
				qn.push(Node{ x, y, h });
			}
		}
	}
	return res;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
			cin >> map[i][j];
		cout << slove() << endl;
	}
	return 0;
}