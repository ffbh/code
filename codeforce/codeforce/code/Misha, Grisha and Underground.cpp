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
#define MMAX ((int)1e5+10)
#define MMAD (20)
vector<int> vi[MMAX];
int n, q;

int deep[MMAX], f[MMAX][MMAD];

void dfs(int p,int dep,int fa){
//	cout << p << endl;
	deep[p] = dep;
	f[p][0] = fa;
	for (int son : vi[p]){
		if (son == fa)
			continue;
		dfs(son,  dep + 1,p);
	}
}

void Init(){
	for (int j = 1; (1 << j) <= n;++j)
	for (int i = 1; i <= n;++i)
	if (f[i][j - 1] != -1)
		f[i][j] = f[f[i][j - 1]][j - 1];
}

int lca(int a,int b){
	if (deep[a] < deep[b])
		swap(a, b);

	for (int j = MMAD-1; j >= 0; --j){
		if (deep[a] - (1 << j) >= deep[b])
			a = f[a][j];
	}

	if (a == b)
		return a;
	for (int j = MMAD-1; j >= 0; --j){
		if (f[a][j] != -1 && f[a][j] != f[b][j]){
			a = f[a][j];
			b = f[b][j];
		}
	}
	return f[a][0];
}

int cale(int a, int b, int t){
	int ab = lca(a, b);
	int bt = lca(b, t);
	int at = lca(a, t);
	int d;
	if (ab == bt){
		d = at;
		
	}
	else if (ab == at){
		d = bt;
	
	}
	else{
		d = ab;
	
	}
	int fa = lca(t, d);
	return deep[t] + deep[d] - 2 * deep[fa] + 1;
}

int main(){
	//ifstream in("C:\\input.txt");

	istream& in = cin;
	in >> n >> q;
	for (int i = 2; i <= n; ++i){
		int t;
		in >> t;
		vi[i].push_back(t);
		vi[t].push_back(i);
	}
	memset(f, -1, sizeof(f));
	dfs(1, 0, -1);
	Init();
	while (q-- > 0){
		int a, b, c;
		in >> a >> b >> c;
		int a1 = cale(a, b, c);
		int a2 = cale(a, c, b);
		int a3 = cale(b, c, a);
		printf("%d\n", max(a1, max(a2, a3)));

	}














	return 0;
}





