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

int n, q;

vector<int> vi[200010];

void Init(){
	for (int i = 0; i < 200010; ++i)
		vi[i].clear();

}


void input(){
	in >> n >> q;
	for (int i = 1; i < n; ++i){
		int a, b;
	//	in >> a >> b;
		scanf("%d%d", &a, &b);
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
}

int cnt[600010];
//int ll[600010], rr[600010];
                      

int cale(int al, int ar, int bl, int br){
	int edge = 0;

	for (int i = al; i <= ar; ++i){
		int p = lower_bound(vi[i].begin(), vi[i].end(), bl) - vi[i].begin();
		while (p < vi[i].size() && vi[i][p] >= bl &&vi[i][p] <= br){
			edge++;
			p++;
		}
	}
	return edge;
}


void build(int root, int L, int R){
//	ll[root] = L;
//	rr[root] = R;
	if (L == R){
		cnt[root] = 1;
		return;
	}
	else{
		int mid = (L + R) / 2;
		build(lson, L, mid);
		build(rson, mid + 1, R);
		cnt[root] = cnt[lson] + cnt[rson] - cale(L, mid, mid + 1, R);
	}
}

int query(int root, int L, int R,int ll,int rr){
	if (ll >= L && rr <= R){
		return cnt[root];
	}
	if (ll > R || rr < L)
		return 0;
	int mid = (ll + rr) / 2;
	int lq = query(lson, L, R, ll, mid);
	int rq = query(rson, L, R, mid + 1, rr);

	if (lq == 0 || rq == 0){
		return  lq + rq;
	}
	else{
		return lq + rq - cale(max(L, ll), mid, mid + 1, min(R, rr));
	}
}
int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

	
		for (int i = 1; i <= n; ++i){
			sort(vi[i].begin(), vi[i].end());
		}

		build(1, 1, n);

		while (q-- > 0){
			int L, R;
		//	in >> L >> R;
			scanf("%d%d", &L, &R);
			printf("%d\n", query(1, L, R, 1, n));
		}




	}


	return 0;
}





