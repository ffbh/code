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

struct  Node{
	int g;
	bool leaf;
}tree[2000010];

int a[500010];

int gcd(int a,int b){
	if (b == 0)
		return a;
	else{
		return gcd(b, a%b);
	}
}

void pushUp(int x){
	if (!tree[x].leaf){
		tree[x].g = gcd(tree[x * 2].g, tree[x * 2 + 1].g);
	}
}

void build(int root,int l,int r){
	if (l == r){
		tree[root].g = a[l];
		tree[root].leaf = 1;
	}
	else{
		int mid = (l + r) / 2;
		tree[root].leaf = 0;
		build(root * 2, l, mid);
		build(root * 2 + 1, mid + 1, r);
		pushUp(root);
	}
}

int query(int root,int l,int r,int L,int R,int X){
	if (l > R || r < L)
		return 0;
	if (tree[root].leaf){
		return tree[root].g % X != 0;
	}
	int mid = (l + r) / 2;
	if (l >= L&&r <= R){
		if (tree[root * 2].g % X == 0 && tree[root * 2 + 1].g % X == 0){
			return 0;
		}
		else if (tree[root * 2].g % X != 0 && tree[root * 2 + 1].g % X != 0){
			return 2;
		}
		else if (tree[root * 2].g % X != 0){
			return query(root * 2, l, mid, L, R, X);
		}
		else{
			return query(root * 2+1, mid+1,r, L, R, X);
		}
	}
	else{
		return query(root * 2, l, mid, L, R, X) + query(root * 2 + 1, mid + 1, r, L, R, X);
		
	}

}


void update(int root, int l, int r, int p, int x){
	if (tree[root].leaf){
		if (l == p){
			tree[root].g = x;
		}
		else{
		//	int t = 0;
			assert(0);
		}
		return;
	}

	int mid = (l + r) / 2;
	if (p <= mid){
		update(root * 2, l, mid, p, x);
	}
	else{
		update(root * 2 + 1, mid + 1, r, p, x);
	}
	pushUp(root);


}

int n, m;

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	in >> m;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		build(1, 1, n);
		while (m-- > 0){
			int cmd, l, r, x;
		//	in >> cmd;
			scanf("%d", &cmd);
			if (cmd == 1){
			//	in >> l >> r >> x;
				scanf("%d%d%d", &l, &r, &x);
				if (query(1, 1, n, l, r, x) < 2){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
			}
			else{
				scanf("%d%d", &l, &x);
			//	in >> l >> x;
				update(1, 1, n, l, x);
			}




		}













	}


	return 0;
}





