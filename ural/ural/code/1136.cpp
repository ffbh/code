#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
struct Node{
	int val, l, r;
}data[3010];
int a[3010], b[3010];
int h[70000];
int root, N, t, size;
void Init(){
	size = 0;
}

int alloc(int val){
	data[size].val = val;
	data[size].l = data[size].r = -1;
	return size++;
}

void show(int p){
	if (p == -1)
		return;
	show(data[p].r);
	show(data[p].l);
	printf("%d\n", data[p].val);
}

int pos;

int dfs(int l, int r){
	int hh = h[a[pos]];
	int p = alloc(a[pos]);
	if (hh < r){
		--pos;
		data[p].r = dfs(hh + 1, r);
	}
	if (hh > l){
		--pos;
		data[p].l = dfs(l, hh - 1);
	}
	return p;
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		for (int i = 1; i <= N; ++i){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + N + 1);
		for (int i = 1; i <= N; ++i)
			h[b[i]] = i;
		pos = N;
		root = dfs(1, N);
		show(root);






	}
















	return 0;
}