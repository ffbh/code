#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define LOGN 10
#define MAXN (1<<LOGN)
#define MAXNODES (3000010)
#define son(x) (p*4-2+x)
// 最值信息
struct dataInfo {
	short posx, posy;
	int val;
	dataInfo() {
		posx = posy = val = -1;
	}
	dataInfo(short _posx, short _posy, int _val) {
		posx = _posx;
		posy = _posy;
		val = _val;
	}
};
// 线段树结点信息
struct treeNode {
	// int son[4]
	dataInfo maxv;
	void reset() {
		maxv = dataInfo(0, 0, INT_MIN);
	}
}nodes[MAXNODES];

// 注意，这里需要返回指针，因为在后续使用中需要对这个结点的信息进行改变，如果返回对象的话只是一个copy，不会改变原结点的内容
treeNode* getNode(int id) {
	return &nodes[id];
}

struct Interval {
	int l, r;
	Interval() {}
	Interval(int _l, int _r) {
		l = _l;
		r = _r;
	}
	// 区间中点 
	int mid() {
		return (l + r) >> 1;
	}
	// 区间长度 
	int len() {
		return r - l + 1;
	}
	// 左半区间 
	Interval left() {
		return Interval(l, mid());
	}
	// 右半区间 
	Interval right() {
		return Interval(mid() + 1, r);
	}
	// 区间判交
	bool isIntersectWith(Interval& tarI) {
		return !(l > tarI.r || r < tarI.l);
	}
	// 区间判包含
	bool isInclude(Interval& tarI) {
		return l <= tarI.l && tarI.r <= r;
	}
	bool in(int v) {
		return l <= v && v <= r;
	}
};


void build_segtree(int p, Interval xI, Interval yI) {
	// 空矩形（右端点小于左端点）
	if (xI.len() <= 0 || yI.len() <= 0) {
		return;
	}
	treeNode* now = getNode(p);
	// 结点初始化
	now->reset();
	// 单位矩形
	if (xI.len() == 1 && yI.len() == 1) {
		return;
	}
	build_segtree(son(0), xI.left(), yI.left());
	build_segtree(son(1), xI.right(), yI.left());
	build_segtree(son(2), xI.left(), yI.right());
	build_segtree(son(3), xI.right(), yI.right());
}

bool insert_segtree(int p, Interval& xI, Interval& yI, int x, int y, int val) {
	if (xI.len() <= 0 || yI.len() <= 0) {
		return false;
	}
	if (!xI.in(x) || !yI.in(y)) {
		return true;
	}
	treeNode *now = getNode(p);
	if (xI.len() == 1 && yI.len() == 1) {
		if (now->maxv.val<val)
		now->maxv  = dataInfo(x, y, val);
		return true;
	}
	bool isvalid[4];
	isvalid[0] = insert_segtree(son(0), xI.left(), yI.left(), x, y, val);
	isvalid[1] = insert_segtree(son(1), xI.right(), yI.left(), x, y, val);
	isvalid[2] = insert_segtree(son(2), xI.left(), yI.right(), x, y, val);
	isvalid[3] = insert_segtree(son(3), xI.right(), yI.right(), x, y, val);

	now->maxv = dataInfo(0, 0, INT_MIN);
	//now->minv = dataInfo(0, 0, MAX_VAL);
	for (int i = 0; i < 4; i++) {
		if (!isvalid[i]) continue;
		treeNode *sonNode = getNode(son(i));
		now->maxv = sonNode->maxv.val > now->maxv.val ? sonNode->maxv : now->maxv;
		//now->minv = sonNode->minv.val < now->minv.val ? sonNode->minv : now->minv;
	}
	return true;
}

void query_segtree(int p, Interval& xI, Interval& yI, Interval& tarXI, Interval& tarYI, dataInfo& ans) {
	if (xI.len() <= 0 || yI.len() <= 0) {
		return;
	}

	if (!tarXI.isIntersectWith(xI) || !tarYI.isIntersectWith(yI)) {
		return;
	}
	treeNode *now = getNode(p);

	// 最大值优化 
	if (ans.val >= now->maxv.val) {
		return;
	}
	if (tarXI.isInclude(xI) && tarYI.isInclude(yI)) {
		ans = now->maxv;
		return;
	}
	query_segtree(son(0), xI.left(), yI.left(), tarXI, tarYI, ans);
	query_segtree(son(1), xI.right(), yI.left(), tarXI, tarYI, ans);
	query_segtree(son(2), xI.left(), yI.right(), tarXI, tarYI, ans);
	query_segtree(son(3), xI.right(), yI.right(), tarXI, tarYI, ans);
}
int main(){
	ifstream in("C:\\temp.txt");
	int M;
	while (cin >> M&&M){
		Interval x, y, tx, ty;
		x.l = 100;
		x.r = 200;
		y.l = 0;
		y.r = 1000;
		build_segtree(1, x, y);
		while (M--){
			char c;
			cin >> c;
			if (c == 'I'){
				int h;
				double a, v;
				cin >> h >> a >> v;
				insert_segtree(1, x, y, h, int(a * 10), int(v*10));
			}
			else{
				int a, b;
				double c, d;
				dataInfo ans;
				cin >> a >> b >> c >> d;
				tx.l = min(a, b);
				tx.r = max(a, b);
				ty.l = int(min(c, d) * 10);
				ty.r = int(max(c, d) * 10);
				query_segtree(1, x, y, tx, ty, ans);
				if (ans.val<0)
					printf("-1\n");
				else
					printf("%.1f\n", double(ans.val) / 10.0);
			}
		}
	}
	return 0;
}