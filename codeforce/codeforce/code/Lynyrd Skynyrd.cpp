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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n, m, q;
int a[200010];
int b[200010];
pii Q[200010];

inline int get_ne(int _p){
	if (_p == n){
		return 1;
	}
	else{
		return _p + 1;
	}
}

inline int get_pe(int _p){
	if (_p == 1){
		return n;
	}
	else{
		return _p - 1;
	}
}
int ne[200010];
int pe[200010];


void input(){
	in >> n >> m >> q;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}

	for (int i = 1; i <= m; ++i){
		in >> b[i];
	}

	for (int i = 1; i <= q; ++i){
		in >> Q[i].first >> Q[i].second;
	}

}

int edge[200010];

//inline void del_edge(int p){
//	int _a = ppp[p];
//	int _b = edge[p];
//	edge[_a] = _b;
//	ppp[_b] = _a;
//
//}

bool vis[200010];
vector<int> ret;
void cale(int pos){
	ret.clear();
	while (pos != -1){
		vis[pos] = 1;
		ret.push_back(pos);
		if (edge[pos] == pos)
			break;
		pos = edge[pos];
	}
}

int h[200010];

int E[200010];

int main(){


	ret.resize(200010);

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= m; ++i){
			edge[i] = -1;
		//	ppp[i] = i - 1;
			E[i] = 1e7;
		}

		for (int i = 1; i <= n; ++i){
			ne[a[i]] = a[get_ne(i)];
//			pe[a[i]] = a[get_pe(i)];
			
		}


		for (int i = m; i >= 1; --i){
			h[b[i]] = i;
			int pp = ne[b[i]];
			if(h[pp]){
				edge[i] = h[pp];
				h[pp] = 0;
			}
		}

		for (int i = 1; i <= m; ++i){
			if (vis[i])
				continue;
			cale(i);
			for (int j = 0;j+n-1<(int)ret.size(); ++j){
				int k = j + n - 1;
				E[ret[j]] = ret[k];
			}
		}

		

		sort(Q + 1, Q + n + 1);
	//	int mmax = 0;
		for (int i = 1; i <= q; ++i){
			int l = Q[i].first;
			int r = Q[i].second;
		//	mmax = max(mmax, E[l]);
			if ( E[l] <= r){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}

	
		cout << endl;







	}


	return 0;
}





