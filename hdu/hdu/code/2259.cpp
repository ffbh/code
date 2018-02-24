#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int N, M;
struct Node{
	int x, y;
	int c;
};
int map[21][21];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M&&map[p.x][p.y] == p.c;
}
int _dfs(int x, int y, int c){
	map[x][y] = 0;
	int res = 1;
	for (int i = 0; i < 4; ++i){
		int tx, ty;
		tx = x + dirs[i][0];
		ty = y + dirs[i][1];
		if (IN(Node{ tx, ty, c }))
			res += _dfs(tx, ty, c);
	}
	return res;
}


void Init(vector<Node>& v){
	int temp[21][21];
	memcpy(temp, map, sizeof(map));
	int m = 2;
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j)
	if (map[i][j]){
		int k = _dfs(i, j, map[i][j]);
		if (k>m){
			m = k;
			v.clear();
			v.push_back(Node{ i, j, temp[i][j] });
		}
		else if (k == m)
			v.push_back(Node{ i, j, temp[i][j] });
		
	}
	memcpy(map, temp, sizeof(map));
}

void drop(){
	int t[21][21];
	memcpy(t, map, sizeof(map));
	memset(map, 0, sizeof(map));
	for (int k = 0; k < M; ++k){
		int index = N - 1;
		for (int j = N - 1; j >= 0; --j)
		if (t[j][k])
			map[index--][k] = t[j][k];
	}
}

bool leftmove(){
	int u, s;
	for (u = 0; u < M; ++u)
	if (map[N - 1][u] == 0)
		break;
	if (u >= M)
		return 0;
	for (s = u; s < M; ++s)
	if (map[N - 1][s])
		break;
	if (s >= M)
		return 0;
	for (int j = 0; j < N; ++j){
		int tu, ts;
		tu = u;
		ts = s;
		while (ts < M){
			map[j][tu] = map[j][ts];
			map[j][ts] = 0;
			tu++;
			ts++;
		}
	}
	return 1;
}
int MAX;
struct Point{
	int x, y;
};
vector<Point> ans;
vector<Point> tem;
void dfs(int now){
	int temp[21][21];
	memcpy(temp, map, sizeof(temp));
	vector<Node> vn;
	Init(vn);
	if (vn.empty()){
		if (now > MAX){
			now = MAX;
			ans = tem;
			return;
		}
	}
	for (int i = 0; i < vn.size(); ++i){
		int t = _dfs(vn[i].x, vn[i].y, vn[i].c);
		tem.push_back(Point{ vn[i].x, vn[i].y });
		drop();
		while (leftmove());
		dfs(now + t*(t - 1));
		tem.pop_back();
		memcpy(map, temp, sizeof(map));
	}

}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		MAX = 0;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < M; ++j)
				map[i][j] = s[j] - '0';
		}
		dfs(0);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
}