#include <iostream>
#include <string>
//#include <fstream>
#include <queue>
using namespace std;
int N, M;
bool map[110][110];
bool vis[110][110];
struct Point{
	int x, y;
};

bool IN(const Point& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};


bool bfs(const Point& p){
	if (map[p.x][p.y] == 0||vis[p.x][p.y])return 0;
	vis[p.x][p.y] = 1;
	queue<Point> qp;
	qp.push(p);
	Point P, Q;
	while (!qp.empty()){
		P = qp.front();
		qp.pop();
		for (int i = 0; i < 8; ++i){
			Q = P;
			Q.x += dir[i][0];
			Q.y += dir[i][1];
			if (IN(Q) && map[Q.x][Q.y] == 1 && !vis[Q.x][Q.y]){
				vis[Q.x][Q.y] = 1;
				qp.push(Q);
			}
		}
	}//while
	return 1;
}
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> N >> M&&N&&M){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < M;++j)
			if (s[j] == '*')
				map[i][j] = 0;
			else map[i][j] = 1;
		}
		int ans = 0;
		Point pp;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
			pp.x = i;
			pp.y = j;
			if (bfs(pp))
				ans++;
		}
		cout << ans << endl;
		


	
	}//while






	return 0;
}