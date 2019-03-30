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
pair<pii,int> Q[200010];

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
		in >> Q[i].first.first >> Q[i].first.second;
		Q[i].second = i - 1;
	}

}

vector<int> edge[200010];

//inline void del_edge(int p){
//	int _a = ppp[p];
//	int _b = edge[p];
//	edge[_a] = _b;
//	ppp[_b] = _a;
//
//}

int dp[200010];
vector<int> ret;
//void cale(int pos){
//	ret.clear();
//	while (pos != -1){
//		vis[pos] = 1;
//		ret.push_back(pos);
//		if (edge[pos] == pos)
//			break;
//		pos = edge[pos];
//	}
//}

int h[200010];

int E[200010];


//int dfs(int pos,int aim,int RRR){
//	if (pos == -1){
//		E[RRR] = 1e7;
//		return -1;
//	}
//	if (dp[pos] != -1){
//		pos = dp[pos];
//	}
//	if (b[pos] == aim){
//		E[RRR] = pos;
//		return pos;
//	}
//	else{
//		int ret = dfs(edge[pos], aim,RRR);
//		if (ret == -1){
//			return pos;
//		}
//		else{
//			dp[pos] = ret;
//			return ret;
//		}
//	}
//}


bool cmp(pair<pii, int> p1, pair<pii, int> p2){
	if (p1.first.first != p2.first.first)
		return p1.first.first > p2.first.first;
	else if (p1.first.second != p2.first.second)
		return p1.first.second > p2.first.second;
	else{
		return p1.second < p2.second;
	}
}

vector<int> path;
bool vis[200010];
void dfs(int p){
	if (vis[p])
		return;
	path.push_back(p);
	if (path.size() >= n){
		E[p] = path[path.size() - n];
	}
	for (int son : edge[p]){
		dfs(son);
	}
	path.pop_back();
}

int main(){


	ret.resize(200010);

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= m; ++i){
			edge[i].clear();
		//	ppp[i] = i - 1;
			E[i] = 1e7;
			dp[i] = -1;
		}

		for (int i = 1; i <= n; ++i){
			ne[a[i]] = a[get_ne(i)];
			pe[a[i]] = a[get_pe(i)];
			
		}


		for (int i = m; i >= 1; --i){
			h[b[i]] = i;
			int pp = ne[b[i]];
			if(h[pp]){
				edge[h[pp]].push_back(i);
	//			edge[i] = h[pp];
			}
		}

		for (int i = 1; i <= m; ++i){
			dfs(i);
			//for (int j = 0;j+n-1<(int)ret.size(); ++j){
			//	int k = j + n - 1;
			//	E[ret[j]] = ret[k];
			//}
		}

		

		sort(Q + 1, Q + q + 1,cmp);

		string ans(q, '0');
		int pos = m + 1;
		int mmin = 1e7;
		for (int i = 1; i <= q; ++i){
			int l = Q[i].first.first;
			int r = Q[i].first.second;
			int Index = Q[i].second;
			while (pos > l){
				pos--;
				mmin = min(mmin, E[pos]);
			}
			if (r >= mmin){
				ans[Index] = '1';
			}
		}

	
		cout << ans<<endl;







	}


	return 0;
}





