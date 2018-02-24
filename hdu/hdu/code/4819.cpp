#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream in("C:\\temp.txt");
#define LOGN 10
#define MAXN (1<<LOGN)
#define MAXNODES (3000010)
#define son(x) (p*4-2+x)
int data[810][810];
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
	dataInfo maxv, minv;
	void reset() {
		maxv = dataInfo(0, 0, INT_MIN);//初始化
		minv = dataInfo(0, 0, INT_MAX);
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


bool build_segtree(int p, Interval xI, Interval yI) {
	// 空矩形（右端点小于左端点）
	if (xI.len() <= 0 || yI.len() <= 0) {
		return 0;
	}
	treeNode* now = getNode(p);
	// 结点初始化
	now->reset();
	// 单位矩形
	if (xI.len() == 1 && yI.len() == 1) {
		now->minv.val = now->maxv.val = data[xI.l][yI.l];
		return 1;
	}
	bool isvalid[4];
	isvalid[0] = build_segtree(son(0), xI.left(), yI.left());
	isvalid[1] = build_segtree(son(1), xI.right(), yI.left());
	isvalid[2] = build_segtree(son(2), xI.left(), yI.right());
	isvalid[3] = build_segtree(son(3), xI.right(), yI.right());
	for (int i = 0; i < 4; i++) {
		if (!isvalid[i]) continue;
		treeNode *sonNode = getNode(son(i));
		now->maxv = sonNode->maxv.val > now->maxv.val ? sonNode->maxv : now->maxv;
		now->minv = sonNode->minv.val < now->minv.val ? sonNode->minv : now->minv;
	}
}

bool insert_segtree(int p, Interval xI, Interval yI, Interval x, Interval y, int val) {
	if (xI.len() <= 0 || yI.len() <= 0) {
		return false;
	}
	if (!xI.isInclude(x) || !yI.isInclude(y)) {
		return true;
	}
	treeNode *now = getNode(p);
	if (xI.len() == 1 && yI.len() == 1&&x.len()==1&&y.len()==1) {
		now->maxv = now->minv = dataInfo(-1, -1, val);
		printf("%d %d:%d\n", xI.l, yI.l, val);
		return true;
	}
	bool isvalid[4];
	isvalid[0] = insert_segtree(son(0), xI.left(), yI.left(), x.left(), y.left(), val);
	isvalid[1] = insert_segtree(son(1), xI.right(), yI.left(), x.right(), y.left(), val);
	isvalid[2] = insert_segtree(son(2), xI.left(), yI.right(), x.left(), y.right(), val);
	isvalid[3] = insert_segtree(son(3), xI.right(), yI.right(), x.right(), y.right(), val);

	// 通过四个子结点的信息更新父结点 
	now->maxv = dataInfo(0, 0, INT_MIN);
	now->minv = dataInfo(0, 0, INT_MAX);
	for (int i = 0; i < 4; i++) {
		if (!isvalid[i]) continue;
		treeNode *sonNode = getNode(son(i));
		now->maxv = sonNode->maxv.val > now->maxv.val ? sonNode->maxv : now->maxv;
		now->minv = sonNode->minv.val < now->minv.val ? sonNode->minv : now->minv;
	}
	return true;
}

void query_segtree(int p, Interval xI, Interval yI, Interval tarXI, Interval tarYI, dataInfo& ans, int query_type) {
	if (xI.len() <= 0 || yI.len() <= 0) {
		return;
	}

	if (!tarXI.isIntersectWith(xI) || !tarYI.isIntersectWith(yI)) {
		return;
	}
	treeNode *now = getNode(p);

	// 最大值优化 
	if (query_type == 0 && ans.val >= now->maxv.val) {
		return;
	}
	// 最小值优化 
	if (query_type == 1 && ans.val <= now->minv.val) {
		return;
	}

	if (tarXI.isInclude(xI) && tarYI.isInclude(yI)) {
		if (query_type == 0) {
			ans = now->maxv;
		}
		else {
			ans = now->minv;
		}
		return;
	}
	query_segtree(son(0), xI.left(), yI.left(), tarXI, tarYI, ans, query_type);
	query_segtree(son(1), xI.right(), yI.left(), tarXI, tarYI, ans, query_type);
	query_segtree(son(2), xI.left(), yI.right(), tarXI, tarYI, ans, query_type);
	query_segtree(son(3), xI.right(), yI.right(), tarXI, tarYI, ans, query_type);
}



int main(){
	int CASE = 1;
	Interval x, y, tx, ty;
	int T;
	in >> T;
	while (T--){
		printf("Case #%d:\n", CASE++);
		int N;
		in >> N;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			in >> data[i][j];
		x.l = y.l = 1;
		x.r = y.r = N;
		build_segtree(1, x, y);
		int Q;
		in >> Q;
		while (Q--){
			int a, b, c;
			in >> a >> b >> c;
			c /= 2;
			tx.l = a - c;
			if (tx.l < 1)
				tx.l = 1;
			tx.r = a + c;
			if (tx.r > N)
				tx.r = N;
			ty.l = b - c;
			if (ty.l < 1)
				ty.l = 1;
			ty.r = b + c;
			if (ty.r > N)
				ty.r = N;
			dataInfo mmin, mmax;
			mmin.val = INT_MAX;
			mmax.val = INT_MIN;
			query_segtree(1, x, y, tx, ty, mmin, 1);
			query_segtree(1, x, y, tx, ty, mmax, 0);
			int ans = (mmin.val + mmax.val) / 2;
			printf("%d\n", ans);
			insert_segtree(1, x, y, tx, ty, ans);
		}
	}
}