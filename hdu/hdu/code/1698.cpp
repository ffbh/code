#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
struct Tree{
	int l, r;
	int sum;
	int lazy;
};
Tree tree[400010];


void Build(int root, int l, int r){
	tree[root].l = l;
	tree[root].r = r;
	tree[root].sum = r - l + 1;
	tree[root].lazy = 0;
	int mid = (l + r) / 2;
	if (l == r)return;
	Build(root * 2, l, mid);
	Build(root * 2 + 1, mid + 1, r);
}


void Pushdown(int root){
	int lson = root * 2;
	int rson = root * 2 + 1;
	tree[lson].lazy = tree[root].lazy;
	tree[rson].lazy = tree[root].lazy;
	tree[lson].sum = (tree[lson].r - tree[lson].l + 1)*tree[root].lazy;
	tree[rson].sum = (tree[rson].r - tree[rson].l + 1)*tree[root].lazy;
	tree[root].lazy = 0;
}

void update(int root, int l, int r, int v){
	if (tree[root].l > r || tree[root].r < l)
		return;

	if (tree[root].l==tree[root].r){
		tree[root].sum = v;
		return;
	}
	if (tree[root].l == l&&tree[root].r == r){
		tree[root].lazy = v;
		tree[root].sum = (r - l + 1)*v;
		return;
	}
	if (tree[root].lazy)
		Pushdown(root);
		
	int mid = (tree[root].l + tree[root].r) / 2;
	if (r <= mid)
		update(root * 2, l, r, v);
	else if (l > mid)
		update(root * 2 + 1, l, r, v);
	else{
		update(root * 2, l, mid, v);
		update(root * 2 + 1, mid + 1,r ,v);
	}
	tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;

}




int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int a, b, c;
	int CASE = 1;
	while (T--){
		cin >> N;
		int M;
		cin >> M;
		Build(1, 1, N);
		while (M--){
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			update(1, a, b, c);
		}
		printf("Case %d: The total value of the hook is %d.\n",CASE++, tree[1].sum);
	}
	return 0;
}