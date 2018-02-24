#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 9999999.0
int N;
struct Point{
	double x, y;
};
struct Map{
	double dist;
	int mstep;
};
Map dp[103];
Point data[103];
bool vis[103];
double map[103][103];
double getDist(Point& A, Point& B){
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

void spfa(){
	memset(vis, 0, sizeof(vis));
	queue<int> qi;
	qi.push(0);
	vis[0] = 1;
	dp[0].dist = 0;
	dp[0].mstep = 0;
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		vis[temp] = 0;
		for (int i = 1; i <= N + 1; ++i)
		if (temp != i&&map[temp][i] < INF&&dp[i].mstep >= dp[temp].mstep + 1){
			if (dp[i].mstep > dp[temp].mstep + 1){
				dp[i].mstep = dp[temp].mstep + 1;
				dp[i].dist = dp[temp].dist + map[temp][i];
				if (!vis[i]){
					vis[i] = 1;
					qi.push(i);
				}
			}
			else
			if (dp[i].dist > dp[temp].dist + map[temp][i]){
				dp[i].dist = dp[temp].dist + map[temp][i];
				if (!vis[i]){
					vis[i] = 1;
					qi.push(i);
				}
			}
		}
	}
}




int main(){
	ifstream in("C:\\temp.txt");
	double K;
	Point S;
	S.x = S.y = 0;
	while (cin >> N >> K){
		for (int i = 0; i <= N + 1; ++i)
		for (int j = 0; j <= N + 1; ++j){
			dp[i].dist = INF;
			dp[i].mstep = 99999;
		}
		for (int i = 0; i <= N + 1; ++i)
		for (int j = 0; j <= N + 1; ++j)
			map[i][j] = INF;
		for (int i = 1; i <= N; ++i)
			cin >> data[i].x >> data[i].y;
		if (K >= 42.5){
			printf("42.50 1\n");
			continue;
		}
		for (int i = 1; i <= N; ++i){
			double D = getDist(S, data[i]);
			if (D - 7.5 <= K)
				map[0][i] = D - 7.5;
		}
		bool flag = 0;
		for (int i = 1; i <= N; ++i){
			double D = min(fabs(50 - fabs(data[i].x)), fabs(50 - fabs(data[i].y)));
			if (D <= K){
				map[i][N + 1] = D;
				flag = 1;
			}
		}
		for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j){
			double D = getDist(data[i], data[j]);
			if (D <= K)
				map[i][j] = map[j][i] = D;
		}
		if (flag)
			spfa();
		if (dp[N + 1].dist == INF || dp[N + 1].mstep>1000)
			cout << "can't be saved" << endl;
		else
			printf("%.2f %d\n", dp[N + 1].dist, dp[N + 1].mstep);
	}
	return 0;
}