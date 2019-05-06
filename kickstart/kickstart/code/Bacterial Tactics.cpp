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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  
#define FFLUAHALL 	fflush(stdin);fflush(stdout);




int R, C;
string M[16];
int dp[16][16][16][16];
bool vvv[16][16];
void input(){
	in >> R >> C;
	for (int i = 0; i < R; ++i)
		in >> M[i];
	
}

void _init(){
	memset(dp, -1, sizeof(dp));
	memset(vvv, 0, sizeof(vvv));

}


bool ok(int x1, int y1, int x2, int y2, int x, int y) {
	if (x != -1) {
		for (int k = y1; k <= y2; ++k) {
			if (M[x][k] == '#')
				return false;
		}
	}
	else {
		for (int k = x1; k <= x2; ++k) {
			if (M[k][y] == '#')
				return false;
		}
	}
	return true;
}

static int dfs(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		return 0;
	}
	set<int> S;
	if (dp[x1][y1][x2][y2] == -1) {
		for (int i = x1; i <= x2; ++i) {
			if (ok(x1, y1, x2, y2, i, -1)) {
				int v1 = dfs(x1, y1, i - 1, y2);
				int v2 = dfs(i + 1, y1, x2, y2);
				S.insert(v1 ^ v2);
			}
		}

		for (int i = y1; i <= y2; ++i) {
			if (ok(x1, y1, x2, y2, -1, i)) {
				int v1 = dfs(x1, y1, x2, i - 1);
				int v2 = dfs(x1, i + 1, x2, y2);
				S.insert(v1 ^ v2);
			}
		}

		for (int k = 0;; ++k) {
			if (!S.count(k)) {
				dp[x1][y1][x2][y2] = k;
				break;
			}
		}
	}
	return dp[x1][y1][x2][y2];
}




int main(){

	int CPP = 1;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		
		int ans = 0;

		for (int i = 0; i < R; ++i) {
			if (ok(0, 0, R - 1, C - 1, i, -1)) {
				int v1 = dfs(0, 0, i - 1, C - 1);
				int v2 = dfs(i + 1, 0, R - 1, C - 1);
				if (v1 == v2){
					ans += C;
				}
			}
		}

		for (int i = 0; i < C; ++i) {
			if (ok(0, 0, R - 1, C - 1, -1, i)) {
				int v1 = dfs(0, 0, R - 1, i - 1);
				int v2 = dfs(0, i + 1, R - 1, C - 1);
				if (v1 == v2) {
					ans += R;
				}
			}
		}

		

		printf("Case #%d: %d\n", CPP++, ans);



	}


	return 0;
}





