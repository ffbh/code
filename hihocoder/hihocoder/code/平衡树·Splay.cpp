#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define INF (1000000010)
int N, size, root;
struct Node{
	int l, r, val, fa;
	void init(int _val, int _fa){
		l = r = -1;
		val = _val;
		fa = _fa;
	}
}data[300000];

void Init(){
	size = 0;
}

int alloc(int v,int f){
	data[size].init(v, f);
	return size++;
}

int insert(int p,int v){
	while (1){
		if (data[p].val > v){
			if (data[p].l == -1){
				return data[p].l = alloc(v, p);
			}
			p = data[p].l;
		}
		else{
			if (data[p].r == -1){
				return data[p].r = alloc(v, p);
			}
			p = data[p].r;
		}
	}
}

void r_rorate(int x){
	int p = data[x].fa;
	int g = data[p].fa;
	int xrson = data[x].r;
	data[x].fa = g;
	if (data[g].l == p){
		data[g].l = x;
	}
	else{
		data[g].r = x;
	}
	if (xrson != -1){
		data[xrson].fa = p;
		data[p].l = xrson;
	}
	else
		data[p].l = -1;
	data[x].r = p;
	data[p].fa = x;
}

void l_rorate(int x){
	int p = data[x].fa;
	int g = data[p].fa;
	int xlson = data[x].l;
	data[x].fa = g;
	if (data[g].l == p){
		data[g].l = x;
	}
	else{
		data[g].r = x;
	}
	if (xlson != -1){
		data[xlson].fa = p;
		data[p].r = xlson;
	}
	else{
		data[p].r = -1;
	}
	data[x].l = p;
	data[p].fa = x;
}

void splay(int x,int f){
	while (data[x].fa != f){
		int p = data[x].fa;
		if (data[p].fa == f){
			if (x == data[p].l){
				r_rorate(x);
			}
			else{
				l_rorate(x);
			}
		}
		else{
			int g = data[p].fa;
			if (data[g].l == p&&data[p].l == x){
				r_rorate(p);
				r_rorate(x);
			}
			else if (data[g].l == p&&data[p].r == x){
				l_rorate(x);
				r_rorate(x);
			}
			else if (data[g].r == p&&data[p].l == x){
				r_rorate(x);
				l_rorate(x);
			}
			else{
				l_rorate(p);
				l_rorate(x);
			}
		}
	}
}

void findlow(int x, int k, int& idx, int& val){
	if (x == -1)
		return;
	if (data[x].val <= k){
		if (data[x].val > val){
			idx = x;
			val = data[x].val;
		}
		findlow(data[x].r, k, idx, val);
	}
	else{
		findlow(data[x].l, k, idx, val);
	}
}

void findlower(int x, int k, int& idx, int& val){
	if (x == -1)
		return;
	if (data[x].val <= k){
		if (data[x].val > val){
			idx = x;
			val = data[x].val;
		}
		findlow(data[x].r, k, idx, val);
	}
	else{
		findlow(data[x].l, k, idx, val);
	}
}

void findupp(int x, int k, int& idx, int& val){
	if (x == -1)
		return;
	if (data[x].val >= k){
		if (data[x].val < val){
			idx = x;
			val = data[x].val;
		}
		findupp(data[x].l, k, idx, val);
	}
	else{
		findupp(data[x].r, k, idx, val);
	}
}

void findupper(int x, int k, int& idx, int& val){
	if (x == -1)
		return;
	if (data[x].val >= k){
		if (data[x].val < val){
			idx = x;
			val = data[x].val;
		}
		findupp(data[x].l, k, idx, val);
	}
	else{
		findupp(data[x].r, k, idx, val);
	}
}

#define MMAX  (1000000000)
void getInput(int n){
	ofstream out("C:\\input.txt");
	out << n << endl;
	srand(time(0));
	for (int i = 0; i < n; ++i){
		int cmd = rand() % 3;
		if (cmd == 0){
			out << "I " << abs(rand()) % MMAX + 1 << endl;
		}
		else if (cmd == 1){
			out << "Q " << abs(rand()) % MMAX + 1 << endl;
		}
		else{
			out << "D " << abs(rand()) % MMAX + 1 << " " << abs(rand()) % MMAX + 1 << endl;
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
//	getInput(200000);
	//return 0;
	Init();
	root = alloc(-1, -1);
	data[root].l = alloc(-INF, root);
	insert(data[root].l, INF);
	cin >> N;
	while (N-- > 0){
		char c;
		int t1, t2;	
		int idx, val;
		int x1, x2, val1, val2;
		cin >> c;
		switch (c){
		case 'I':
			cin >> t1;
			//scanf("%d", &t1);
			splay(insert(data[root].l, t1), root);
			break;
		case 'Q':
			cin >> t1;
			//scanf("%d", &t1);
			val = -INF;
			findlow(data[root].l, t1, idx, val);
			printf("%d\n", val);

				
			break;
		case 'D':
			cin >> t1 >> t2;
			//scanf("%d%d", &t1, &t2);
			if (t1 > t2)
				swap(t1, t2);
			val1 = -INF-10;
			val2 = INF+10;
			findlower(data[root].l, t1-1, x1, val1);
			findupper(data[root].l, t2+1, x2, val2);
			splay(x1, root);
			splay(x2, x1);
			data[x2].l = -1;
			break;
		}
 	}
	return 0;
}