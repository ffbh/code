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
pii p[500010];
LL b[2000010];
LL c[2000010];
LL mod = (LL)1e9 + 7;



LL update(int root,int l,int r,int x,int v,LL* tree){
	if (l <= x && x <= r){
		if (l == r){
			assert(tree[root] == 0);
			tree[root] += v;
		}
		else{
			int mid = (l + r) / 2;
			LL ll = update(lson, l, mid, x, v, tree);
			LL rr = update(rson, mid+1, r, x, v, tree);
			tree[root] = ll + rr;
		}
	}
	return tree[root];
}

LL query(int root,int l,int r,int L,int R,LL* tree){
	if (l <= L && R <= r){
		return tree[root];
	}
	else if (l > R || r < L){
		return 0;
	}
	else{
		int mid = (L + R) / 2;
		return query(lson, l, r, L, mid, tree) + query(rson, l, r, mid + 1, R, tree);
	}
}


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> p[i].first;
		p[i].second = i;
	}


}

void add(LL &A, LL b){
	A %= mod;
	b %= mod;
	A += b;
	A %= mod;
	if (A < 0){
		A += mod;
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();


		sort(p + 1, p + n + 1);


		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			LL val = p[i].first;
			int idx = p[i].second;
			update(1, 1, n, idx, idx, b);
			update(1, 1, n, idx, n - idx + 1, c);
			LL lf = query(1, 1, idx, 1, n, b);
			LL rg = query(1, idx, n, 1, n, c);
			add(ans, lf*rg%mod*val);
		}
		cout << ans << endl;












	}


	return 0;
}





