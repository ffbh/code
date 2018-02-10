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

#define MMAX (((int)2e5)+10)
set<LL> all;
LL D[MMAX];

int N;
LL MAXR;
struct Node{
	LL l, r;
	int state;//1 full   0 empty   2 no
	int lazy;
	bool end;
}tree[2 * MMAX * 4 + 10];

void build(int root,int l,int r){
	tree[root].l = D[l];
	tree[root].r = D[r] - 1;
	tree[root].state = 0;
	tree[root].lazy = -1;
	tree[root].end = 0;
	if (l+1==r){
		tree[root].end = 1;
		return;
	}
	else{
		int mid = (l + r) / 2;
		build(lson, l, mid);
		build(rson, mid, r);
	}
}

int op_state(int a){
	if (a == 2){
		return 2;
	}
	return 1 - a;

}

void pushDown(int root){
	if (tree[root].lazy == -1)
		return;



	if (tree[root].lazy == 1){
		tree[lson].lazy = tree[root].lazy;
		tree[lson].state = 1;
		tree[rson].lazy = tree[root].lazy;
		tree[rson].state = 1;
	}
	else if (tree[root].lazy == 2){
		tree[lson].lazy = tree[root].lazy;
		tree[lson].state = 0;
		tree[rson].lazy = tree[root].lazy;
		tree[rson].state = 0;

	}
	else{
		if (tree[lson].lazy == 1){
			tree[lson].lazy = 2;
			tree[lson].state = 0;
		}
		else if (tree[lson].lazy == 2){
			tree[lson].lazy = 1;
			tree[lson].state = 1;
		}
		else if (tree[lson].lazy == 3){
			tree[lson].lazy = -1;
			tree[lson].state = op_state(tree[lson].state);
		}
		else{
			tree[lson].lazy = 3;
			tree[lson].state = op_state(tree[lson].state);
		}

		if (tree[rson].lazy == 1){
			tree[rson].lazy = 2;
			tree[rson].state = 0;
		}
		else if (tree[rson].lazy == 2){
			tree[rson].lazy = 1;
			tree[rson].state = 1;
		}
		else if (tree[rson].lazy == 3){
			tree[rson].lazy = -1;
			tree[rson].state = op_state(tree[rson].state);
		}
		else{
			tree[rson].lazy = 3;
			tree[rson].state = op_state(tree[rson].state);
		}


	}
	tree[root].lazy = -1;

}

void pushUp(int root){
	if (tree[lson].state == 2 || tree[rson].state == 2){
		tree[root].state = 2;
	}
	if (tree[lson].state == tree[rson].state)
		tree[root].state = tree[lson].state;
	else
		tree[root].state = 2;
}


void update(int root, LL l, LL r, LL type){
	
	if (tree[root].l > r || tree[root].r < l)
		return;
	

	if (!tree[root].end)
		pushDown(root);
	if (tree[root].l >= l && tree[root].r <= r){
		if (type == 1){
			tree[root].state = 1;
			tree[root].lazy = 1;
		}
		else if (type == 2){
			tree[root].state = 0;
			tree[root].lazy = 2;
		}
		else{
			tree[root].lazy = 3;
			tree[root].state = op_state(tree[root].state);
		}
	}
	else{
		update(lson, l, r, type);
		update(rson, l, r, type);
		pushUp(root);
	}


}
int kk;
LL query(int root){
	pushDown(root);
	
	if (tree[root].end){
		assert(tree[root].state != 2);
		if (tree[root].state == 0){
			return tree[root].l;
		}
		else{
			return MAXR;
		}
	}
	if (tree[root].state == 0){
		return tree[root].l;
	}
	else if (tree[root].state == 1){
		return MAXR;
	}
	else{
		
		LL lf = query(lson);
		if (lf != MAXR)
			return lf;
		LL rt = query(rson);
		pushUp(root);
		
		return rt;
	}


	
}

LL op[MMAX],a[MMAX], b[MMAX];
int n;
void input(){
	in >> N;
	all.insert(1);
	for (int i = 1; i <= N; ++i){
	//	in >> op[i] >> a[i] >> b[i];
		scanf("%lld%lld%lld", &op[i], &a[i], &b[i]);
		all.insert(a[i]);
	/*	all.insert(b[i]);
		if (a[i] - 1 > 0)
			all.insert(a[i] - 1);
		if (b[i] - 1 > 0)
			all.insert(b[i] - 1);
		all.insert(a[i] + 1);*/
		all.insert(b[i] + 1);
		MAXR = max(MAXR, b[i] + 1);
	}
	n = 1;
	for (LL p : all){
		D[n++] = p;
	}
	n--;
	build(1, 1, n);




}

int main(){


	input();



	for (int i = 1; i <= N; ++i){
	
		update(1, a[i], b[i], op[i]);
		printf("%lld\n", query(1));
	}

	return 0;
}





