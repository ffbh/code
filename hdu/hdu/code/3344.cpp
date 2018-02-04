#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;
int N, M;
int map[110][110];
int dirs[2][2] = { -1, 0, 0, -1 };
struct Node{
	int val[2];
}ans[110][110];
bool vis[110][110][2];
bool mark[110][110];



int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		memset(map, -1, sizeof(map));
		memset(ans, -1, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i<N; ++i){
			for (int j = 0; j<M; ++j){
				char c;
				cin >> c;
				if (c != '_'){
					map[i][j] = c - '0';
					for (int k = 0; k<2; ++k){
						int nextx, nexty;
						nextx = i + dirs[k][0];
						nexty = j + dirs[k][1];
						if (nextx >= 0 && nexty >= 0)
							vis[nextx][nexty][k] = 1;
					}
				}
				else
					mark[i][j] = 1;
			}
		}
		for (int i = 0; i<N; ++i){
			for (int j = 0; j<M; ++j)
			if (mark[i][j])
			for (int k = 0; k<2; ++k)
			if (vis[i][j][k]){
				int sum = 0;
				int x, y;
				x = i - dirs[k][0];
				y = j - dirs[k][1];
				while (x<N&&y<M&&map[x][y] >= 0){
					sum += map[x][y];
					x -= dirs[k][0];
					y -= dirs[k][1];
				}
				ans[i][j].val[k] = sum;
			}
		}
		for (int i = 0; i<N; ++i){
			for (int j = 0; j<M; ++j){
				if (map[i][j] != -1)
					printf(".......");
				else if (!vis[i][j][0] && !vis[i][j][1])
					printf("XXXXXXX");
				else{
					if (ans[i][j].val[0] != -1)
						printf("%03d", ans[i][j].val[0]);
					else
						printf("XXX");
					putchar('\\');
					if (ans[i][j].val[1] != -1)
						printf("%03d", ans[i][j].val[1]);
					else
						printf("XXX");
				}

				if (j<M - 1)
					putchar(' ');
			}
			printf("\n");
		}
		cout << endl;

	}






	return 0;

}