#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

int n, m;
char mmp[110][110];
int dp[210][110][110];
bool vis[210][110][110];

void input(){
	in >> m >> n;
	for (int i = 0; i < n; ++i)
		in >> mmp[i];


}

void upd(int& a,int b){
	if (a < b)
		a = b;
}

bool IN(int x,int y){
	return x >= 0 && x < n&&y >= 0 && y < m&&mmp[x][y] != '#';
}

void Init(){
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
}

int dirs[4][4] = { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1 };

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		Init();

		if (mmp[0][0] == '*')
			dp[0][0][0] = 1;
		else
			dp[0][0][0] = 0;
		vis[0][0][0] = 1;
		for (int k = 0; k <= n + m - 2; ++k){
			for (int i = 0; i < n;++i)
			for (int j = 0; j < n; ++j){
				if (!vis[k][i][j])
					continue;

				int & ref = dp[k][i][j];
				
				int ax = i;
				int ay = k - i;
				int bx = j;
				int by = k - j;
				if (!IN(ax, ay) || !IN(bx, by)){
					continue;
				}

				if (k == 1 && ax == 1 && bx == 0){
					int t = 0;
				}

				for (int p = 0; p < 4; ++p){
					int nax = ax + dirs[p][0];
					int nay = ay + dirs[p][1];
					int nbx = bx + dirs[p][2];
					int nby = by + dirs[p][3];
					
					if (nax == 1 && nay == 1){
						int t = 0;
					}

					if (IN(nax, nay) && IN(nbx, nby)){
						int add = 0;
						if (nax == nbx){
							
					
							if (mmp[nax][nay] == '*'){
								add++;
							}
						

						}
						else{
							if (mmp[nax][nay] == '*'){
								add++;
							}
							if (mmp[nbx][nby] == '*'){
								add++;
							}
						}
						vis[k + 1][nax][nbx] = 1;
						upd(dp[k + 1][nax][nbx], ref + add);
					}

				}
			}


		}

		printf("%d\n", dp[n + m - 2][n - 1][n - 1]);

	}


	return 0;
}





