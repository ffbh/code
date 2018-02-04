#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
struct Tree{
	int l, r;
	int lsum, rsum, sum;
	bool ok;
};
Tree tree[200010];

void Build(int root, int l, int r){
	tree[root].ok = 1;
	tree[root].l = l;
	tree[root].r = r;
	tree[root].lsum = tree[root].rsum = tree[root].sum = r-l+1;
	if (l == r)return;
	int mid = (l + r) / 2;
	Build(root * 2, l, mid);
	Build(root * 2+1, mid + 1, r);
}

void Pushup(int root){
	int lson = tree[root*2].r - tree[root*2].l + 1;
	int rson = tree[root * 2 + 1].r - tree[root * 2 + 1].l + 1;
	if (lson == tree[root * 2].lsum)
		tree[root].lsum = lson + tree[root * 2 + 1].lsum;
	else
		tree[root].lsum = tree[root * 2].lsum;

	if (rson == tree[root * 2 + 1].rsum)
		tree[root].rsum = rson + tree[root * 2].rsum;
	else
		tree[root].rsum = tree[root * 2 + 1].rsum;

	int mmax = max(tree[root].lsum, tree[root].rsum);
	tree[root].sum = max(mmax, tree[root * 2].rsum + tree[root * 2 + 1].lsum);
}

void Update(int root, int num, bool ok){
	if (tree[root].l == tree[root].r){
		tree[root].ok = ok;
		tree[root].lsum = tree[root].rsum = tree[root].sum = ok;
		return;
	}
	int l = tree[root].l;
	int r = tree[root].r;
	int mid = (l + r) / 2;
	if (num <= mid)
		Update(root * 2, num, ok);
	else
		Update(root * 2 + 1, num, ok);
	Pushup(root);
}


int Query(int root, int x){
	int ans = 0;
	if (tree[root].l == tree[root].r)
		return tree[root].ok;

	if (tree[root].sum == 0 || tree[root].sum == (tree[root].r - tree[root].l + 1))
		return tree[root].sum;

	int mid = (tree[root].l + tree[root].r) / 2;
	if (x <= mid){
		if (x >= tree[root*2].r - tree[root*2].rsum+1)
			ans += Query(root * 2 + 1, mid+1) + Query(root * 2, x);
		else
			ans += Query(root * 2, x);
	}
	else{
		if (x <= tree[root * 2 + 1].lsum + tree[root * 2 + 1].l-1)
			ans += Query(root * 2 + 1, x) + Query(root * 2, mid);
		else
			ans += Query(root * 2 + 1, x);
	}
	return ans;
}








int main(){
	ifstream in("C:\\temp.txt");
	int M;
	char cmd;
	int n;
	vector<int>::iterator it;
	while (cin >> N >> M){
		vector<int> vv;
		Build(1, 1, N);
		while(M--){
			getchar();
			cmd = getchar();
		//	in >> cmd;
			if (cmd == 'D'){
				scanf("%d", &n);
			//	in >> n;
				Update(1,n, 0);
				vv.push_back(n);
			}
			else if (cmd == 'Q'){
				scanf("%d", &n);
			//	in >> n;
				cout << Query(1,n) << endl;
			}
			else if(!vv.empty()){
				n = vv.back();
				Update(1, n, 1);
				while (1){
					it = vv.begin();
					while (it != vv.end() && *it != n)
						it++;
					if (it == vv.end())
						break;
					else
						vv.erase(it);
				}
			
			}
		}
	}
	return 0;
}