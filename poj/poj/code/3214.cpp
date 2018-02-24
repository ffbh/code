#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int H;

int V[21][1050000];
struct Node{
	int mmax, mmin;
}node[21][1050000];

void first_dfs(int h,int pos){
	if (h == H){
		node[h][pos].mmax = node[h][pos].mmin = V[h][pos];
		return;
	}
	first_dfs(h + 1, pos * 2 - 1);
	first_dfs(h + 1, pos * 2);
	int son_max = max(node[h + 1][pos * 2 - 1].mmax, node[h + 1][pos * 2].mmax);
	int son_min = min(node[h + 1][pos * 2 - 1].mmin, node[h + 1][pos * 2].mmin);
	node[h][pos].mmax = max(V[h][pos], son_max);
	node[h][pos].mmin = min(V[h][pos], son_min);
}

int dfs(int h,int pos,int limit_max,int limit_min){
	if (h == H){
		if (V[h][pos] <= limit_max && V[h][pos] >= limit_min)
			return 0;
		else
			return 1;
	}
	bool change = 1;
	if (V[h][pos] <= limit_max && V[h][pos] >= limit_min)
		change = 0;
	int ret;
	int root = V[h][pos];
	int l_son_max = node[h + 1][pos * 2 - 1].mmax;
	int r_son_min = node[h + 1][pos * 2].mmin;
	int l_son = V[h + 1][pos * 2 - 1];
	int r_son = V[h + 1][pos * 2];



	return ret;
}

int main(){
	ifstream in("C:\\input.txt");
	in >> H;
	int num = 1;
	for (int i = 1; i <= H; ++i){
		for (int j = 1; j <= num; ++j){
			in >> V[i][j];
		}
		num *= 2;
	}
	first_dfs(1, 1);
	cout << dfs(1, 1, node[1][1].mmax, node[1][1].mmin) << endl;


	return 0;
}