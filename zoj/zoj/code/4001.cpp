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


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int N, M;
bool F[100010];
vector<pll> vi[100010];


struct Node{
	Node(pii p, LL _d){
		node = p;
		if (node.first > node.second){
			swap(node.first, node.second);
		}
		d = _d;
	}
	pii node;
	LL d;
	bool operator<(const Node& p)const{
		if (d != p.d)
			return d < p.d;
		else
			return node < p.node;
	}
};
vector<Node> vn;

struct U{
	U(){}
	U(LL a,LL b,int c){
		mmax = a;
		now = b;
		id = c;
	}
	LL mmax, now;
	int id;
	bool operator<(const U& p)const{
		if (mmax != p.mmax){
			return mmax > p.mmax;
		}
		else if (now != p.now){
			return now > p.now;
		}
		return id < p.id;
	}
};


LL A[100010], B[100010];
int pace[100010];
bool vis[100010];
void dij(int r){
	for (int i = 0; i <= N; ++i){
		A[i] = B[i] = LL(1e18);
		vis[i] = 0;
	}
	A[r] = 0;
	B[r] = 0;
	pace[r] = r;
	priority_queue<U> Q;
	Q.push(U(0,0,r));

	while (!Q.empty()){
		U u = Q.top(), v;
		Q.pop();
		if (vis[u.id]){
			continue;
		}
		vis[u.id] = 1;
		if (F[u.id]){
			if (u.id != r){
				vn.push_back(Node(mp(u.id,pace[u.id]),u.now));
			}
			u.now = 0;
			pace[u.id] = u.id;
		}


		for (pll p : vi[u.id]){
			v.id = (int)p.first;
			v.mmax = u.mmax;
			v.now = u.now + p.second;
			v.mmax = max(v.mmax, v.now);
			if (v.mmax < A[v.id] || v.mmax == A[v.id] && v.now < B[v.id]){
				pace[v.id] = pace[u.id];
				A[v.id] = v.mmax;
				B[v.id] = v.now;
				Q.push(v);
			}
		}

	}

}


vector<pii> AAA[100010];
LL ans[100010];
bool mark[100010];
int f[100010];

int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
	in >> N >> M;
	for (int i = 1; i <= N; ++i)
		in >> F[i];
	for (int i = 1; i <= M; ++i){
		int a, b, c;
		in >> a >> b >> c;
		vi[a].push_back(mp(b, c));
		vi[b].push_back(mp(a, c));
	}
	
	int root = -1;
	for (int i = 1; i <= N; ++i){
		if (F[i]){
			root = i;
			break;
		}
	}


	//assert(root != -1);
	dij(root);



	int q;
	in >> q;
	for (int i = 1; i <= q; ++i){
		int a, b;
		in >> a >> b;
		AAA[a].push_back(mp(b, i));
		AAA[b].push_back(mp(a, i));
		if (a != b)
			ans[i] = (LL)1e18;
		else
			ans[i] = 0;
	}

	sort(vn.begin(), vn.end());
	for (int i = 1; i <= N; ++i)
		f[i] = i;
	for (Node& p : vn){
		f[find(p.node.second)] = f[find(p.node.first)];

		int P;

		P = p.node.first;
		for (pii k : AAA[P]){
			if (find(k.first) == find(P)){
				ans[k.second] = min(ans[k.second], p.d);
			}
		}

		P = p.node.second;
		for (pii k : AAA[P]){
			if (find(k.first) == find(P)){
				ans[k.second] = min(ans[k.second], p.d);
			}
		}
	}

	for (int i = 1; i <= q; ++i){
		
		assert(ans[i] != (LL)1e18);
		printf("%lld\n", ans[i]);
	}




	return 0;
}





