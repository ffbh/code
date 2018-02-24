#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int x, y, step;
	Node(int _x, int _y, int _step = 0){
		x = _x;
		y = _y;
		step = _step;
	}
	Node(){}
};
int N, M;
string map[20];
bool ok[20][20];
bool vis[20][20];
int ans[20][20];
int dept[20][20];
vector<Node> person, gate;

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

void Init(){
	person.clear();
	gate.clear();
	for (int i = 0; i < 20;++i)
	for (int j = 0; j < 20; ++j)
		ans[i][j] = 1 << 30;
}


void bfs(int x,int y){
	memset(vis, 0, sizeof(vis));
	memset(dept, 0, sizeof(dept));

	queue<Node> qn;
	qn.push(Node(x, y, 0));
	vis[x][y] = 1;
	int m_dept = 0;
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		for (int i = 0; i < 4; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			v.step = u.step + 1;
			if (IN(v)&&!vis[v.x][v.y]&&ok[v.x][v.y]){
				v.step += 
				vis[v.x][v.y] = 1;
				if (map[v.x][v.y] == 'X')
					m_dept++;
				if (v.step < m_dept)
					v.step = m_dept;
				if (map[v.x][v.y] == 'X'){
					if (v.step < ans[v.x][v.y]){
						ans[v.x][v.y] = v.step;
					}
				}
				qn.push(v);
			}
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	while (in >> N >> M){
		Init();
		for (int i = 0; i < N; ++i){
			in >> map[i];
			for (int j = 0; j < M; ++j){
				if (map[i][j] == '.')
					ok[i][j] = 1;
				else if (map[i][j] == 'X'){
					ok[i][j] = 1;
					person.push_back(Node(i, j));
				}
				else if (map[i][j] == '@'){
					ok[i][j] = 1;
					gate.push_back(Node(i, j));
				}
				else{
					ok[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < gate.size(); ++i){
			bfs(gate[i].x, gate[i].y);
		}

		int ret = 0;
		for (int i = 0; i < person.size(); ++i){
			ret = max(ret, ans[person[i].x][person[i].y]);
		}
		if (ret == 1 << 30)
			cout << -1 << endl;
		else
			cout << ret << endl;


	}
















	return 0;
}