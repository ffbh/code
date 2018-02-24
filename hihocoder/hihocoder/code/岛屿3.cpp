#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
bool mark[1010][1010];

int getID(int x,int y){
	return x * 1010 + y;
}
int f[1010 * 1010 + 1010];

int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

void Init(){
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < 1010 * 1011; ++i)
		f[i] = i;
}

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(int x, int y){
	return x >= 0 && x < 1000 && y >= 0 && y < 1000;
}

int main(){
	ifstream in("C:\\input.txt");
	int N;
	while (cin >> N){
		Init();
		int a, b, c;
		a = b = c = 0;
		while (N-- > 0){
			int x, y;
			cin >> x >> y;
			if (mark[x][y]){

			}
			else{
				mark[x][y] = 1;
				int id = getID(x, y);
				a++;
				b++;
				c += 4;
				for (int i = 0; i < 4; ++i){
					int nx = x + dirs[i][0];
					int ny = y + dirs[i][1];
					if (IN(nx, ny) && mark[nx][ny]){
						c-=2;
						int nid = getID(nx, ny);
						int fa = find(id);
						int fb = find(nid);
						if (fa != fb){
							a--;
							f[fa] = fb;
						}
					}

				}

			}
			printf("%d %d %d\n", a, b, c);
		}
	}





	return 0;
}