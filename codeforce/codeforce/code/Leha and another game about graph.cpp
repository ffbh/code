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
#define MAXN ((3*(int)1e5)+10)
vector<pair<int,int> > vi[MAXN];
int d[MAXN];
int n, m;
void input(){
	
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		in >> d[i];
	for (int i = 1; i <= m; ++i){
		int u, v;
		in >> u >> v;
		vi[u].push_back(make_pair(v,i));
		vi[v].push_back(make_pair(u,i));
	}



}
int root, negepos, ansnum;
bool ans[MAXN], vis[MAXN];

int dfs(int p,int id){
	if (vis[p])
		return 0;
	vis[p] = 1;
	int ret = d[p];
	for (pair<int, int> pp : vi[p]){
		int son = pp.first;
		ret = (ret + dfs(son,pp.second)) % 2;
	}

	if (ret == 1){
		ans[id] = 1;
		ansnum++;
	}
	return ret;
}

bool judge(){
	root = -1;
	negepos = -1;
	int num = 0;
	for (int i = 1; i <= n; ++i){
		if (d[i] == 1){
			num++;
			root = i;
		}
		else if (d[i] == -1){
			negepos = i;
			d[i] = 0;
		}

	}
	if (negepos == -1 && num % 2 == 1)
		return 0;
	if (num % 2 == 1){
		d[negepos] = 1;
		root = negepos;
	}
	return 1;
}

int main(){
	input();

	if (!judge())
		printf("-1\n");
	else if (root == -1){
			printf("0\n");
	}
	else{
		ansnum = 0;
		dfs(root,0);
		printf("%d\n", ansnum);
		for (int i = 1; i <= m;++i)
		if (ans[i]){
			printf("%d\n", i);
		}
	}



	return 0;
}





