#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int id[4][4], p[4][4];
bool ok[3][3];
int dirs[9][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 0, 0, 1, 1, -1, 1, 0, 1, 1 };

void Init(){
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 4; ++j){
		id[i][j] = i * 4 + j;
		p[i][j] = (1 << id[i][j]);
	}
}

bool IN(int x,int y){
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

bool vis[1 << 20];
struct Node{
	int key, step;
};

int bfs(vector<int>& V,int start){
	queue<Node> qi;
	Node st;
	st.key = start;
	vis[start] = 1;
	st.step = 0;
	qi.push(st);
	while (!qi.empty()){
		Node u = qi.front(), v;
		qi.pop();
		if (u.key == 0 || u.key == 65535 ){
			return u.step;
		}
		for (int i = 0; i < V.size(); ++i){
			v.step = u.step + 1;
			v.key = u.key^V[i];
			if (!vis[v.key]){
				vis[v.key] = 1;
				qi.push(v);
			}
		}
	}
	return -1;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	string s;
	int startkey = 0;
	for (int i = 0; i < 4; ++i){
		cin >> s;
		for (int j = 0; j < 4; ++j){
			startkey = startkey * 2 + (s[j] == 'B');
		}
	}

	for (int i = 0; i < 3; ++i){
		cin >> s;
		for (int j = 0; j < 3; ++j)
			ok[i][j] = (s[j] == '1');
	}
	vector<int> v;
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 4; ++j){
		if (i == 2 && j == 1){
			int t = 0;
		}
		int key = 0;
		for (int k = 0; k < 9; ++k){
			int x = i + dirs[k][0];
			int y = j + dirs[k][1];
			int real_x = dirs[k][0] + 1;
			int real_y = dirs[k][1] + 1;
			if (ok[real_x][real_y] && IN(x, y)){
				key += (1 << (15 - id[x][y]));
			}
		}
		
		if (key)
			v.push_back(key);
	}
	

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int ans = bfs(v, startkey);
	if (ans == -1)
		cout << "Impossible" << endl;
	else
		cout << ans << endl;



	return 0;
}