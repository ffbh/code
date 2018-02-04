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
string mmp[510];
int d[510][510][4];
bool vis[510][510][4];
int N, M;
int sx, sy, ex, ey;

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
struct Node{
	int x, y, d;
	Node(int a,int b,int c){
		x = a;
		y = b;
		d = c;
	}
	Node(){}
};

bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M&&mmp[p.x][p.y] != '#';
}


int spfa(){
	for (int i = 0; i < 510; ++i)
	for (int j = 0; j < 510; ++j)
	for (int k = 0; k < 4; ++k)
		d[i][j][k] = (1 << 29);
	for (int i = 0; i < 4; ++i)
		d[sx][sy][i] = 0;
	queue<Node> qn;
	for (int i = 0; i < 4;++i)
		qn.push(Node(sx, sy,i));
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		vis[u.x][u.y][u.d] = 0;
		if (u.x == 1 && u.y == 4 && u.d == 2){
			int t = 0;
		}
		v.x = u.x + dirs[u.d][0];
		v.y = u.y + dirs[u.d][1];
		v.d = u.d;
		

		if (IN(v)){
			if (d[v.x][v.y][v.d] > d[u.x][u.y][u.d]){
				d[v.x][v.y][v.d] = d[u.x][u.y][u.d];
				if (!vis[v.x][v.y][v.d]){
					vis[v.x][v.y][v.d] = 1;
					qn.push(v);
				}
			}
		}
		else{
			v = u;
			
			v.d = (u.d + 1) % 4;
			if (d[v.x][v.y][v.d] > d[u.x][u.y][u.d] +1){
				d[v.x][v.y][v.d] = d[u.x][u.y][u.d] +1;
				if (!vis[v.x][v.y][v.d]){
					vis[v.x][v.y][v.d] = 1;
					qn.push(v);
				}
			}
			
			v.d = (u.d + 3) % 4;
			if (d[v.x][v.y][v.d] > d[u.x][u.y][u.d] + 1){
				d[v.x][v.y][v.d] = d[u.x][u.y][u.d] + 1;

				if (!vis[v.x][v.y][v.d]){
					vis[v.x][v.y][v.d] = 1;
					qn.push(v);
				}
			}


		}


	}
	int ans = 1 << 29;
	for (int i = 0; i < 4; ++i)
		ans = min(ans,d[ex][ey][i]);
	return ans;

}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	
	in >> N >> M;
	for (int i = 0; i < N; ++i){
		in >> mmp[i];
		for (int j = 0; j < M; ++j){
			if (mmp[i][j] == 'S'){
				sx = i;
				sy = j;

			}
			if (mmp[i][j] == 'T'){
				ex = i;
				ey = j;
			}
		}
	}

	int ans = spfa();
	if (ans == (1 << 29))
		cout << -1 << endl;
	else{
		cout << ans << endl;
	}















	return 0;
}