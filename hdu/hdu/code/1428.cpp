#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
#define INF (99999999)
int N;
struct Node{
	int x, y;
};
int map[51][51];
bool vis[51][51];
int dp[51][51];
_int64 ans[51][51];
bool IN(const Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < N;
}

int dirs[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };

void bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = temp1.y = N - 1;
	dp[N - 1][N - 1] = 0;
	qn.push(temp1);
	vis[N - 1][N - 1] = 1;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		vis[temp1.x][temp1.y] = 0;
		for (int i = 0; i < 4; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2)){
				int tempV = dp[temp1.x][temp1.y] + map[temp2.x][temp2.y];
				if (dp[temp2.x][temp2.y] > tempV){
					dp[temp2.x][temp2.y] = tempV;
					if (!vis[temp2.x][temp2.y]){
						vis[temp2.x][temp2.y] = 1;
						qn.push(temp2);
					}
				}
			}
		}
	}
}

_int64 DFS(int x, int y){
	if (x == N - 1 && y == N - 1)
		return 1;
	if (ans[x][y] != -1)
		return ans[x][y];
	ans[x][y] = 0;
	Node temp;
	for (int i = 0; i < 4; ++i){
		temp.x = x + dirs[i][0];
		temp.y = y + dirs[i][1];
		if (IN(temp) && dp[temp.x][temp.y] < dp[x][y])
			ans[x][y] += DFS(temp.x, temp.y);
	}
	return ans[x][y];
}


int main(){
	//    ifstream in("C:\\temp.txt");
	while (cin >> N){
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			dp[i][j] = INF;
			ans[i][j] = -1;
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			//    in >> map[i][j];
			scanf("%d", &map[i][j]);
		bfs();
		cout << DFS(0, 0) << endl;
	}
	return 0;
}
