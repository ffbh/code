#pragma comment(linker, "/STACK:10240000000,10240000000") 
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
ifstream in("C:\\input.txt");
//istream& in = cin;
#define MAXN (200010)
int n, q;
pair<int, int> edge[MAXN * 2];
struct Node{
	int to, d, idx;
};
struct Tree{
	Tree(){
		memset(C,0, sizeof(C));
		memset(f, -1, sizeof(f));
	}

	vector<pair<int,int> > vi[MAXN];
	long long C[MAXN * 2];
	int f[MAXN][25];
	int hw[MAXN];
	int sonid[MAXN], deep[MAXN], fa[MAXN], fd[MAXN], froot[MAXN], size[MAXN], ID[MAXN], PRE[MAXN], SIZE;
	int lowbit(int x){
		return x&(-x);
	}

	void add(int x, int w){
		while (x < MAXN){
			C[x] += w;
			x += lowbit(x);
		}
	}

	long long query(int x){
		long long sum = 0;
		while (x){
			sum += C[x];
			x -= lowbit(x);
		}
		return sum;
	}
	
	
	int pre_dfs(int u, int dep){

		size[u] = 1;
		deep[u] = dep;
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i].first;
			size[u] += pre_dfs(v, dep + 1);
		}
		return size[u];
	}


	void dfs(int u, int pre){
		if (vi[u].size() == 0)
			return;
		int mmax = -1, id, v;
		for (pair<int, int>& p : vi[u]){
			if (size[p.first] > mmax){
				mmax = size[p.first];
				v = p.first;
				id = p.second;
			}
		}

		hw[id] = SIZE;
		ID[SIZE++] = id;
		add(SIZE - 1, fd[edge[id].second]);

		if (pre == -1){
			PRE[id] = SIZE - 1;
		}
		else{
			PRE[id] = pre;
		}

		dfs(v, PRE[id]);

		for (pair<int, int>& p : vi[u]){
			if (p.first == v){
				continue;
			}
			dfs(p.first, -1);
		}
	}

	bool lca(int a, int b){
		if (deep[a] >= deep[b])
			return 0;
		for (int i = 24; i >= 0; --i){
			if (deep[b] - (1 << i) >= deep[a]){
				b = f[b][i];
			}
		}
		return a == b;
	}


	long long cale(int p){
		long long sum = 0;
		while (p != 1){
			if (hw[sonid[p]] == 0){
				sum += fd[p];
				p = fa[p];
			}
			else{
				int id = sonid[p];
				//		long long a = query(hw[id]);
				//		long long b = query(PRE[id] - 1);
				sum += query(hw[id]) - query(PRE[id] - 1);
				p = edge[ID[PRE[id]]].first;
			}
		}
		return sum;
	}





}start;



vector<pair<int, int> > vi[MAXN];

int hw[MAXN];
int sonid[MAXN], deep[MAXN], fa[MAXN], fd[MAXN], froot[MAXN], size[MAXN], ID[MAXN], PRE[MAXN], SIZE;
int f[MAXN][25];
long long C[MAXN * 2];

int lowbit(int x){
	return x&(-x);
}

void add(int x, int w){
	while (x < MAXN){
		C[x] += w;
		x += lowbit(x);
	}
}

long long query(int x){
	long long sum = 0;
	while (x){
		sum += C[x];
		x -= lowbit(x);
	}
	return sum;
}



void input(){

	SIZE = 1;

	in >> n >> q;
	//scanf("%d%d", &n, &q);
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n - 1; ++i){
		int a, b, c;
			in >> a >> b >> c;
	//	scanf("%d%d%d", &a, &b, &c);
		edge[i].first = a;
		edge[i].second = b;
		fa[b] = a;
		f[b][0] = a;
		fd[b] = c;
		sonid[b] = i;
		vi[a].push_back(make_pair(b, i));
		if (a != 1){
			start.f[a][0] = b;
			start.fd[a] = c;
			start.fa[a] = b;
			start.sonid[a] = i;
			start.vi[b].push_back(make_pair(a, i));
		}

	}
	for (int i = n; i <= 2 * n - 2; ++i){
		int a, b, c;
			in >> a >> b >> c;
	//	scanf("%d%d%d", &a, &b, &c);
		edge[i].first = a;
		edge[i].second = b;
		froot[a] = c;

		start.f[a][0] = b;
		start.fd[a] = c;
		start.fa[a] = b;
		start.sonid[a] = i;
		start.vi[b].push_back(make_pair(a, i));

	}


	for (int k = 1; k<25; ++k){
		for (int i = 1; i <= n; ++i)
		if (f[i][k - 1] != -1){
			f[i][k] = f[f[i][k - 1]][k - 1];
		}
	}

	for (int k = 1; k<25; ++k){
		for (int i = 1; i <= n; ++i)
		if (start.f[i][k - 1] != -1){
			start.f[i][k] = start.f[start.f[i][k - 1]][k - 1];
		}
	}

}


int pre_dfs(int u, int dep){

	size[u] = 1;
	deep[u] = dep;
	for (int i = 0; i < vi[u].size(); ++i){
		int v = vi[u][i].first;
		size[u] += pre_dfs(v, dep + 1);
	}
	return size[u];
}


void dfs(int u, int pre){
	if (vi[u].size() == 0)
		return;
	int mmax = -1, id, v;
	for (pair<int, int>& p : vi[u]){
		if (size[p.first] > mmax){
			mmax = size[p.first];
			v = p.first;
			id = p.second;
		}
	}

	hw[id] = SIZE;
	ID[SIZE++] = id;
	add(SIZE - 1, fd[edge[id].second]);

	if (pre == -1){
		PRE[id] = SIZE - 1;
	}
	else{
		PRE[id] = pre;
	}

	dfs(v, PRE[id]);

	for (pair<int, int>& p : vi[u]){
		if (p.first == v){
			continue;
		}
		dfs(p.first, -1);
	}
}

bool lca(int a, int b){
	if (deep[a] >= deep[b])
		return 0;
	for (int i = 24; i >= 0; --i){
		if (deep[b] - (1 << i) >= deep[a]){
			b = f[b][i];
		}
	}
	return a == b;
}


long long cale(int p){
	long long sum = 0;
	while (p != 1){
		if (hw[sonid[p]] == 0){
			sum += fd[p];
			p = fa[p];
		}
		else{
			int id = sonid[p];
			//		long long a = query(hw[id]);
			//		long long b = query(PRE[id] - 1);
			sum += query(hw[id]) - query(PRE[id] - 1);
			p = edge[ID[PRE[id]]].first;
		}
	}
	return sum;
}




int main(){
	//	output();
	//	return 0;
	input();
	pre_dfs(1, 0);

	dfs(1, -1);
	
	while (q-- > 0){
		int code, a, b;
		in >> code >> a >> b;
		if (code == 1){
			if (hw[a] != 0){
				add(hw[a], b - fd[edge[a].second]);
			}
			if (start.hw[a] != 0){
				start.add(hw[a], b - start.fd[edge[a].second]);
			}
			if (a <= n - 1){
				fd[edge[a].second] = b;
			}
			else{
				froot[edge[a].first] = b;
			}
		}
		else{
			if (a == 4 && b == 2){
				int t = 0;
			}

			if (a == b)
				printf("0\n");
			else if (lca(a, b)){
				cout << cale(b) - cale(a) << endl;
			}
			else{
				long long tmp = cale(b);
				long long t2 = start.cale(a);
				cout << cale(b) + start.cale(a) << endl;

			}

		}


	}
















	return 0;
}

