#include <iostream>
#include <string>
#include <fstream>
#include<queue>
using namespace std;
int N, M;
int K, sx, sy, ex, ey;
struct Node{
	int x, y;
	int dirs;
	int time;
};
bool map[110][110];
int vis[110][110];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}
bool bfs(){
	queue<Node> qn;
	if (sx == ex&&sy == ey)return 1;
	Node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.dirs = -1;
	temp1.time = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.dirs != i){
				temp2.dirs = i;
				temp2.time++;
			}
			if (temp2.time>K+1)
				continue;
			if (temp2.x == ex&&temp2.y == ey)
				return 1;
			if (IN(temp2) && map[temp2.x][temp2.y] == 0 && vis[temp2.x][temp2.y]>=temp2.time){
				vis[temp2.x][temp2.y] = temp2.time;
				qn.push(temp2);
			}
		}
	}
	return 0;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	string s;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 0; i <= 100;++i)
		for (int j = 0; j <= 100; ++j)
			vis[i][j] = INT_MAX;
		for (int i = 1; i <= N; ++i){
			cin >> s;
			for (int j = 1; j <= M;++j)
			if (s[j - 1] == '.')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
		cin >> K >> sy >> sx >> ey >> ex;
		if (bfs())
			cout << "yes" << endl;
		else
			cout << "no" << endl;


	}
	return 0;
}