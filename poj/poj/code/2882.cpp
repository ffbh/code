#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int x, y, z;
};
bool vis[110][110][110];
int dirs[6][3] = { 
	0, 0, 1,
	0, 1, 0,
	1, 0, 0,
	0, 0, -1,
	0, -1, 0,
	- 1, 0, 0 };
int maxx, maxy, maxz, minx, miny, minz;
bool IN(Node& p){
	return p.x >= minx&&p.x <= maxx&&p.y >= miny&&p.y <= maxy&&p.z >= minz&&p.z <= maxz;
}

void bfs(int x,int y,int z){
	queue<Node> qn;
	Node u;
	u.x = x;
	u.y = y;
	u.z = z;
	vis[x][y][z] = 1;
	qn.push(u);
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		for (int i = 0; i < 6; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			v.z = u.z + dirs[i][2];
			if (IN(v)&&!vis[v.x][v.y][v.z]){
				vis[v.x][v.y][v.z] = 1;
				qn.push(v);
			}
		}
	}


}



int main(){
	ifstream in("C:\\input.txt");
	int T, M, ans;
	in >> T;
	while (T--){
		maxx = maxy = maxz = 0;
		minx = miny = minz = 100;
		memset(vis, 0, sizeof(vis));
		in >> M;
		ans = 0;
		while (M--){
			int x, y, z;
			in >> x >> y >> z;
			if (x > maxx)
				maxx = x;
			if (y > maxy)
				maxy = y;
			if (z > maxz)
				maxz = z;
			if (x < minx)
				minx = x;
			if (y < miny)
				miny = y;
			if (z < minz)
				minz = z;
			
			vis[x][y][z] = 1;
			
		}
		for (int i = minx; i <= maxx;++i)
		for (int j = miny; j <= maxy; ++j){
			if (!vis[i][j][minz]){
				bfs(i, j, minz);
			}
			if (i == 2 && j == 2 ){
				int t = 0;
			}
			if (!vis[i][j][maxz]){
				bfs(i, j, maxz);
			}
		}

		for (int i = minx; i <= maxx;++i)
		for (int j = minz; j <= maxz; ++j){
			if (!vis[i][miny][j]){
				bfs(i, miny, j);
			}
			if (!vis[i][maxy][j]){
				bfs(i, maxy, j);
			}

		}

		for (int i = miny; i <= maxy;++i)
		for (int j = minz; j <= maxz; ++j){
			if (!vis[minx][ i][ j]){
				bfs(minx, i, j);
			}
			if (!vis[maxx][ i][ j]){
				bfs(maxx, i, j);
			}
		}

		for (int i = minx; i <= maxx;++i)
		for (int j = miny; j <= maxy;++j)
		for (int k = minz; k <= maxz; ++k){
			if (!vis[i][j][k]){
				ans++;
				bfs(i, j, k);
			}

		}
		cout << ans << endl;



	}
















	return 0;
}