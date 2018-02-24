#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int h, w, area;
	bool operator<(const Node& p)const{
		return area < p.area;
	}
}data[20];
bool map[22][22];
bool vis[20];
int N, M, K;
bool judge(int x, int y, int b, bool f){
	int W, H;
	if (f){
		W = x + data[b].w - 1;
		H = y + data[b].h - 1;
	}
	else{
		W = x + data[b].h - 1;
		H = y + data[b].w - 1;
	}
	if (H > N || W > M)
		return 0;
	for (int i = x; i <= H;++i)
	for (int j = y; j <= W;++j)
	if (map[i][j])
		return 0;
	return 1;
}

void color(int x, int y, int b, bool f,int c){
	int W, H;
	if (f){
		W = x + data[b].w - 1;
		H = y + data[b].h - 1;
	}
	else{
		W = y + data[b].h - 1;
		H = x + data[b].w - 1;
	}
	for (int i = x; i <= H; ++i)
	for (int j = y; j <= W; ++j)
		map[i][j] = c;
}


bool dfs(){
	int x, y;
	bool flag = 1;
	for (int i = 1; i <= N&&flag;++i)
	for (int j = 1; j <= M;++j)
	if (map[i][j] == 0){
		x = i;
		y = j;
		flag = 0;
		break;
	}
	if (flag)
		return 1;
	for (int i = 1; i <= K; ++i){
		if (vis[i])
			continue;
		if (judge(x, y, i, 0)){
			color(x, y, i, 0, 1);
			vis[i] = 1;
			if (dfs())
				return 1;
			vis[i] = 0;
			color(x, y, i, 0, 0);
		}
		if (data[i].h!=data[i].w&&judge(x, y, i, 1)){
			color(x, y, i, 1, 1);
			vis[i] = 1;
			if (dfs())
				return 1;
			vis[i] = 0;
			color(x, y, i, 1, 0);
		}
	}
	return 0;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		cin >> K;
		for (int i = 1; i <= K; ++i){
			cin >> data[i].h >> data[i].w;
			data[i].area = data[i].h*data[i].w;
		}
		if (dfs())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}