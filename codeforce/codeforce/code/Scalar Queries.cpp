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
#define LYSS_CONNECTCHAR(a,b) a##b
#define ANNOTATION LYSS_CONNECTCHAR(/,/)
#define cerr ANNOTATION
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
LL d[2000010];
LL mod = (LL)1e9 + 7;



LL update(int root,int l,int r,int x,int v,LL* tree){
	if (l <= x && x <= r){
		if (l == r){
			assert(tree[root] == 0);
			tree[root] = v;
		}
		else{
			int mid = (l + r) / 2;
			LL ll = update(lson, l, mid, x, v, tree);
			LL rr = update(rson, mid+1, r, x, v, tree);
			tree[root] = (ll + rr) % mod;
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
		return (query(lson, l, r, L, mid, tree) + query(rson, l, r, mid + 1, R, tree)) % mod;
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


LL b_force(){
	LL ans = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = i; j <= n; ++j){
			
			int tmp[100];
			for (int k = i; k <= j; ++k){
				tmp[k - i + 1] = p[k].first;
			}
			if (i == 1 && j == 2){
				int t = 0;
			}
			int len = j - i + 1;
			sort(tmp + 1, tmp + len + 1);
			LL sum = 0;
			for (int i = 1; i <= len; ++i){
				add(sum, tmp[i] * i);
			}
	//		cerr << "try " << i << " " << j <<  " " << sum << endl;
			ans += sum;
		}
	}
	return ans;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		cerr << b_force() << endl;

		sort(p + 1, p + n + 1);


		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			LL val = p[i].first;
			int idx = p[i].second;
			
			

		//	LL l_empty = idx - query(1, 1, idx, 1, n, d);
		//	LL r_empty = n - idx + 1 - query(1, idx, n, 1, n, d);
		//	update(1, 1, n, idx, 1, d);
			int l_empty = idx ;
			int r_empty = n - idx + 1 ;
			update(1, 1, n, idx, l_empty, b);
			update(1, 1, n, idx, r_empty, c);
			LL lf = query(1, 1, idx, 1, n, b);
			LL rg = query(1, idx, n, 1, n, c);

			LL xishu = ((lf - idx)*(n - idx + 1)%mod + idx * rg % mod)% mod;
			if (i == 3){
				int t = 0;
			}
			add(ans, xishu%mod*val);
		}
		cout << ans << endl;











	}


	return 0;
}





