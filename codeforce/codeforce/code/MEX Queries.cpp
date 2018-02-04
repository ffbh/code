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
using namespace std;
#define MMAX ((int)1e5)
__int64 data[2 * MMAX + 10], size;
map<__int64, int> mii;
int type[MMAX];
__int64 L[MMAX], R[MMAX];
int N;
__int64 MAXR;
struct Node{
	int l, r;
	int state;//1 full   2 empty   0 no
}tree[2 * MMAX * 4 + 10];

void build(int root,int l,int r){
	tree[root].l = l;
	tree[root].r = r;
	tree[root].state = 2;
	if (l >= r - 1){
		
	}
	else{
		int mid = (l + r) / 2;
		build(root * 2, l, mid);
		build(root * 2 + 1, mid + 1, r);
	}
}


int upd(int root,int l,int r,int type){
	if (type == 3){
		int t = 0;
	}


	if (tree[root].l >= tree[root].r - 1){
		if (tree[root].l >= l && tree[root].r <= r){
			if (type == 1 || type == 2){
				tree[root].state = type;
			}
			else{
				tree[root].state = 3 - tree[root].state;
			}
		}
		return tree[root].state;
	}
	if (type == 1 || type == 2){
		if (tree[root].l >= l && tree[root].r <= r ){
			tree[root].state = type;
		}
		else{
			int a = upd(root * 2, l, r, type);
			int b = upd(root * 2 + 1, l, r, type);
			if (a != b){
				tree[root].state = 0;
			}
			else{
				tree[root].state = a;
			}
		}
	}
	else{
		if (tree[root].state == 1 || tree[root].state == 2){
			tree[root].state = 3 - tree[root].state;
		}
		else{
			int a = upd(root * 2, l, r, type);
			int b = upd(root * 2 + 1, l, r, type);
			if (a != b){
				tree[root].state = 0;
			}
			else{
				tree[root].state = a;
			}
		}
	}
	return tree[root].state;
}

__int64 query(int root){
	if (tree[root].state == 0){
		__int64 lret = query(root * 2);
		__int64 rret = query(root * 2 + 1);
		return min(lret, rret);
	}
	else if (tree[root].state == 1){
		return MAXR;
	}
	else{
		return data[tree[root].l-1];
	}
}



int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	in >> N;
	for (int i = 0; i < N; ++i){

		in >> type[i] >> L[i] >> R[i];
		data[i * 4] = L[i];
		data[i * 4 + 1] = R[i];
		if (L[i] > 1)
			data[i * 4 + 2] = L[i] - 1;
		else{
			data[i * 4 + 2] = L[i];
		}
		data[i * 4 + 3] = R[i] + 1;
	}
	size = 4 * N;
	sort(data, data + size);
	size = unique(data, data + size) - data;
	for (int i = 0; i < size; ++i)
		mii[data[i]] = i + 1;
	MAXR = data[size - 1];
	size--;

	build(1, 1, size);

	for (int i = 0; i < N; ++i){
		upd(1, mii[L[i]], mii[R[i]],type[i]);
		printf("%I64d\n", query(1));
	}

	return 0;
}





