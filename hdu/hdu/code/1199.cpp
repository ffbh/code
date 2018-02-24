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


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

set<LL> all;
unordered_map<LL, int> M;
LL D[20000];
#define MMAX (400000)
LL L[MMAX], R[MMAX];
LL l[MMAX], r[MMAX], len[MMAX];
int lazy[MMAX];
pll W[MMAX];

pll MAX(pll& a,pll &b){
	if (a.second - a.first > b.second - b.first){
		return a;
	}
	else if (a.second - a.first < b.second - b.first){
		return b;
	}
	else if (a.first < b.first){
		return a;
	}
	else
		return b;
}


void pushUp(int root){
	W[root] = MAX(W[lson], W[rson]);

	LL a = R[lson];
	LL b = L[rson];
	
	if (R[lson]>0 && L[rson] > 0){
		pll p = mp(r[lson] - R[lson] + 1, l[rson] + L[rson] - 1);
		W[root] = MAX(W[root], p);
	}
	if (L[lson] == len[lson]){
		L[root] = L[lson] + L[rson];
	}
	else{
		L[root] = L[lson];
	}
	if (R[rson] == len[rson]){
		R[root] = R[rson] + R[lson];
	}
	else{
		R[root] = R[rson];
	}
}


void pushDown(int root){
	if (lazy[root] == -1)
		return;
	if (lazy[root] == 0){
		L[lson] = 0;
		R[lson] = 0;
		W[lson] = mp(0, -1);
		lazy[lson] = 0;
		L[rson] = 0;
		R[rson] = 0;
		W[rson] = mp(0, -1);
		lazy[rson] = 0;
	}
	else{
		L[lson] = len[lson];
		R[lson] = len[lson];
		W[lson] = mp(l[lson],r[lson]);
		lazy[lson] = 1;
		L[rson] = len[rson];
		R[rson] = len[rson];
		W[rson] = mp(l[rson], r[rson]);
		lazy[rson] = 1;
	}





	lazy[root] = -1;
}

void build(int root, LL ll, LL rr){

	l[root] = D[ll];
	r[root] = D[rr] - 1;
	len[root] = r[root] - l[root] + 1;
	lazy[root] = -1;
	if (ll + 1 == rr){
		L[root] = R[root] = 0;
		W[root] = mp(0, -1);
		return;
	}
	else{
		LL mid = (ll + rr) / 2;
		build(lson, ll, mid);
		build(rson, mid, rr);
		pushUp(root);
	}
}


void update(int root,LL ll,LL rr,int f){
	if (l[root] > rr || r[root] < ll){
		return;
	}
	
	pushDown(root);

	if (l[root] >= ll && r[root] <= rr){
		if (f == 0){
			L[root] = 0;
			R[root] = 0;
			W[root] = mp(0, -1);
			lazy[root] = 0;
		}
		else{
			L[root] = len[root];
			R[root] = len[root];
			W[root] = mp(l[root], r[root]);
			lazy[root] = 1;
		}
	}
	else{
		if (root == 1){
			int t = 0;
		}

		update(lson, ll, rr,f);
		update(rson, ll, rr,f);
		pushUp(root);
		
	}
	


}

int N;
LL a[2010], b[2010];
int f[2010];
void input(){
	all.clear();

	for (int i = 1; i <= N; ++i){
		char c;
		in >> a[i] >> b[i] >> c;
		if (c == 'w'){
			f[i] = 1;
		}
		else{
			f[i] = 0;
		}
		all.insert(a[i]);
		all.insert(b[i]);
		all.insert(a[i] - 1);
		all.insert(a[i] + 1);
		all.insert(b[i] - 1);
		all.insert(b[i] + 1);
	}
}

int n;

void Init(){
	n = 1;
	M.clear();
	for (LL p : all){
		D[n] = p;
		M[p] = n++;
	}
	n--;
	build(1, 1, n);

}

int main(){


	while (in>>N){
		input();
		Init();
		for (int i = 1; i <= N; ++i){
			if (i == 3){
				int t = 0;
			}
			update(1, a[i], b[i], f[i]);
		}

		LL len = W[1].second - W[1].first + 1;
		if (len <= 0){
			printf("Oh, my god\n");
		}
		else{
			printf("%lld %lld\n", W[1].first, W[1].second);
		}


	}


	return 0;
}





