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

int n, q;
int C[200010];
vector<int> vi[200010];
vector<pair<pii,int> > Q;

void Init(){
	for (int i = 0; i < 200010; ++i)
		vi[i].clear();
	memset(C, 0, sizeof(C));
	Q.clear();

}



void input(){
	in >> n >> q;
	for (int i = 1; i < n; ++i){
		int a, b;
		in >> a >> b;
	//	scanf("%d%d", &a, &b);
		vi[a].push_back(b);
		vi[b].push_back(a);
	}



	for (int i = 1; i <= q; ++i){
		int l, r;
		in >> l >> r;
		Q.push_back(mp(mp(l, r),i));

	}

}




int lowbit(int x){
	return x&(-x);
}


void add(int p){
	while (p <= n){
		C[p]++;
		p += lowbit(p);
	}
}

int query(int p){
	int sum = 0;
	while (p){
		sum += C[p];
		p -= lowbit(p);
	}
	return sum;
}


int dp[200010], ans[200010];

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		Init();
		input();

		dp[0] = 0;
		for (int i = 1; i <= n; ++i){
			dp[i] = dp[i - 1] + 1;
			for (int son : vi[i]){
				if (son < i){
					dp[i]--;
				}
			}
		}

		sort(Q.begin(), Q.end());



		int ll = 0;
		for (pair<pii,int> pp : Q){
			pii& p = pp.first;
			if (p.first == 2){
				int t = 0;
			}
			while (ll < p.first - 1){
				ll++;
				for (int son : vi[ll]){
					if (son > ll)
						add(son);
				}
			
			}
			LL ak = dp[p.second] - dp[p.first - 1];
			LL bk = query(p.second) - query(p.first - 1);
			ans[pp.second] = ak + bk;
		}
		for (int i = 1; i <= q; ++i)
			printf("%d\n", ans[i]);

		
		

	

		




	}


	return 0;
}





