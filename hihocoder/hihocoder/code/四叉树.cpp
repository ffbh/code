#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
#define MMAX (50000)
#define MAXSIZE (10)
int N, M, maxx, maxy, minx, miny, size;
#define Exp (1e-7)
bool lessequal(double x,double y){
	return x - y < Exp;
}
struct Node{
	bool div;
	int num;
	int son[4];
	int lx, ly, rx, ry, midx, midy;
	double radius;
	bool IN(int x, int y){
		return x >= lx&&x <= rx&&y <= ry&&y >= ly;
	}
	bool IN(int a, int b, int r){
		double dis = sqrt((midx - a)*(midx - a) + (midy - b)*(midy - b));
	//	return dis <= r + radius;
		return lessequal(dis, r + radius);
	}
}tree[MMAX];
struct Point{
	int x, y;
	Point(){}

}data[50010];

Point vp[MMAX][MAXSIZE];

int newNode(int lx, int ly, int rx, int ry){
	tree[size].div = 0;
	tree[size].num = 0;
	tree[size].lx = lx;
	tree[size].ly = ly;
	tree[size].rx = rx;
	tree[size].ry = ry;
	tree[size].midx = (lx + rx) / 2;
	tree[size].midy = (ly + ry) / 2;
	tree[size].radius = sqrt((rx - lx)*(rx - lx) + (ry - ly)*(ry - ly)) / 2.0;
	return size++;
}



void Insert(int root, int x, int y){
	if (!tree[root].IN(x, y))
		return;
	if (tree[root].div){
		for (int i = 0; i < 4; ++i){
			Insert(tree[root].son[i], x, y);
		}
	}
	else{
		int& num = tree[root].num;
		if (num < MAXSIZE){
			vp[root][num].x = x;
			vp[root][num].y = y;
			num++;
		}
		else{
			tree[root].div = 1;
			int lx = tree[root].lx;
			int ly = tree[root].ly;
			int rx = tree[root].rx;
			int ry = tree[root].ry;
			int midx = tree[root].midx;
			int midy = tree[root].midy;
			tree[root].son[0] = newNode(lx, midy, midx, ry);
			tree[root].son[1] = newNode(midx + 1, midy, rx, ry);
			tree[root].son[2] = newNode(lx, ly, midx - 1, midy - 1);
			tree[root].son[3] = newNode(midx, ly, rx, midy - 1);
			for (int i = 0; i < 4; ++i){
				Insert(tree[root].son[i], x, y);
			}
			for (int k = 0; k < MAXSIZE; ++k){
				int x = vp[root][k].x;
				int y = vp[root][k].y;
				for (int i = 0; i < 4; ++i){
					Insert(tree[root].son[i], x, y);

				}
			}
		}
	}

}

int query(int root, int a, int b, int r){
	if (!tree[root].IN(a, b, r))
		return 0;
	int ans = 0;
	if (tree[root].div){
		for (int i = 0; i < 4; ++i){
			ans += query(tree[root].son[i], a, b, r);
		}
	}
	else{
		for (int i = 0; i < tree[root].num; ++i){
			int x = vp[root][i].x;
			int y = vp[root][i].y;
	//		if (sqrt((x - a)*(x - a) + (y - b)*(y - b)) <= r)
			if (lessequal(sqrt((x - a)*(x - a) + (y - b)*(y - b)),r))
				ans++;
		}
	}
	return ans;
}


int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	maxx = maxy = 0;
	minx = miny = 30000;
	size = 0;
	for (int i = 0; i < N; ++i){
		cin >> data[i].x >> data[i].y;
		if (maxx < data[i].x)
			maxx = data[i].x;

		if (maxy < data[i].y)
			maxy = data[i].y;

		if (minx > data[i].x)
			minx = data[i].x;

		if (miny > data[i].y)
			miny = data[i].y;
	}
	newNode(minx, miny, maxx, maxy);
	for (int i = 0; i < N; ++i){
		Insert(0, data[i].x, data[i].y);
	}
	while (M--){
		int a, b, r;
		cin >> a >> b >> r;
		printf("%d\n", query(0, a, b, r));
	}
	return 0;
}