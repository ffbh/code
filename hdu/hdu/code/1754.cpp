#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//ifstream in("C:\\temp.txt");
struct Tree{
	int mmax;
	int l, r;
};
Tree tree[1600100];
int max(int a, int b){
	return a > b ? a : b;
}

void Build(int root, int l, int r){
	tree[root].l = l;
	tree[root].r = r;
	if (l == r){
	//	in >> tree[root].mmax;
		scanf("%d", &tree[root].mmax);
		return;
	}
	int mid = (l + r) / 2;
	Build(root * 2, l, mid);
	Build(root * 2 + 1, mid + 1, r);
	tree[root].mmax = max(tree[root * 2].mmax, tree[root * 2 + 1].mmax);
}


void update(int root,int f,int v){
	int l = tree[root].l;
	int r = tree[root].r;
	if (l == r){
		tree[root].mmax = v;
		return;
	}
	int mid = (l + r) / 2;
	if (f <= mid)
		update(root * 2, f, v);
	else
		update(root * 2 + 1, f, v);
	tree[root].mmax = max(tree[root * 2].mmax, tree[root * 2 + 1].mmax);
 }


int Query(int root, int l, int r){
	if (l == tree[root].l&&r == tree[root].r)
		return tree[root].mmax;
	if (tree[root].l==tree[root].r)
		return tree[root].mmax;
	int mid = (tree[root].l + tree[root].r) / 2;
	if (r<=mid)
		return Query(root * 2, l, r);
	else if (l>mid)
		return Query(root * 2+1, l, r);
	else
		return  max(Query(root * 2, l, mid), Query(root * 2 + 1, mid + 1, r));
	
}






int main(){
	int N, M;
	char cmd;
	int a, b;
	while (cin >> N >> M){
		Build(1, 1, N);
		
		while (M--){
			cin >> cmd ;
		//	getchar();
			scanf("%d%d", &a, &b);
			if (cmd == 'Q'){
				if (a > b)
					swap(a, b);
				cout << Query(1, a, b) << endl;
			}
			else{
				update(1,a,b);
			}
		}
	}

	return 0;
}