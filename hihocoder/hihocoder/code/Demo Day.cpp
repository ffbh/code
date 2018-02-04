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
int N, M;
string mmp[110];

int ans[110][110][2];
bool vis[110][110][2];
int dirs[2][2] = { 1, 0, 0, 1 };
struct Node{
	int x, y, d;
	Node(int a, int b, int c){
		x = a;
		y = b;
		d = c;
	}
	Node(){}
};

bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

int spfa(){
	for (int i = 0; i < 110;++i)
	for (int j = 0; j < 110; ++j){
		ans[i][j][0] = ans[i][j][1] = (1 << 28);
		vis[i][j][0] = vis[i][j][1] = 0;
	}

	ans[0][0][1] = 0;
	vis[0][0][1] = 1;
	queue<Node> qn;
	qn.push(Node(0, 0, 1));
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		vis[u.x][u.y][u.d] = 0;
		if (u.x == N - 1 && u.y == M - 1){
			continue;
		}
		v.d = u.d;
		v.x = u.x + dirs[v.d][0];
		v.y = u.y + dirs[v.d][1];
		
		if (IN(v)){
			if (mmp[v.x][v.y] == '.'){
				if (IN(v) && ans[v.x][v.y][v.d] > ans[u.x][u.y][u.d]){
					ans[v.x][v.y][v.d] = ans[u.x][u.y][u.d];
					if (!vis[v.x][v.y][v.d]){
						vis[v.x][v.y][v.d] = 1;
						qn.push(v);
					}
				}

				v.d = 1 - v.d;
				v.x = u.x + dirs[v.d][0];
				v.y = u.y + dirs[v.d][1];
				int p = 0;
				if (IN(v) && mmp[v.x][v.y] != '.')
					p = 1;
				if (IN(v) && ans[v.x][v.y][v.d] > ans[u.x][u.y][u.d] + 1 + p){
					ans[v.x][v.y][v.d] = ans[u.x][u.y][u.d] + 1 + p;
					if (!vis[v.x][v.y][v.d]){
						vis[v.x][v.y][v.d] = 1;
						qn.push(v);
					}
				}
			}
			else{
				v.d = 1 - v.d;
				v.x = u.x + dirs[v.d][0];
				v.y = u.y + dirs[v.d][1];
				int p = 0;
				if (IN(v) && mmp[v.x][v.y] != '.')
					p = 1;
				if (IN(v) && ans[v.x][v.y][v.d] > ans[u.x][u.y][u.d]+p){
					ans[v.x][v.y][v.d] = ans[u.x][u.y][u.d]+p;
					if (!vis[v.x][v.y][v.d]){
						vis[v.x][v.y][v.d] = 1;
						qn.push(v);
					}
				}

				v.d = 1 - v.d;
				v.x = u.x + dirs[v.d][0];
				v.y = u.y + dirs[v.d][1];
				if (IN(v) && ans[v.x][v.y][v.d] > ans[u.x][u.y][u.d] + 1){
					ans[v.x][v.y][v.d] = ans[u.x][u.y][u.d] + 1;
					if (!vis[v.x][v.y][v.d]){
						vis[v.x][v.y][v.d] = 1;
						qn.push(v);
					}
				}
			}
		}
		else{
			v.d = 1 - v.d;
			v.x = u.x + dirs[v.d][0];
			v.y = u.y + dirs[v.d][1];
			int p = 0;
			if (IN(v) && mmp[v.x][v.y] != '.')
				p = 1;
			if (IN(v) && ans[v.x][v.y][v.d] > ans[u.x][u.y][u.d] + p){
				ans[v.x][v.y][v.d] = ans[u.x][u.y][u.d]+ p;
				if (!vis[v.x][v.y][v.d]){
					vis[v.x][v.y][v.d] = 1;
					qn.push(v);
				}
			}
		}
	}
	return min(ans[N - 1][M - 1][0], ans[N - 1][M - 1][1]);
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> mmp[i];


	cout << spfa() << endl;


	return 0;
}