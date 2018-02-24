#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
#define ID(x,y) (x*1010+y)
bool mark[1010][1010];
int f[10000010];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

bool IN(int x, int y){
	return x >= 0 && x < 1000 && y >= 0 && y < 1000;
}

int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

void Union(int a, int b){
	f[a] = b;
}

int main(){
	ifstream in("C:\\input.txt");

	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < 1010;++i)
	for (int j = 0; j < 1010; ++j)
		f[ID(i, j)] = ID(i, j);

	int N, x, y, tx, ty;
	int ans = 0;
	cin >> N;
	while (N--){
		cin >> x >> y;
		if (mark[x][y]){
			cout << ans << endl;
			continue;
		}
		ans++;
		mark[x][y] = 1;
		for (int i = 0; i < 4; ++i){
			tx = x + dirs[i][0];
			ty = y + dirs[i][1];
			if (IN(tx, ty) && mark[tx][ty]){
				int fb = find(ID(tx, ty));
				int fa = find(ID(x, y));
				if (fa != fb){
					Union(fa, fb);
					ans--;
				}
			}
		}
		cout << ans << endl;
	}
















	return 0;
}