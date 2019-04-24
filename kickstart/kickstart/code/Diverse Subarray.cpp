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



int N, S;
int a[100010];
unordered_map<int, int> M;
void input(){
	in >> N >> S;
	for (int i = 1; i <= N; ++i)
		in >> a[i];


}


int mmax[400010], lazy[400010], L[400010], R[400010];

void build(int root, int l, int r){
	mmax[root] = lazy[root] = 0;
	L[root] = l;
	R[root] = r;
	if (l < r){
		int mid = (l + r) / 2;
		build(lson, l, mid);
		build(rson, mid + 1, r);
	}
}
bool debug;
int update(int root, int l, int r, int v){
	//if (debug && L[root]==1&&R[root]==2){
	//	int t = 0;
	//}

	if (L[root] == R[root]){
		if (r < L[root] || l > R[root]){

		}
		else{
			mmax[root] += v;
		}
	}
	else if (r < L[root] || l > R[root]){

	}
	else if (l <= L[root] && r >= R[root]) {
		lazy[root] += v;
		mmax[root] += v;
	}
	else {
		if (lazy[root] != 0) {
			lazy[lson] += lazy[root];
			lazy[rson] += lazy[root];
			mmax[lson] += lazy[root];
			mmax[rson] += lazy[root];
			lazy[root] = 0;
		}
		int vl = update(lson, l, r, v);
		int vr = update(rson, l, r, v);
	/*	if (debug){
			cout << L[root] << "  " << R[root] << " :" << vl << " " << vr << endl;
		}*/
		mmax[root] = max(vl, vr);
	}
	return mmax[root];
}

queue<int> V[100010];
int num[100010];
int mark[100010];
void _init(){
	for (int i = 0; i <= 100000; ++i){
		num[i] = 0;
		while (!V[i].empty()){
			V[i].pop();
		}
	}
	memset(mark, -1, sizeof(mark));
}

int tmp[100010];

int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		build(1, 1, N);
		int ans = 0;
		for (int i = 1; i <= N; ++i){

			if (i == 4){
				debug = 1;
				int t = 0;
			}
			else{
				debug = 0;
			}

			tmp[i] = 1;
			if ((int)V[a[i]].size() < S){
			
				V[a[i]].push(i);
			}
			else{
				if (mark[a[i]] != -1){
					update(1, 1, mark[a[i]], S);
					tmp[mark[a[i]]] = 0;
				}
				V[a[i]].push(i);
				mark[a[i]] = V[a[i]].front();
				tmp[mark[a[i]]] = -S;
				V[a[i]].pop();
				update(1, 1, mark[a[i]], -S - 1);
			}
			int ret = update(1, 1, i, 1);
			ans = max(ans, ret);
		
	//		cout << "ff" << i << "  " << ret << endl;

		}

		printf("Case #%d: %d\n",CPP++, ans);












	}


	return 0;
}





