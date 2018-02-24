#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define INF (100000010)


int N, size, root;
struct Node{
	int l, r, val, fa, id, size;
	long long sum;
	int d;
	void init(int _val,int _id, int _fa){
		sum = d = 0;
		l = r = -1;
		val = _val;
		fa = _fa;
		id = _id;
		size = 1;
	}
}data[300000];

void Init(){
	size = 0;
}

int alloc(int v, int id,int f){
	data[size].init(v, id,f);
	return size++;
}

void pushup(int x){
	long long l, r;
	int ls, rs;
	l = r = ls = rs = 0;
	if (data[x].l != -1){
		l = data[data[x].l].sum;
		ls = data[data[x].l].size;
	}
	if (data[x].r != -1){
		r = data[data[x].r].sum;
		rs = data[data[x].r].size;
	}
	data[x].size = ls + rs + 1;
	data[x].sum = l + r + data[x].val + (long long)data[x].d*data[x].size;
}

void pushdown(int x){
	if (data[x].d){
		int d = data[x].d;
		data[x].d = 0;
		data[x].val += d;
		if (data[x].l != -1){
			data[data[x].l].d += d;
		
		}
		if (data[x].r != -1){
			data[data[x].r].d += d;
		
		}
	
	}
}

int insert(int p, int v,int id){
	int ret;
	while (1){
		pushdown(p);
		if (data[p].id > v){
			if (data[p].l == -1){
				ret = data[p].l = alloc(v,id, p);
				break;
			}
			p = data[p].l;
		}
		else{
			if (data[p].r == -1){
				ret = data[p].r = alloc(v,id, p);
				break;
			}
			p = data[p].r;
		}
	}
	return ret;
}



void r_rorate(int x){
	int p = data[x].fa;
	int g = data[p].fa;
	int xrson = data[x].r;
	pushdown(p);
	pushdown(x);
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
	pushup(p);
	//pushup(x);
}

void l_rorate(int x){
	int p = data[x].fa;
	int g = data[p].fa;
	int xlson = data[x].l;
	pushdown(p);
	pushdown(x);
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
	pushup(p);
	//pushup(x);
}

void splay(int x, int f){
	pushdown(x);
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
	pushup(x);
}


void findlower(int x, int k, int& idx, int& id){
	if (x == -1)
		return;
	if (data[x].id <= k){
		if (data[x].id > id){
			idx = x;
			id = data[x].id;
		}
		findlower(data[x].r, k, idx, id);
	}
	else{
		findlower(data[x].l, k, idx, id);
	}
}



void findupper(int x, int k, int& idx, int& id){
	if (x == -1)
		return;
	if (data[x].id >= k){
		if (data[x].id < id){
			idx = x;
			id = data[x].id;
		}
		findupper(data[x].l, k, idx, id);
	}
	else{
		findupper(data[x].r, k, idx, id);
	}
}


#define MMAX  (1000000000)
void getInput(int n){
	ofstream out("C:\\input.txt");
	out << n << endl;
	srand(time(0));
	for (int i = 0; i < n; ++i){
		int cmd = rand() % 4;
		if (cmd == 0){
			out << "I " << abs(rand()) % MMAX + 1 << " " << abs(rand()) % MMAX + 1 << endl;
		}
		else if (cmd == 1){
			out << "Q " << abs(rand()) % MMAX + 1 << " " << abs(rand()) % MMAX + 1 << endl;
		}
		else if (cmd == 3){
			out << "M " << abs(rand()) % MMAX + 1 << " " << abs(rand()) % MMAX + 1 << " " << abs(rand()) % MMAX + 1 << endl;
		}
		else{
			out << "D " << abs(rand()) % MMAX + 1 << " " << abs(rand()) % MMAX + 1 << endl;

		}
	}
}

int main(){
	///ifstream in("C:\\input.txt");
//	getInput(50000);
//	return 0;
	cin >> N;
	root = alloc(0,0,0);
	data[root].l = alloc(0, -INF, root);
	insert(data[root].l, 0, INF);
	while (N-- > 0){
		char c;
		cin >> c;
		if (c == 'I'){
			int id, val;
			cin >> id >> val;
			splay(insert(data[root].l, val, id), root);
		}
		else if (c == 'Q'){
			int a, b, x1, x2, id1, id2;
   			id1 = -INF-10;
			id2 = INF+10;
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			findlower(data[root].l, a - 1, x1, id1);
			findupper(data[root].l, b + 1, x2, id2);
			splay(x1, root);
			splay(x2, x1);
			printf("%lld\n", data[data[x2].l].sum);
		}
		else if (c == 'M'){
			int a, b, d, x1, x2, id1, id2;
			id1 = -INF - 10;
			id2 = INF + 10;
			cin >> a >> b >> d;

			if (a > b)
				swap(a, b);
			findlower(data[root].l, a - 1, x1, id1);
			findupper(data[root].l, b + 1, x2, id2);
			splay(x1, root);
			splay(x2, x1);

			data[data[x2].l].d += d;
			pushup(data[x2].l);
			pushup(x1);
		}
		else{
			int a, b, x1, x2, id1, id2;
			id1 = -INF - 10;
			id2 = INF + 10;
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			findlower(data[root].l, a - 1, x1, id1);
			findupper(data[root].l, b + 1, x2, id2);
			splay(x1, root);
			splay(x2, x1);
			data[x2].l = -1;
			pushup(x2);
			pushup(x1);
		}


	}

	return 0;
}