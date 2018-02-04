#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
struct Line{
	double yu, yd;
	int flag;
	double x;
	bool operator<(const Line& p)const{
		return x < p.x;
	}
}line[210];
double y[410];
struct Node{
	double l, r;
	double x;
	bool leaf;
	int cover;
}data[50010];

void Build(int root,int l,int r){
	data[root].cover = 0;
	data[root].l = y[l];
	data[root].r = y[r];
	if (l == r-1){
		data[root].leaf = 1;
		return;
	}
	data[root].leaf = 0;
	int mid = (l + r) / 2;
	Build(root * 2, l, mid);
	Build(root * 2 + 1, mid, r);
}

double Update(int root,double x,double l,double r,int flag){
	if (data[root].r <= l || data[root].l >= r)
		return 0;
	if (data[root].leaf){
		double ans = 0;
		if (data[root].cover)
			ans += (x - data[root].x)*(data[root].r - data[root].l);	
		data[root].x = x;
		data[root].cover += flag;
		return ans;
	}
	return Update(root * 2, x, l, r, flag) + Update(root * 2 + 1, x,l, r, flag);
}





int main(){
	ifstream in("C:\\temp.txt");
	int size, cnty;
	int CASE = 1;
	while (in >> N&&N){
		size = cnty = 0;
		for (int i = 0; i < N; ++i){
			double x1, y1, x2, y2;
			in >> x1 >> y1 >> x2 >> y2;
			y[cnty++] = y1;
			y[cnty++] = y2;
			line[size].x = x1;
			line[size].yd = y1;
			line[size].yu = y2;
			line[size].flag = 1;
			size++;
			line[size].x = x2;
			line[size].yd = y1;
			line[size].yu = y2;
			line[size].flag = -1;
			size++;
		}
		sort(y, y + cnty);
		sort(line, line + size);
		Build(1, 0, cnty - 1);
		double ans = 0;
		for (int i = 0; i < size; ++i)
			ans += Update(1, line[i].x, line[i].yd, line[i].yu, line[i].flag);
		printf("Test case #%d\n",CASE++);
		printf("Total explored area: %.2f\n", ans);
	}
	return 0;
}