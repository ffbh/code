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


int n;
vector<pii> vi[200010];


void input(){
	in >> n;
	for (int i = 1; i < n; ++i){
		int a, b;
		in >> a >> b;
		vi[a].push_back(mp(b, i));
		vi[b].push_back(mp(a, i));
	}


}


int deep[200010], F[200010], edge_id[200010];
bool mark[200010];
void DFS(int p,int f){
	for (pii son : vi[p]){
		if (son.first == f)
			continue;
		deep[son.first] = deep[p] + 1;
		edge_id[son.first] = son.second;
		F[son.first] = p;
		DFS(son.first, p);
	}
}

int get_root(int p){
	deep[p] = 0;
	DFS(p, -1);
	F[p] = -1;
	int ret = 1;
	for (int i = 1; i <= n; ++i){
		if (deep[ret] < deep[i]){
			ret = i;
		}
	}
	return ret;
}

int A[200010], B[200010], pos;
LL ans;
pii ANS[200010];
void add(int a, int b, int c){
	A[pos] = a;
	B[pos] = b;
	ans += c;
	pos++;
}

void dfs(int p ,int f,int dep,int ans_root){
	for (pii son : vi[p]){
		if (mark[son.second] || son.first == f)
			continue;
		dfs(son.first, p, dep + 1,ans_root);
	}
	if (f != -1){
		add(p, ANS[ans_root].second, dep + ANS[ans_root].first);
	}
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int RA = get_root(1);
		int RB = get_root(RA);

		vector<int> R;
		int t = RB;
		R.push_back(t);
		while (t != RA){
			mark[edge_id[t]] = 1;
			t = F[t];
			R.push_back(t);
		}

		for (int i = 0; i < R.size(); ++i){
			int a = i;
			int b = R.size() - 1 - i;
			if (a < b){
				ANS[R[i]].first = b;
				ANS[R[i]].second = R.back();
			}
			else{
				ANS[R[i]].first = a;
				ANS[R[i]].second = R[0];
			}
		}

		for (int r : R){
			if (r == 2){
				int t = 0;
			}
			dfs(r, -1,0,r);
		}

		for (int i = R.size() - 1; i > 0; --i){
			add(R[i], R[0], i);
		}

		cout << ans << endl;
		for (int i = 0; i < pos; ++i)
			printf("%d %d %d\n", A[i], B[i], A[i]);





	}


	return 0;
}





