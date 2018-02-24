#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Node{
	int size;
	int l, r, d, u;
	int x, y;
};

struct DLX{
	const static int MMAX = 45010;
	vector<int> pace;
	Node p[MMAX];
	int size;
	int head[MMAX];
	int ans;
	void Init(int m){
		memset(head, -1, sizeof(head));
		for (int i = 0; i <= m; ++i){
			p[i].u = p[i].d = i;
			p[i].l = i - 1;
			p[i].r = i + 1;
			p[i].size = 0;
		}
		p[0].l = m;
		p[m].r = 0;
		ans = -1;/////
		pace.clear();
		size = m + 1;
	}
	void showmap(int n,int m,int kk){
		int k = n*m + 1;
		for (int i = 1; i <= kk; ++i){
			for (int j = 1; j <= n*m; ++j){
				if (p[k].x == i&&p[k].y == j){
					printf("%d ", k-n*m);
					k++;
				}
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
	void link(int row,int col){
		p[size].x = row;
		p[size].y = col;
		p[size].d = col;
		p[size].u = p[col].u;
		p[p[col].u].d = size;
		p[col].u = size;
		p[col].size++;
		if (head[row] == -1) head[row] = p[size].l = p[size].r = size;
		else{
			p[size].r = head[row];
			p[size].l = p[head[row]].l;
			p[p[size].l].r = size;
			p[p[size].r].l = size;
		}
		size++;
	}
	void del(int c){
		p[p[c].l].r = p[c].r;
		p[p[c].r].l = p[c].l;
		for (int i = p[c].d; i != c; i = p[i].d)
		for (int j = p[i].l; j != i; j = p[j].l){
			p[p[j].u].d = p[j].d;
			p[p[j].d].u = p[j].u;
			p[p[j].y].size--;
		}
	}
	void rse(int c){
		p[p[c].l].r = c;
		p[p[c].r].l = c;
		for (int i = p[c].u; i != c; i = p[i].u)
		for (int j = p[i].r; j != i; j = p[j].r){
			p[p[j].u].d = j;
			p[p[j].d].u = j;
			p[p[j].y].size++;
		}
	}
	void dfs(){
		if (ans != -1 && pace.size() >= ans)
			return;
		if (p[0].r == 0){
			if (ans == -1)
				ans = pace.size();
			else
				ans = min(ans, int(pace.size()));
			return;
		}
		int c = p[0].r;
		del(c);
		for (int i = p[c].d; i != c; i = p[i].d){
			pace.push_back(p[i].x);
			for (int j = p[i].r; j != i; j = p[j].r)
				del(p[j].y);
			dfs();
			for (int j = p[i].l; j != i; j = p[j].l)
				rse(p[j].y);
			pace.pop_back();
		}
		rse(c);
	}
}dlx;


int N, M, K;


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		//in >> N >> M >> K;
		scanf("%d%d%d", &N, &M, &K);
		dlx.Init(N*M);
		for (int k = 1; k <= K; ++k){
			int x1, y1, x2, y2;
		//	in >> x1 >> y1 >> x2 >> y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1++;
			y1++;
			for (int i = x1; i <= x2;++i)
			for (int j = y1; j <= y2; ++j)
				dlx.link(k, (i-1)*M + j);
		}
	//	dlx.showmap(N, M, K);
		dlx.dfs();
		cout << dlx.ans << endl;
	}
	return 0;
}