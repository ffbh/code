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


int n, a[200010];

void input(){
	in >> n;
	for (int i = 1l; i <= n; ++i){
		in >> a[i];
	}


}



int L[200010], R[200010], lsize, rsize;
bool upd[200010];
int idx[200010], val[200010];


int binary_sezrch(int l,int r,int v){
	int ret = r;
	while (l <= r){
		int mid = (l + r) / 2;
		if (R[mid] < v){
			ret = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return ret;
}

int insert_to_R(int v){
	if (rsize == 0 || R[rsize - 1] >= v){
		R[rsize++] = v;
		return rsize - 1;
	}
	else{
		int pos = binary_sezrch(0, rsize - 1, v);
		R[pos] = v;
		return pos;
	}
}

int bs(int l,int r,int v){
	int ret = r;
	if (v >= L[r])
		return r + 1;
	else if (v < L[l]){
		return 0;
	}
	else{
		int ret = 0;
		while (l <= r){
			int mid = (l + r) / 2;
			if (L[mid] <= v){
				ret = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		return ret + 1;

	}

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		for (int i = 1; i <= n; ++i)
			a[i] -= i;
	

		lsize = 0;
		for (int i = 1; i < n; ++i){
			if (lsize == 0 || L[lsize - 1] <= a[i]){
				idx[i] = lsize;
				upd[i] = 0;
				L[lsize++] = a[i];
			}
			else{
				upd[i] = 1;
				int p = upper_bound(L, L + lsize, a[i]) - L;
				val[i] = L[p];
				L[p] = a[i];
				idx[i] = p;
			}
		}
	
		int ans = n - lsize - 1;


		rsize = 0;
		for (int k = n - 1; k >= 1; --k){
			if (upd[k] == 0){
				lsize--;
			}
			else{
				L[idx[k]] = val[k];
			}

			int pos = insert_to_R(a[k + 1] + 1);
			int len = pos + 1 + bs(0, lsize - 1, a[k + 1] + 1);
			ans = min(ans, n - 1 - len);


		}
		cout << ans << endl;


















	}


	return 0;
}





