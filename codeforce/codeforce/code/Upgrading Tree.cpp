#pragma comment(linker, "/STACK:204800000,204800000") 
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
#include <cassert>
using namespace std;


//ifstream in("C:\\input.txt");
istream& in = cin;
struct Node{
	int x, y1, y2;
	Node(int a, int b, int c){
		x = a;
		y1 = b;
		y2 = c;
	}
};

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;
#define MMAX ((int)2e5+10)
vector<Node> ans;
vector<int> edge[MMAX];
int dfs(int p,int f){
	if (edge[p].size() == 1 && edge[p].back() == f){
		return p;
	}

	if (p == 9){
		int t = 0;
	}

	int ret;
	for (int son : edge[p]){
		if (son == f)
			continue;
		ret = dfs(son, p);
		ans.push_back(Node(p, son, ret));
	}
	return ret;
}


int n;
vector<int> vi[MMAX];

int pre_dfs(int p, int f, bool root){
	if (vi[p].size() == 1 && vi[p].back() == f){
		return p;
	}
	vector<pii> leaf;
	for (int son : vi[p]){
		if (son == f)
			continue;
		leaf.pb(mp(pre_dfs(son, p, 0),son));
	}
	
	if (root){
		if (p == 3){
			int t = 0;
		}
		for (int i = 0; i < leaf.size(); ++i){
			edge[leaf[i].first].push_back(p);
			edge[p].push_back(leaf[i].first);
		
				ans.push_back(Node(p, leaf[i].second, leaf[i].first));
		}
		return -1;
	}
	else{

		if (p ==11){
			int t = 0;
		}

		if (leaf.size() == 1){
			if (p == 2){
				int t = 0;
			}
			
			ans.push_back(Node(p, leaf[0].second, leaf[0].first));
			edge[p].push_back(leaf[0].first);
			edge[leaf[0].first].push_back(p);
			return leaf[0].second;
		}
		else{
			if (p == 7){
				int t = 0;
			}
			mark[f] = 1;
			ans.push_back(Node(f, p, leaf.back().first));
			int nowf = leaf.back().second;
			int nowp = p;
			for (int i = leaf.size() - 2; i >= 0; --i){
				ans.push_back(Node(nowf, nowp, leaf[i].first));

				edge[leaf[i].first].push_back(nowf);
				edge[nowf].push_back(leaf[i].first);
				nowf = leaf[i].second;
				nowp = p;

			}
			edge[p].push_back(nowf);
			edge[nowf].push_back(p);
		}
		return leaf.back().first;
	}
}


void input(){
	in >> n;
	for (int i = 1; i < n; ++i){
		int a, b;
		in >> a >> b;
		vi[a].pb(b);
		vi[b].pb(a);
	}
}
bool ok[MMAX];
int roota, rootb;
int get_root(int p,int f){
	int size = 1;
	for (int son : vi[p]){
		if (son == f)
			continue;
		int tmp = get_root(son, p);
		if (tmp < n - tmp){
			ok[son] = 1;
		}

		if ( n - tmp < tmp){
			ok[p] = 1;
		}

		size += tmp;
	}
	
	
	return size;
}




int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if (n <= 3){
			cout << 0 << endl;
			continue;
		}
		roota = rootb = -1;

		get_root(1, -1);
		vector<int> vp;
		for (int i = 1; i <= n;++i)
		if (!ok[i])
			vp.push_back(i);
		
		assert(vp.size() <= 2);

		roota = vp[0];
		if (vp.size() == 2){
			rootb = vp.back();
		}
		

		pre_dfs(roota, rootb, 1);
		if (rootb != -1){
			pre_dfs(rootb, roota, 1);
		}
		

		dfs(roota, -1);
		if (rootb != -1){
			dfs(rootb, -1);
		}

		printf("%d\n", ans.size());
		for (Node& p : ans){
			printf("%d %d %d\n", p.x, p.y1, p.y2);
		}




	}


	return 0;
}





