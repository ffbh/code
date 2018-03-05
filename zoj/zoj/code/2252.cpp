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
#include <set>
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int N, M, sx, sy, ex, ey;
LL mmp[30][30];
void input(){
//	in >> M >> N;
	in >> sx >> sy >> ex >> ey;
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M; ++j)
		in >> mmp[i][j];


}

int dirs[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
#define INF ((LL)1e18)
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M&&mmp[x][y] != -1;
}
struct Node{
	int m, x, y;
};
LL d[4][30][30];
void bfs(){
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 30;++j)
	for (int k = 0; k < 30; ++k)
		d[i][j][k] = INF;
	Node S;
	S.m = mmp[sx][sy] % 4;
	S.x = sx;
	S.y = sy;
	d[S.m][sx][sy] = mmp[sx][sy];
	queue<Node> Q;
	Q.push(S);
	while (!Q.empty()){
		Node u = Q.front(), v;
		Q.pop();
	//	cout << u.m << " " << u.x << " " << u.y << endl;
		v.x = u.x;
		v.y = u.y;

		if (IN(v.x, v.y)){
			v.m = (u.m + 1) % 4;
			if (d[v.m][v.x][v.y] > d[u.m][u.x][u.y] + 1 ){
				d[v.m][v.x][v.y] = d[u.m][u.x][u.y] + 1 ;
				Q.push(v);
			}
		}
		
		v.x = u.x + dirs[u.m][0];
		v.y = u.y + dirs[u.m][1];
		if (IN(v.x, v.y)){
			v.m = (u.m + 1 + mmp[v.x][v.y]) % 4;
			if (d[v.m][v.x][v.y] > d[u.m][u.x][u.y] + 1 + mmp[v.x][v.y]){
				d[v.m][v.x][v.y] = d[u.m][u.x][u.y] + 1 + mmp[v.x][v.y];
				Q.push(v);
			}
		}
	}


}

int main(){

	while (in >> M >> N){
		input();
		bfs();
		LL ans = INF;
		for (int i = 0; i < 4; ++i)
			ans = min(ans, d[i][ex][ey]);
		if (ans == INF){
			printf("%d\n", -1);
		}
		else{
			printf("%lld\n", ans - mmp[ex][ey]);
		}




	}











	return 0;
}





