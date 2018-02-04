#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int W, H, N;
struct Node{
	int x1, y1, x2, y2;
	bool vis[4];
	bool cover[1010];
	int ans;
	bool ok(){
		for (int i = 0; i < 4;++i)
		if (!vis[i])
			return 1;
		return 0;
	}

	void set(int id){
		if (!cover[id]){
			ans++;
			cover[id] = 1;
		}
	}

	void getP(int mark, int& x, int& y){
		switch (mark)
		{
		case 0:
			x = x1; y = y1;
			break;
		case 1:
			x = x1; y = y2;
			break;
		case 2:	
			x = x2; y = y1;
			break;
		case 3:
			x = x2; y = y2;
			break;
		default:
			break;
		}
	}
}data[1010];

vector<int> vi[1010];

bool intersection(Node& p1,Node& p2){
	int x1 = max(p1.x1, p2.x1);
	int y1 = max(p1.y1, p2.y1);
	int x2 = min(p1.x2, p2.x2);
	int y2 = min(p1.y2, p2.y2);
	return x1 < x2&&y1 < y2;
}

bool inner(Node& p,int x,int y){
	return x>p.x1&&x<p.x2&&y>p.y1&&y < p.y2;
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> W >> H >> N;
	for (int i = 1; i <= N; ++i){
		cin >> data[i].x1 >> data[i].y1 >> data[i].x2 >> data[i].y2;
		memset(data[i].vis, 0, sizeof(data[i].vis));
		memset(data[i].cover, 0, sizeof(data[i].cover));
		data[i].ans = 0;
	}
	for (int i = 1; i <= N;++i)
	for (int j = i - 1; j >= 1; --j){
		int x, y;
		if (intersection(data[i], data[j])){
			vi[j].push_back(i);
		}
		for (int k = 0; k < 4; ++k){
			data[j].getP(k, x, y);
			if (inner(data[i], x, y))
				data[j].vis[k] = 1;
		}
	}
	int ans = 0, id;
	for (int i = N; i >= 1; --i){
		data[i].set(i);
		for (int j = 0; j < vi[i].size(); ++j){
			int v = vi[i][j];
			for (int k = v; k <= N;++k)
			if (data[v].cover[k]){
				data[i].set(k);
			}
		}
		if (data[i].ok()&&ans <= data[i].ans){
			ans = data[i].ans;
			id = i;
		}
	}


	printf("%d %d\n", ans, id);


	return 0;
}