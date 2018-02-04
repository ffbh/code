#include <iostream>
#include <cstring>
#include <string> 
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
	int x, y;
};
int map[50][50], N, M, size;
int vis[50][50];
bool mark[2010];
int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
vector<int> vi[2010];
bool IN(const Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}
void pre_bfs(int x,int y,int f){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = x;
	temp1.y = y;
	vis[x][y] = f;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && map[temp1.x][temp1.y] == map[temp2.x][temp2.y]&&!vis[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = f;
				qn.push(temp2);
			}
		}
	}
}

void Build_Map(){
	for (int i = 1; i < size; ++i)
		vi[i].clear();
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M;++j)
	for (int k = 0; k < 4; ++k){
		int tx = i + dirs[k][0];
		int ty = j + dirs[k][1];
		if (vis[tx][ty] != vis[i][j] && IN(Node{ tx, ty })){
			vi[vis[tx][ty]].push_back(vis[i][j]);
			vi[vis[i][j]].push_back(vis[tx][ty]);
		}
	}
}
struct BFS{
	int now, step;
};

int bfs(int s){
	queue<BFS> qn;
	memset(mark, 0, sizeof(mark));
	BFS temp;
	temp.now = s;
	temp.step = 0;
	mark[s] = 1;
	qn.push(temp);
	int ans = 0;
	while (!qn.empty()){
		temp = qn.front();
		qn.pop();
		if (temp.step > ans)
			ans = temp.step;
		for (int i = 0; i < vi[temp.now].size(); ++i){
			int son = vi[temp.now][i];
			if (mark[son])
				continue;
			mark[son] = 1;
			qn.push(BFS{ son, temp.step + 1 });
		}
	}
	return ans;
}


int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		size = 1;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M;++j)
			if (s[j] == 'X')
				map[i][j + 1] = 1;
			else
				map[i][j + 1] = 0;
		}
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M;++j)
		if (!vis[i][j])
			pre_bfs(i, j, size++);
		Build_Map();
		int ans = 9999999;
		for (int i = 1; i < size; ++i){
			int ret = bfs(i);
			if (ret < ans)
				ans = ret;
		}
		cout << ans << endl;
	}



	return 0;
}