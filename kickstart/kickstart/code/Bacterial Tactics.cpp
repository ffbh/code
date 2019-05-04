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
int mark[70000];
void input(){
	in >> R >> C;
	for (int i = 0; i < R; ++i)
		in >> M[i];

}

void _init(){
	memset(mark, -1, sizeof(mark));


}

inline bool can_put(int mask , int x,int y,char c){
	if (M[x][y] == '#')
		return 0;
	int pp = x * C + y;
	if ((1 << pp) & mask){
		return 0;
	}
	if (c == 'H'){
		for (int k = y - 1; k >= 0; --k){
			int pv = x * C + k;
			if (M[x][k] == '#'){
				return 0;
			}
			else if ((1 << pv) & mask){
				break;
			}
		}
		for (int k = y + 1; k < C; ++k){
			int pv = x * C + k;
			if (M[x][k] == '#'){
				return 0;
			}
			else if ((1 << pv) & mask){
				break;
			}
		}
	}
	else{
		for (int k = x - 1; k >= 0; --k){
			int pv = k * C + y;
			if (M[k][y] == '#'){
				return 0;
			}
			else if ((1 << pv) & mask){
				break;
			}
		}
		for (int k = x + 1; k < R; ++k){
			int pv = k * C + y;
			if (M[k][y] == '#'){
				return 0;
			}
			else if ((1 << pv) & mask){
				break;
			}
		}
	}

	return 1;
}


inline int put(int mask, int x, int y, char c){
	int MASK = mask;
	int pp = x * C + y;
	MASK += (1 << pp);
	if (c == 'H'){
		for (int k = y - 1; k >= 0; --k){
			int pv = x * C + k;
			if ((1 << pv) & mask){
				break;
			}
			else{
				MASK += (1 << pv);
			}
		}
		for (int k = y + 1; k < C; ++k){
			int pv = x * C + k;

			if ((1 << pv) & mask){
				break;
			}
			else{
				MASK += (1 << pv);
			}
		}
	}
	else{
		for (int k = x - 1; k >= 0; --k){
			int pv = k * C + y;
			if ((1 << pv) & mask){
				break;
			}
			else{
				MASK += (1 << pv);
			}
		}
		for (int k = x + 1; k < R; ++k){
			int pv = k * C + y;
			if ((1 << pv) & mask){
				break;
			}
			else{
				MASK += (1 << pv);
			}
		}
	}
	return MASK;
}


int dfs(int mask){

	if (mark[mask] != -1){
		return mark[mask];
	}
	mark[mask] = 0;
	int MASK;
	for (int i = 0; i < R && mark[mask] == 0; ++i)
	for (int j = 0; j < C && mark[mask]==0; ++j){
		if (can_put(mask, i, j, 'H')){
			MASK = put(mask, i, j, 'H');
			if (dfs(MASK) == 0){
				mark[mask] = 1;
			}
		}

		if (can_put(mask, i, j, 'V')){
			MASK = put(mask, i, j, 'V');
			if (dfs(MASK) == 0){
				mark[mask] = 1;
			}
		}
	}

	return mark[mask];
}

int main(){

	int CPP = 1;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		int ans = 0;
		for (int i = 0; i < R ; ++i)
		for (int j = 0; j < C; ++j){
			if (can_put(0, i, j, 'H')){
				int MASK = put(0, i, j, 'H');
				if (dfs(MASK) == 0){
					ans++;
				}
			}

			if (can_put(0, i, j, 'V')){
				int MASK = put(0, i, j, 'V');
				if (dfs(MASK) == 0){
					ans++;
				}
			}
		}

		printf("Case #%d: %d\n", CPP++, ans);



	}


	return 0;
}





