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

#define INF ((int)1e9)

int N;
pll pt[100010];
//LL p[100010];
//int t[100010];

LL sp[800010][3], sn[800010][3];
LL price[800010];
int num[800010];
int val[800010];
bool leaf[800010];





void Init(){
	memset(leaf, 0, sizeof(leaf));
	memset(val, 0, sizeof(val));
}


void input(){
	in >> N;
	for (int i = 1; i <= N; ++i){
		in >> pt[i].second;
	}
	for (int i = 1; i <= N; ++i){
		in >> pt[i].first;
	}
	pt[0].first = 0;

}

int LSON, RSON;

void pushup(int root){
	LSON = lson;
	RSON = rson;

	val[root] = min(val[lson], val[rson]);
	num[root] = num[lson] + num[rson];
	for (int i = 0; i < 3; ++i){
		sp[root][i] = sp[lson][i] + sp[rson][(i + num[lson]) % 3];
		sn[root][i] = sn[lson][i] + sn[rson][(i + num[lson]) % 3];
	}
}


void build(int root,int l,int r){
	
	for (int i = 0; i < 3; ++i){
		sp[root][i] = 0;
		sn[root][i] = 0;
	}
	num[root] = 0;
	if (l == r){
		val[root] = pt[l].first - pt[l - 1].first;
		price[root] = pt[l].second;
		leaf[root] = 1;
	}
	else{
		int mid = (l + r) / 2;
		build(lson,l, mid);
		build(rson, mid + 1, r);
		pushup(root);
	}

}

void update(int root,int w){
	LSON = lson;
	RSON = rson;
	if (val[root] != w)
		return;
	if (leaf[root]){
		sn[root][0] = 3;
		sn[root][1] = 1;
		sn[root][2] = 2;
		sp[root][0] = 3 * price[root];
		sp[root][1] = 1 * price[root];
		sp[root][2] = 2 * price[root];
		num[root] = 1;
		val[root] = INF;
	}
	else{
		update(lson, w);
		update(rson, w);
		pushup(root);
	}
}

bool big(pll & a,pll& b){
	double A = double(a.first) / a.second;
	double B = double(b.first) / b.second;

	return A < B;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

		sort(pt + 1, pt + N + 1);
		set<int> si;
		
		for (int i = 1; i <= N; ++i)
			si.insert(pt[i].first - pt[i - 1].first);
		
		build(1, 1, N);
		double W;
		pll M = mp(0, 1);
		for (int w : si){
		
			update(1, w);
			
			pll now = mp(sp[1][1], num[1]);
	//		cout << now.first << " " << now.second << endl;
			if (big(M, now)){
				M = now;
				W = w;
			}
		}

		printf("%.6f %.6f\n", W, double(M.first) / M.second);
		










	}


	return 0;
}





