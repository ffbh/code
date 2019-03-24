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
	for (int i = 1; i <= Q; ++i)
		in >> a[i].first >> a[i].second;

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
	M.insert(mp(mp(1, N), N));
	for (int i = 1; i <= Q; ++i){

		if (m == 3 && i ==3){
			int t = 0;
		}
		int L = a[i].first;
		int R = a[i].second;
		vector<map<pii, int>::iterator> del;
		map<pii, int>::iterator ptr = M.upper_bound(mp(a[i].first, a[i].first));
		if (ptr != M.begin()){
			ptr--;
		}
		int block = 0;
		map<pii, int>::iterator first = ptr;
		map<pii, int>::iterator last = ptr;
		while (ptr != M.end() && ptr->first.first <= R){
			int uu = get_union(ptr->first, a[i]);
			if (uu <= ptr->second){
				int free_block = min(ptr->second, uu);
				block += free_block;
				del.push_back(ptr);
				last = ptr;
				last->second -= free_block;
			}
			ptr++;
		}

		pair<pii, int> FIRST = mp(mp(first->first.first, first->first.second), first->second);
		FIRST.first.second = L - 1;
		pair<pii, int> LAST = mp(mp(last->first.first,last->first.second), last->second);
		LAST.first.first = R + 1;
		
		if (block < m)
			return 0;
		for (auto ppp : del){
			M.erase(ppp);
		}
		M[a[i]] = block - m;
		if (FIRST.first.first <= FIRST.first.second)
			M[FIRST.first] = FIRST.second;
		if (LAST.first.first <= LAST.first.second)
			M[LAST.first] = LAST.second;

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

		sort(a + 1, a + Q + 1, cmp);
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





