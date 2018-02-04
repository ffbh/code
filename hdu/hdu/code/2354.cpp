#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N, M;
struct Node{
	int x, y;
};
char map[30][30];
bool vis[30][30];
int dist[30][30];
bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}
int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1,0 };

int spfa(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 30; ++i)
	for (int j = 0; j < 30; ++j)
		dist[i][j] = INT_MAX;
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = 1;
	for (int i = 1; i <= M; ++i){
		dist[1][i] = 1;
		temp1.y = i;
		vis[1][i] = 1;
		qn.push(temp1);
	}
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		dist[0][0] = 1;
		vis[temp1.x][temp1.y] = 0;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2)){
				if (map[temp2.x][temp2.y] == map[temp1.x][temp1.y]){
					if (dist[temp2.x][temp2.y]>dist[temp1.x][temp1.y]){
						dist[temp2.x][temp2.y] = dist[temp1.x][temp1.y];
						if (!vis[temp2.x][temp2.y]){
							vis[temp2.x][temp2.y] = 1;
							qn.push(temp2);
						}
					}
				}
				else{
					if (dist[temp2.x][temp2.y] > dist[temp1.x][temp1.y] + 1){
						dist[temp2.x][temp2.y] = dist[temp1.x][temp1.y] + 1;
						if (!vis[temp2.x][temp2.y]){
							vis[temp2.x][temp2.y] = 1;
							qn.push(temp2);
						}
					}
				}
			}
		}
	}
	int mmin = INT_MAX;
	for (int i = 1; i <= M; ++i)
	if (dist[N][i] < mmin)
		mmin = dist[N][i];
	return mmin;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < s.length(); ++j)
				map[i][j + 1] = s[j];
		}
		cout << spfa() << endl;
	}
	return 0;
}