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

void _init(){



}

int n;
int a[200010];
int h[200010];

int mmax[800010], IDX[800010];
pii update(int root,int l,int r,int x){
	if (x >= l  &&  x <= r){
		int v = a[x];
		if (l == r){
			mmax[root] = v;
			IDX[root] = x;
		}
		else{
			int mid = (l + r) / 2;
			pii ll = update(lson, l, mid, x);
			pii rr = update(rson, mid + 1, r, x);
			if (ll.first > rr.first){
				mmax[root] = ll.first;
				IDX[root] = ll.second;
			}
			else{
				mmax[root] = rr.first;
				IDX[root] = rr.second;
			}
		}
	}
	return mp(mmax[root], IDX[root]);

}

pii query(int root, int l, int r,int L,int R){
	if (l > R || r < L){
		return mp(-1,-1);
	}
	if (l <= L && r >= R){
		return mp(mmax[root], IDX[root]);
	}
	else{
		int mid = (L + R) / 2;
		pii ll = query(lson, l, r, L, mid);
		pii rr = query(rson, l, r, mid + 1, R);
		return max(ll, rr);
	}
}


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

int ans;

void dfs(int l , int r){
	if (r - l + 1 <= 2){
		return;
	}
	if (l == 1 && r == 3){
		int t = 0;
	}
	pii M = query(1, l, r, 1, n);
	int idx = M.second;
	int st, en;
	int aim_l, aim_r;
	if (idx - l < r - idx){
		st = l;
		en = idx - 1;
		aim_l = idx + 1;
		aim_r = r;
	}
	else{
		st = idx + 1;
		en = r;
		aim_l = l;
		aim_r = idx - 1;
	}
	for (int k = st; k <= en; ++k){
		int aim = h[a[idx] - a[k]];
		if (aim >= aim_l && aim <= aim_r){
			ans++;
		}
	}
	dfs(l, idx - 1);
	dfs(idx + 1, r);
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();


		ans = 0;

		for (int i = 1; i <= n; ++i){
			h[a[i]] = i;
			if (i == 4){
				int t = 0;
			}
			update(1, 1, n, i);
		}

		dfs(1, n);


		cout << ans << endl;










	}


	return 0;
}





