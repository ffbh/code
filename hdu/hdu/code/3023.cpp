#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
string map[1010];
bool vis[1010][1010];
int N, M;
int sx, sy, ex, ey;
struct Node{
	int x, y;
};
int dirs[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1 ,1,1,-1,-1,1,-1,-1,1};
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;

}
struct Dp{
	int minchange, step;
}dp[1010][1010];


void spfa(){
	queue<Node> qn;
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M; ++j)
		dp[i][j].minchange = dp[i][j].step = 99999999;
	memset(vis, 0, sizeof(vis));
	Node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	qn.push(temp1);
	dp[sx][sy].minchange = dp[sx][sy].step = 0;
	vis[sx][sy] = 1;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		vis[temp1.x][temp1.y] = 0;
		for (int i = 0; i < 8; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && map[temp2.x][temp2.y]!='0'){
				int minchange = dp[temp1.x][temp1.y].minchange;
				if (map[temp1.x][temp1.y] != map[temp2.x][temp2.y])
					minchange++;
				int step = dp[temp1.x][temp1.y].step + 1;
				if (minchange < dp[temp2.x][temp2.y].minchange || minchange == dp[temp2.x][temp2.y].minchange
					&&step < dp[temp2.x][temp2.y].step){
					dp[temp2.x][temp2.y].minchange = minchange;
					dp[temp2.x][temp2.y].step = step;
					if (!vis[temp2.x][temp2.y]){
						vis[temp2.x][temp2.y] = 1;
						qn.push(temp2);
					}
				}
			}
		}
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		cin >> sx >> sy >> ex >> ey;
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		sx--;
		sy--;
		ex--;
		ey--;
		spfa();
		printf("%d %d\n",  dp[ex][ey].step+1,dp[ex][ey].minchange);



	}







	return 0;
}