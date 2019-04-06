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
LL a[100010];
pll Q[100010];
unsigned long long ans[100010];
void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];
	
	in >> q;
	for (int i = 1; i <= q; ++i){
		LL l, r;
		in >> l >> r;
		Q[i] = mp(r - l + 1, i);
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();



		sort(Q + 1, Q + q + 1);
	
		set<LL> S;
		for (int i = 1; i <= n; ++i){
			S.insert(a[i]);
		}
		int KKK = 1;
		for (LL s : S){
			a[KKK++] = s;
		}
		n = KKK - 1;
		map<LL, int> M;
		for (int i = 1; i < n; ++i){
			M[a[i + 1] - a[i]]++;
		}
	
		LL num = S.size();
		LL val = 0;
		LL last = 0;
		auto ptr = M.begin();
		for (int KK = 1; KK <= q; ++KK){
			LL len = Q[KK].first;
			while (ptr != M.end() && ptr->first < len){
				LL ppp = (ptr->first - last) * num;
				num -= ptr->second;
				last = ptr->first;
				val += ppp;
				ptr++;

			}
			val += num * (len - last);
			ans[Q[KK].second] = val;
			last = len;
		}


		for (int i = 1; i <= q; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;









	}


	return 0;
}





