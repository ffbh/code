#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
	int jew;
	int value;
	int step;
}que[1300010];
int map[51][51];
bool vis[51][51][1050];
int value[20];
int N, M, K, num, sx, sy, ex, ey;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}

int bfs(){
	memset(vis, 0, sizeof(vis));
	//queue<Node> qn;
	Node temp1, temp2;
	int res = -1;
	temp1.x = sx;
	temp1.y = sy;
	temp1.jew = 0;
	temp1.value = 0;
	temp1.step = 0;
	vis[sx][sy][0] = 1;
	int f, tail;
	f = tail = 0;
	que[f++] = temp1;
	//qn.push(temp1);
	//while(!qn.empty()){
	while (tail<f){
		//temp1 = qn.front();
	//	qn.pop();
		if (que[tail].step > K){
			tail++;
			continue;
		}/////////////////
		if (que[tail].x == ex&&que[tail].y == ey){
			if (que[tail].value > res)
				res = que[tail].value;
		}
		que[tail].step++;
		for (int i = 0; i < 4; ++i){
			temp2 = que[tail];
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y][temp2.jew] && map[temp2.x][temp2.y] >= 0){
				vis[temp2.x][temp2.y][temp2.jew] = 1;
				if (map[temp2.x][temp2.y]){
					int jew = (1 <<( map[temp2.x][temp2.y]-1));
					if (!(temp2.jew&jew)){
						temp2.jew += jew;
						temp2.value += value[map[temp2.x][temp2.y]];
						vis[temp2.x][temp2.y][temp2.jew] = 1;
					}
				}
			//	qn.push(temp2);
				que[f++] = temp2;
			}
		}
		tail++;
	}
	return res;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	in >> T;
	int CASE = 1;
	while (T--){
		in >> M >> N >> K >> num;
		for (int i = 1; i <= num; ++i)
			in >> value[i];
		for (int i = 0; i < N; ++i){
			string temp;
			in >> temp;
			for (int j = 0; j < M;++j)
			if (temp[j] == '*')
				map[i][j] = -1;
			else if (temp[j] == '.')
				map[i][j] = 0;
			else if (temp[j] >= 'A'&&temp[j] <= 'J')
				map[i][j] = temp[j] - 'A'+1;
			else if (temp[j] == '@'){
				map[i][j] = 0;
				sx = i;
				sy = j;
			}
			else{
				map[i][j] = 0;
				ex = i;
				ey = j;
			}
		}
		int ans = bfs();
		printf("Case %d:\n", CASE++);
		if (ans < 0)
			cout << "Impossible" << endl;
		else
			printf("The best score is %d.\n", ans);
		cout << endl;
	}
	return 0;
}