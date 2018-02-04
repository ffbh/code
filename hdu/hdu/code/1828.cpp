#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
struct Line{
	int a, max,min, flag;
	bool operator<(const Line& p){
		if (a!=p.a)
			return a < p.a;
		return flag>p.flag;
	}
}Xline[10010], Yline[10010];
int X[20010], Y[20010];
struct Node{
	int cover;
	int l, r;
	bool leaf;
}data[500010];

void Build(int root, int l, int r, int* arr){
	data[root].cover = 0;
	data[root].l = arr[l];
	data[root].r = arr[r];
	if (l + 1 == r){
		data[root].leaf = 1;
		return;
	}
	data[root].leaf = 0;
	int mid = (l + r) / 2;
	Build(root * 2, l, mid, arr);
	Build(root * 2 + 1, mid, r,arr);
}

int Update(int root,int l,int r,int flag){
	if (data[root].r <= l || data[root].l >= r)
		return 0;
	if (data[root].leaf){
		int ans = 0;
		if (data[root].cover == 0||data[root].cover==1&&flag==-1 )
			ans = data[root].r - data[root].l;
		data[root].cover += flag;
		return ans;
	}
	return Update(root * 2, l, r, flag) + Update(root * 2 + 1, l, r, flag);
}






int main(){
	ifstream in("C:\\temp.txt");
	int cntx, cnty, size, x, y;
	while (cin >> N){
		cntx = cnty = size = x = y = 0;
		if (N == 0){
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < N; ++i){
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			X[x++] = x1;
			X[x++] = x2;
			Y[y++] = y1;
			Y[y++] = y2;
			Xline[cntx].a = x1;
			Xline[cntx].min = y1;
			Xline[cntx].max = y2;
			Xline[cntx].flag = 1;
			cntx++;
			Xline[cntx].a = x2;
			Xline[cntx].min = y1;
			Xline[cntx].max = y2;
			Xline[cntx].flag = -1;
			cntx++;
			Yline[cnty].a = y1;
			Yline[cnty].min = x1;
			Yline[cnty].max = x2;
			Yline[cnty].flag = 1;
			cnty++;
			Yline[cnty].a = y2;
			Yline[cnty].min = x1;
			Yline[cnty].max = x2;
			Yline[cnty].flag = -1;
			cnty++;
		}
		sort(Xline, Xline + cntx);
		sort(Yline, Yline + cnty);
		sort(X, X + x);
		sort(Y, Y + y);
		x = unique(X, X + x) - X;
		y = unique(Y, Y + y) - Y;
		int ans = 0;
		Build(1, 0, y - 1, Y);
		for (int i = 0; i < cntx; ++i)
			ans += Update(1, Xline[i].min, Xline[i].max, Xline[i].flag);
		Build(1, 0, x - 1, X);
		for (int i = 0; i < cnty; ++i)
			ans += Update(1, Yline[i].min, Yline[i].max, Yline[i].flag);
		cout << ans << endl;
	}
	return 0;
}