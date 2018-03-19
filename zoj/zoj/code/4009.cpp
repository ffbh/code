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

int n, q;
int a[100010];
int mod = 99971;

int getval(int& ret){
	ret = 0;
	char c;
	while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
	ret = c - '0';
	while ((c = getchar()) != ' '&&c != '\n'&&c != '\r')
		ret = ret * 10 + c - '0';
	return ret;
}


void input(){
	in >> n >> q;
	
	for (int i = 1; i <= n; ++i){
		//	in >> a[i];
		getval(a[i]);
	//	scanf("%d", &a[i]);
	}

}

int sum[48][400010], lazy[400010];



void pushup(int root){
	for (int i = 0; i < 48; ++i)
		sum[i][root] = (sum[(i + lazy[lson]) % 48][lson] + sum[(i + lazy[rson] ) % 48][rson]) % mod;
	
}

void build(int root, int L, int R){
	
	lazy[root] = 0;
	if (L == R){
		
		sum[0][root] = a[L] % mod;
		for (int i = 1; i < 48; ++i){
			sum[i][root] =(LL)1* sum[i - 1][root] * sum[i - 1][root]*sum[i - 1][root] % mod;
			
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

//	pushdown(root);
	int mid = (ll +rr) >> 1;
	if (mid >= L)
		update(lson, L, R, ll, mid);
	if (mid + 1 <= R)
		update(rson, L, R, mid + 1, rr);
	pushup(root);

}



int query(int root, int L, int R,int ll,int rr,int add){
	//if (ll > R || rr < L)
	//	return 0;

	if (ll >= L&&rr <= R){
		return sum[(lazy[root]+add)%48][root];
	}

//	pushdown(root);
	int mid = (ll + rr) >> 1;
	int ans = 0;
	if (mid >= L)
		ans += query(lson, L, R, ll, mid,add+lazy[root]);
	if (mid + 1 <= R)
		ans += query(rson, L, R, mid + 1, rr,add+lazy[root]);
	ans %= mod;
	

//	pushup(root);
	return ans;

}


void get_input(int T){
	ofstream ou("C:\\input.txt");
	ou << T << endl;
	srand(time(0));
	for (int i = 0; i < T; ++i){
		int n = 1e5;
		int m = 1e5;
		ou << n << " " << m << endl;
		for (int j = 0; j < n; ++j){
			ou << abs(rand()) << " ";
		}
		ou << endl;
		for (int j = 0; j < m; ++j){
			int op = abs(rand()) % 2 + 1;
			int l = abs(rand()) % n + 1;
			int r = abs(rand()) % n + 1;
			if (l>r)
				swap(l, r);
			ou << op << " " << l << " " << r << endl;
		}
	}
}


int main(){

	/*get_input(5);
	return 0;*/

	int TEST_CASE = 1;
	in >> TEST_CASE;

	while (TEST_CASE-- > 0){
		input();

		

		build(1, 1, n);

		while (q-- > 0){
			int op, L, R;
		//		in >> op >> L >> R;
		//	scanf("%d%d%d", &op, &L, &R);
			getval(op);
			getval(L);
			getval(R);
			if (op == 1){
				update(1, L, R, 1, n);
			}
			else{
			//	int ans = query(1, L, R, 1, n, 0);
				printf("%d\n", query(1, L, R, 1, n,0));
			//	printf("%d\n", ans);

			}
		}
	}
	
	return 0;
}




