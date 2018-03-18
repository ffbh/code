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
//#include <unordered_set>
//#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
//ifstream in("C:\\input.txt");
istream& in = cin;
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

int n, q;
int a[100010];
int mod = 99971;




void input(){
	in >> n >> q;
	
	for (int i = 1; i <= n; ++i){
		//	in >> a[i];
		scanf("%d", &a[i]);
	}

}

int sum[48][300010], lazy[300010];



void pushup(int root){
	for (int i = 0; i < 48; ++i)
		sum[i][root] = (sum[(i + lazy[lson]) % 48][lson] + sum[(i + lazy[rson] ) % 48][rson]) % mod;
	
}

void build(int root, int L, int R){
	
	lazy[root] = 0;
	if (L == R){
		sum[0][root] = a[L] % mod;
		for (int i = 1; i < 48; ++i){
			sum[i][root] = sum[i - 1][root] * sum[i - 1][root] % mod*sum[i - 1][root] % mod;
		}
	}
	else{
		int mid = (L + R) >> 1;
		build(lson, L, mid);
		build(rson, mid + 1, R);
	//	pushup(root);
		for (int i = 0; i < 48; ++i)
			sum[i][root] = (sum[i][lson] + sum[i][rson]) % mod;
	}
}


void pushdown(int root){
	if (lazy[root] != 0){
		lazy[lson] += lazy[root];
		lazy[rson] += lazy[root];
		lazy[root] = 0;
	}
}

void update(int root, int L, int R,int ll,int rr){
	/*if (ll > R || rr < L)
		return;*/

	if (ll >= L&&rr <= R){
		lazy[root] ++;
		return;
	}

	pushdown(root);
	int mid = (ll +rr) >> 1;
	if (mid >= L)
		update(lson, L, R, ll, mid);
	if (mid + 1 <= R)
		update(rson, L, R, mid + 1, rr);
	pushup(root);

}

int query(int root, int L, int R,int ll,int rr){
	//if (ll > R || rr < L)
	//	return 0;

	if (ll >= L&&rr <= R){
		return sum[(lazy[root])%48][root];
	}

	pushdown(root);
	int mid = (ll + rr) >> 1;
	int ans = 0;
	if (mid >= L)
		ans += query(lson, L, R, ll, mid);
	if (mid + 1 <= R)
		ans += query(rson, L, R, mid + 1, rr);
	ans %= mod;
	pushup(root);
	return ans;

}



int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;

	while (TEST_CASE-- > 0){
		input();

		build(1, 1, n);

		while (q-- > 0){
			int op, L, R;
			//	in >> op >> L >> R;
			scanf("%d%d%d", &op, &L, &R);
			
			if (op == 1){
				update(1, L, R, 1, n);
			}
			else{
				printf("%d\n", query(1, L, R, 1, n));

			}


		}

	}
	return 0;
}




