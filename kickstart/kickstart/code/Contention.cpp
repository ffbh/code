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

int N, Q;
pii a[30010];

void input(){
	in >> N >> Q;
	for (int i = 1; i <= Q; ++i){
		in >> a[i].first >> a[i].second;
	}
}

inline int book(int limit,int end){
	return max(end - limit, 0);

}

inline int get_union(pii a,pii b){
	int x = max(a.first, b.first);
	int y = min(a.second, b.second);
	return max(0, y - x + 1);
}



bool ok(int m){
	

	map<pii, int> M;
	int line = -1;
	for (int i = 1; i <= Q; ++i){
		int L = a[i].first;
		int R = a[i].second;
		while (L - 1 > line && !M.empty()){
			if (M.begin()->first.first < L){
				int e = M.begin()->first.first;
				assert(e >= line);
				M.begin()->second += e - line;
				line = e;
				if (M.begin()->second < m){
					return 0;
				}
				M.erase(M.begin());
			}
			else{
				assert(L - 1 >= line);
				M.begin()->second += L - 1 - line;
				line = L - 1;
				break;
			}
		}
		line = L - 1;
		M.insert(mp(mp(R, i), 0));
		//while (!M.empty() /*&& M.begin()->first.first < R*/ && M.begin()->second >= m){
		//	M.erase(M.begin());
		//}
	/*	auto it = M.lower_bound(mp(R, i));
		if (it == M.begin())
			continue;
		--it;
		while (1) {
			if (it->second >= m) {
				if (it == M.begin()) {
					M.erase(it);
					break;
				}
				else {
					auto bef = it;
					--it;
					M.erase(bef);
				}
			}
			else
				break;
		}*/
	}
	while (!M.empty()){
		int e = M.begin()->first.first;
		assert(e >= line);
		M.begin()->second += e - line;
		line = e;
		if (M.begin()->second < m){
			return 0;
		}
		M.erase(M.begin());
	}
	return 1;
}

bool cmp(pii a, pii b){
	int lena = a.second - a.first + 1;
	int lenb = b.second - b.first + 1;
	if (lena != lenb){
		return lena < lenb;
	}
	else{
		return a < b;
	}
}

int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a + 1, a + Q + 1);
		int ans = 0;
		
	
		int l = 1, r = N;
		while (l <= r){
			int m = (l + r) / 2;
			
			if (ok(m)){
				ans = m;
				l = m + 1;
			}
			else{
				r = m - 1;
			}
		}
		

		printf("Case #%d: %d\n", CPP++, ans);











	}


	return 0;
}





