#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int dist[510][510];
struct Node{
	int x, y;
	int  step;
	bool monster[30];
};
struct Map{
	bool monster[30];
	int trap;
}map[510][510];
bool vis[510][510];

int sx, sy, ex, ey;
int N, M;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int ans1, ans2;
bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}


void  spfa(){
	queue<Node> qn;
	Node temp1, temp2;
	for (int i = 0; i < 510;++i)
	for (int j = 0; j < 510; ++j)
		dist[i][j] = (1 << 29);
	temp1.x = sx;
	temp1.y = sy;
	temp1.step = 0;
	memset(temp1.monster, 0, sizeof(temp1.monster));
	qn.push(temp1);
	vis[temp1.x][temp1.y] = 1;
	dist[sx][sy] = 0;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		vis[temp1.x][temp1.y] = 0;
		if (temp1.x == ex&&temp1.y == ey){
			if (dist[temp1.x][temp1.y] < ans1){
				ans1 = dist[temp1.x][temp1.y];
				ans2 = temp1.step;
			}
			else if (dist[temp1.x][temp1.y] == ans1&&temp1.step < ans2)
				ans2 = temp1.step;
			continue;
		}
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y]){
				int sumkill = dist[temp1.x][temp1.y] + map[temp2.x][temp2.y].trap;
				for (int i = 1; i <= 26;++i)
				if (map[temp2.x][temp2.y].monster[i] && !temp2.monster[i]){
					temp2.monster[i] = 1;
					sumkill += i;
				}
				if (sumkill < dist[temp2.x][temp2.y]){
					dist[temp2.x][temp2.y] = sumkill;
					if (!vis[temp2.x][temp2.y]){
						vis[temp2.x][temp2.y];
						qn.push(temp2);
					}
				}
			}
		}
	}
}





int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(vis, 0, sizeof(vis));
		ans1 = ans2 = 99999999;
		cin >> N >> M;
		cin >> sx >> sy >> ex >> ey;
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			for(int j=0;j<M;++j)
			if (s[j] != '.'){
				if (s[j] == '#')
					vis[i][j + 1] = 1;
				else if (s[j] >= 'a'&&s[j] <= 'z')
					map[i][j+1].trap += s[j] - 'a'+1;
				else{
					int nextx, nexty;
					map[i][j+1].monster[s[j] - 'A' + 1] = 1;
					for (int k = 0; k < 4; ++k){
						nextx = i + dirs[k][0];
						nexty = j + 1 + dirs[k][1];
						map[nextx][nexty].monster[s[j] - 'A'+1] = 1;
					}
				}
			}
		}
		spfa();
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}