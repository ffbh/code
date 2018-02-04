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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
#define DEBUG (0)

struct Node{
	int x, y;
	Node(int a, int b){
		x = a;
		y = b;
	}
	Node(){}
};
int N, M;
bool gp[60][60];
struct Ans{
	int a, b;
}data[60][60];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int sx, sy, ex, ey;

bool vis[60][60];

bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}
class ForestGarbage {
public:
	vector <int> bestWay(vector <string> mmp) {
		memset(gp, 0, sizeof(gp));
		N = mmp.size();
		M = mmp[0].size();

		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			if (mmp[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			else if (mmp[i][j] == 'F'){
				ex = i;
				ey = j;
			}

			bool ok = 0;
			if (mmp[i][j] == '.'){
				for (int k = 0; k < 4; ++k){
					int nx = i + dirs[k][0];
					int ny = j + dirs[k][1];
					if (IN(nx, ny) && mmp[nx][ny] == 'g'){
						ok = 1;
						break;
					}
				}
			}
			gp[i][j] = ok;
		}

		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			data[i][j].a = data[i][j].b = (1 << 29);

		data[sx][sy].a = data[sx][sy].b = 0;

		queue<Node> qn;
		vis[sx][sy] = 1;
		qn.push(Node(sx, sy));
		while (!qn.empty()){
			Node u = qn.front(), v;
			vis[u.x][u.y] = 0;
			qn.pop();
			for (int i = 0; i < 4; ++i){
				v.x = u.x + dirs[i][0];
				v.y = u.y + dirs[i][1];
				if (IN(v)){
					int a = data[u.x][u.y].a;
					int b = data[u.x][u.y].b;
					if (mmp[v.x][v.y] == 'g')
						a++;
					if (gp[v.x][v.y])
						b++;
					if (a < data[v.x][v.y].a || (a == data[v.x][v.y].a&&b < data[v.x][v.y].b)){
						data[v.x][v.y].a = a;
						data[v.x][v.y].b = b;
						if (!vis[v.x][v.y]){
							vis[v.x][v.y] = 1;
							qn.push(v);
						}

					}
				}

			}


		}
		vector<int> ans(2, 0);
		ans[0] = data[ex][ey].a;
		ans[1] = data[ex][ey].b;
		return ans;

	}
};


#if 0
int main(){
	vector<string> p({ { "........", "g..g...g", "........", ".g...g..", "..g.g..S", ".F.g....", "......g." } });
	ForestGarbage so;
	vector<int> k = so.bestWay(p);
	cout << k[0] << "  " << k[1] << endl;















	return 0;
}
#endif

