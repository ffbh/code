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
int N, A, B, C;
char color[51][51];
bool vis[51][51][51];
struct Node{
	int data[3], step;
	Node(){}
	Node(int _a, int _b, int _c){
		data[0] = _a;
		data[1] = _b;
		data[2] = _c;
		Sort();
		step = 0;
	}
	bool ok(){
		return data[0] == data[1]&&data[1] == data[2];
	}

	void mark(){
		vis[data[0]][data[1]][data[2]] = 1;
	}
	bool canMove(){
		return vis[data[0]][data[1]][data[2]] == 0;
	}
	void Sort(){
		sort(data, data + 3);
	}
};

int bfs(){
	queue<Node> qn;
	memset(vis, 0, sizeof(vis));
	Node start(A, B, C);
	start.mark();
	qn.push(start);
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		if (u.ok())
			return u.step;
		for (int k = 0; k < 3; ++k){
			for (int i = 1; i <= N; ++i){
				if (color[u.data[k]][i] == color[u.data[(k + 1) % 3]][u.data[(k + 2) % 3]]){
					v = u;
					v.data[k] = i;
					v.Sort();
					/*	if (v.canMove()){
							v.step++;
							v.mark();
							qn.push(v);
							}*/
					if (!vis[v.data[0]][v.data[1]][v.data[2]]){
						v.step++;
						vis[v.data[0]][v.data[1]][v.data[2]] = 1;
						qn.push(v);
					}
				}
			}
		}

	

		
	}

	return -1;
}


int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N&&N){
		cin >> A >> B >> C;
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> color[i][j];

		int ret = bfs();
		if (ret == -1)
			cout << "impossible" << endl;
		else
			cout << ret << endl;
	}

	return 0;
}