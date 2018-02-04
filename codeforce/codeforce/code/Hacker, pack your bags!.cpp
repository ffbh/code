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
#define MMAX (((int)1e5)+10)
int n, x;
struct Node{
	int l, r, c;
	bool operator<(const Node& p)const{
		if (l != p.l)
			return l < p.l;
		else if (r != p.r)
			return r < p.r;
		else
			return c < p.c;
	}
}data[2 * MMAX];
vector<Node> V[2 * MMAX];
int idx[2 * MMAX], ans;

void upd(int x){
	if (ans == -1){
		ans = x;
	}
	else {
		ans = min(ans, x);
	}
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> x;
	for (int i = 0; i < n; ++i){
		in >> data[i].l >> data[i].r >> data[i].c;
	}

	sort(data, data + n);
	for (int i = 0; i < n; ++i)
		V[data[i].r - data[i].l + 1].push_back(data[i]);
	for (int i = 0; i < 2 * MMAX; ++i){
		for (int j = (int)V[i].size() - 1; j>0; --j){
			V[i][j-1].c = min(V[i][j].c, V[i][j - 1].c);
		}
	}


	ans = -1;

	for (int i = 0; i < n; ++i){
		int a = data[i].r - data[i].l + 1;
		int b = x - a;
		if (b <= 0)
			continue;
		while (idx[b] < V[b].size() && data[i].r >= V[b][idx[b]].l){
			idx[b]++;
		}

		if (idx[b] < V[b].size()){
			upd(data[i].c + V[b][idx[b]].c);
		}
		if (ans == 49){
			int t = 0;
		}

	}

	cout << ans << endl;
	return 0;
}





