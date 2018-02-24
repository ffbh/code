#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int N;
struct Node{
	int x, y;
}data[1010];
int x[1010], y[1010], lx, ly;
int mx[1000010],my[1000010];
vector<int> vx[1010], vy[1010];
bool map[1010][1010];

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> data[i].x >> data[i].y;
		x[i] = data[i].x;
		y[i] = data[i].y;
	}
	lx = ly = N;
	sort(x, x + lx);
	lx = unique(x, x + lx) - x;
	sort(y, y + ly);
	ly = unique(y, y + ly) - y;
	for (int i = 0; i < lx; ++i)
		mx[x[i]] = i;
	for (int i = 0; i < ly; ++i)
		my[y[i]] = i;
	for (int i = 0; i < N; ++i){
		int h_x = mx[data[i].x];
		int h_y = my[data[i].y];
		map[h_x][h_y] = 1;
		vx[h_x].push_back(i);
		vy[h_y].push_back(i);
	}
	long long ans = 1e18;

	for (int k = 0; k < 1010; ++k){
		for (int i = 0; i < vx[k].size();++i)
		for (int j = i + 1; j < vx[k].size(); ++j){
			int x1 = data[vx[k][i]].x;
			int y1 = data[vx[k][i]].y;
			int x2 = data[vx[k][j]].x;
			int y2 = data[vx[k][j]].y;
			if (y1 == y2)
				continue;
			int h_y1 = my[y1];
			for (int e = 0; e < vy[h_y1].size(); ++e){
				int x3 = data[vy[h_y1][e]].x;
				int y3 = data[vy[h_y1][e]].y;
				if (x3 != x1){
					int x4 = x3;
					int y4 = y2;
					if (map[mx[x4]][my[y4]]){
						long long area = ((long long)(abs(x3 - x1)))*(abs(y2 - y1));
						if (area < ans)
							ans  = area;
					}


				}

			}




		}

	}
	if (ans == 1e18)
		cout << -1 << endl;
	else
		cout << ans << endl;


	return 0;
}