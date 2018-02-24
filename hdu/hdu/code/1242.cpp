#include <iostream>
#include <string>
#include <queue>
//#include <fstream>
#include <cmath>
using namespace std;
int N, M;
int map[210][210];
bool vis[210][210];
int sx, sy, ex, ey;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
struct node{
	int x, y;
	int f;
	int step;
	bool operator<(const node& p)const{
		return f>p.f;
	}
};

int getT(const node& p){
	return abs(ex - p.x) + abs(ey - p.y);
}
bool IN(const node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

int bfs(){
	priority_queue<node> pn;
	node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.step = 0;
	pn.push(temp1);
	vis[temp1.x][temp1.y] = 1;
	while (!pn.empty()){
		temp1 = pn.top();
		pn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.x == ex&&temp2.y == ey)
				return temp2.step + 1;
			if (IN(temp2) && !vis[temp2.x][temp2.y]&&map[temp2.x][temp2.y]!=0){
				vis[temp2.x][temp2.y] = 1;
				temp2.step += map[temp2.x][temp2.y];
				temp2.f = temp2.step + getT(temp2);
				pn.push(temp2);
			}
		}
	}
	return -1;

}

int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> N >> M){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int k = 0; k < M; ++k)
			if (s[k] == '.')
				map[i][k] = 1;
			else if (s[k] == '#')
				map[i][k] = 0;
			else if (s[k] == 'x')
				map[i][k] = 2;
			else if (s[k] == 'a'){
				ex = i;
				ey = k;
				map[i][k] = 1;
			}
			else{
				sx = i;
				sy = k;
				map[i][k] = 1;
			}
		}//for
		int ans = bfs();
		if (ans == -1)
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		else
			cout << ans << endl;





	}//while

	return 0;
}