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


LL n, m;
LL a[100010];

void input(){
	in >> n >> m;
	//scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
	in >> a[i];
		//scanf("%lld", &a[i]);


}

LL now[100010];


void add(int p,LL tt,LL mmax){
	if (now[p] < mmax){

		LL need = mmax - now[p];
		LL cc = need / a[p] + (need % a[p] != 0 ? 1 : 0);
		if (cc <= tt){
			now[p] = 1e18;
		}
		else{
			now[p] += tt * a[p];
		}
	}
}

LL get(LL a1,LL a2){
	LL ans = a1 / a2;
	if (a1 % a2 != 0){
		ans++;
	}
	return ans;
}

bool ok(LL mid){
	now[0] = 0;
	for (int i = 1; i <= n; ++i){
		now[i] = get(mid,a[i]);
	}


	if (mid == 5){
		int t = 0;
	}

	LL time = m;
	int pos = 0;
	while (pos <= n){
		if (now[pos] > 0){
			LL cc = now[pos];
			if (time < cc * 2){
				return 0;
			}
			time -= cc * 2;
			now[pos] -= cc;
			now[pos + 1] -= cc;
		//	now[pos] += a[pos] * cc;
		//	now[pos + 1] += a[pos + 1] * cc;
		}
		
		if (time){
			time--;
			pos++;
	//		now[pos] += a[pos];
			now[pos]--;
		}
		else{
			break;
		}
	}
	for (int k = 1; k <= n; ++k){
		if (now[k] > 0){
			return 0;
		}
	}

	return 1;
}



int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		LL l = 0;
		LL r = (LL)1e18;
		LL ans = 0;
//		cout << r << endl;
		while (l <= r){
			LL mid = (l + r) / 2;
		//	cout << mid << endl;
			if (ok(mid)){
				ans = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		printf("%lld\n", ans);











	}


	return 0;
}





