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
	int x, y, d;
	Node(int a, int b, int c){
		x = a;
		y = b;
		d = c;
	}
	Node(){}
};
int dirs[5][2] = { 1, 0, 0, 1, -1, 0, 0, -1,0,0 };
string mmp[40];
bool vis[40][40][40];
bool b[40][40][40];
int tim[40][40][40];

int N, M;
int sx, sy;

bool IN(Node& p){
	return p.x >= 0 && p.x < N;
}

int spfa(){
	for (int i = 0; i < 40;++i)
	for (int j = 0; j < 40;++j)
	for (int k = 0; k < 40; ++k){
		tim[i][j][k] = (1 << 29);
	}

	tim[sx][sy][0] = 0;

	queue<Node> qn;
	qn.push(Node(sx, sy, 0));
	vis[sx][sy][0] = 1;
	int ans = 1 << 29;
	while (!qn.empty()){
		Node u = qn.front(),v;
		
		qn.pop();
		vis[u.x][u.y][u.d] = 0;
		if (mmp[u.x][u.y] == '~'){
			ans = min(ans, tim[u.x][u.y][u.d]);
			continue;
		}
		for (int i = 0; i < 5; ++i){
			v.x = u.x + dirs[i][0];
			v.y = (u.y + dirs[i][1] + M) % M;
			v.d = (u.d + 1) % M;
			if (IN(v) && mmp[v.x][v.y] != 'T' && !b[v.x][v.y][v.d]){
				int spend = (mmp[u.x][u.y] != '.');
				if (tim[v.x][v.y][v.d] > tim[u.x][u.y][u.d] + spend){
					tim[v.x][v.y][v.d] = tim[u.x][u.y][u.d] + spend;
					if (!vis[v.x][v.y][v.d]){
						vis[v.x][v.y][v.d] = 1;
						qn.push(v);
					}
				}
			}
		}
	}

	return ans;
}


void Init(){
	memset(vis, 0, sizeof(vis));
	memset(b, 0, sizeof(b));
}

void  build(int x,int y,int dir){
	for (int i = 0; i < M; ++i){
		b[x][(y + i*dir + M) % M][i] = 1;
	//	cout << x << " " << (y + i*dir + M) % M << " " << i << endl;
	}
}

int main(){
	ifstream in("C:\\input.txt");
//	istream& in = cin;
	int T;
	in >> T;
	while (T-- > 0){
		Init();
		in >> N >> M;
		for (int i = 0; i < N; ++i){
			in >> mmp[i];
			for (int j = 0; j < M; ++j){
				if (mmp[i][j] == '&'){
					sx = i;
					sy = j;
				}
				else if (mmp[i][j] == '<'){
					build(i, j, -1);
				}
				else if (mmp[i][j] == '>'){
					build(i, j, 1);
				}
			}
		}

		int ans = spfa();
		if (ans == 1 << 29)
			cout << "Impassable" << endl;
		else
			cout << ans << endl;



	}




	return 0;
}