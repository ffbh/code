#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ofstream on("C:\\temp2.txt");
int N, M;
struct Point{
	int x, y;
};
vector<Point> vtemp;

struct Node{
	int lx, ly, rx, ry;
	int time;
	bool rmove;
	bool operator<(const Node& p)const{
		return time > p.time;
	}
}sta;
priority_queue<Node> qn;
bool vis[61][61][61][61];
int map[70][70];
bool ok[70][70];
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}
int ans;
int dirs[9][2] = { 0, 1, 0, 2, 0, 3, 1, 1, 2, 1, -1, 1, -2, 1, 1, 2, -1,2 };
void Push(){
	memset(vis, 0, sizeof(vis));
	sta.time = 0;
	for (int u = 0; u < vtemp.size(); ++u){
		sta.lx = sta.rx = vtemp[u].x;
		sta.ly = sta.ry = vtemp[u].y;
		vis[sta.lx][sta.ly][sta.rx][sta.ry] = 1;
		vis[sta.lx][sta.ly][sta.rx][sta.ry] = 1;
		sta.rmove = 0;
		qn.push(sta);
		sta.rmove = 1;
		qn.push(sta);
	}
}

void bfs(){
	Node temp1, temp2;
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();
  		if (temp1.time > ans)
			continue;
		if (ok[temp1.lx][temp1.ly]||ok[temp1.rx][temp1.ry]){
			if (temp1.time < ans){
				ans = temp1.time;
			}
			return;
		}
		for (int i = 0; i < 9; ++i){
			if (temp1.rmove){
				temp2.time = temp1.time;
				temp2.lx = temp1.lx;
				temp2.ly = temp1.ly;
				temp2.rx = temp2.lx + dirs[i][0];
				temp2.ry = temp2.ly + dirs[i][1];
				temp2.rmove = 0;
				if (IN(temp2.rx, temp2.ry) && map[temp2.rx][temp2.ry] >= 0
					&&!vis[temp2.lx][temp2.ly][temp2.rx][temp2.ry]){
					vis[temp2.lx][temp2.ly][temp2.rx][temp2.ry] = 1;
					temp2.time += map[temp2.rx][temp2.ry];
					qn.push(temp2);
				}
			}
			else{
				temp2.time = temp1.time;
				temp2.rx = temp1.rx;
				temp2.ry = temp1.ry;
				temp2.lx = temp2.rx - dirs[i][0];
				temp2.ly = temp2.ry - dirs[i][1];
				temp2.rmove = 1;
				if (IN(temp2.lx, temp2.ly) && map[temp2.lx][temp2.ly] >= 0
					&& !vis[temp2.lx][temp2.ly][temp2.rx][temp2.ry]){
					vis[temp2.lx][temp2.ly][temp2.rx][temp2.ry] = 1;
					temp2.time += map[temp2.lx][temp2.ly];
					qn.push(temp2);
				}
			}
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> M>>N&&N + M){
		vtemp.clear();
		while (!qn.empty())
			qn.pop();
		ans = INT_MAX;
		memset(ok, 0,sizeof(ok));
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
			char c;
			cin >> c;
			if (c == 'X')
				map[i][j] = -1;
			else if (c == 'T'){
				map[i][j] = 0;
				ok[i][j] = 1;
			}
			else if (c >= '1'&&c <= '9')
				map[i][j] = c - '0';
			else{
				vtemp.push_back(Point{ i, j });
				map[i][j] = 0;
			}
		}
		Push();
		bfs();
		if (ans == INT_MAX)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}