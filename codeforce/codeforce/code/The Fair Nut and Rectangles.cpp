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


int n;
vector<pair<pll, LL> > xya;
#define cost(k) (xya[k].second)

void input(){
//	in >> n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		LL x, y, a;
//		in >> x >> y >> a;
		scanf("%lld%lld%lld", &x, &y, &a);
		xya.push_back(mp(mp(x, y), a));
	}
}

inline LL get_kth(int k){
	LL pre = 0;
	if (k > 0){
		pre = xya[k - 1].first.first;
	}
	return (xya[k].first.first - pre) * xya[k].first.second;
}


LL dp[1000010][2];

inline LL cale_kth(int k,LL x){
	LL X = xya[k].first.first;
	LL Y = xya[k].first.second;
	LL del = xya[k].second;
	return (X - x)*Y - del;
}

inline LL catch_time(int fast,int slow){
	double y_fast = xya[fast].first.second;
	double y_slow = xya[slow].first.second;
	double extra = abs(xya[fast].first.first - xya[slow].first.first) * y_slow;
	LL len = ceil((xya[fast].second - xya[slow].second + extra) / (y_fast - y_slow));
	if (len < 0){
		len = 0;
	}
	return xya[fast].first.first - len;
}


inline bool ok(int a,int b,int c){
	return catch_time(b, a) > catch_time(c, b);
}


LL leftX;
deque<int> Q;
inline void cale(int k){

//	assert(!Q.empty());

	/*LL now = cale_kth(k, leftX);
	while (!Q.empty()){
		LL back = Q.back();
		LL end = cale_kth(back, leftX);
		if (now < end){
			break;
		}
		Q.pop_back();
	}*/

	while (Q.size() >= 2){
		int small = Q[Q.size() - 1];
		int large = Q[Q.size() - 2];
		if (ok(large, small, k)){
			break;
		}
		Q.pop_back();
	}
	Q.push_back(k);

	while (Q.size() >= 2){
		LL v1 = cale_kth(Q[0], leftX);
		LL v2 = cale_kth(Q[1], leftX);
		if (v1 > v2)
			break;
		Q.pop_front();
	}
}

int main(){



	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(xya.begin(), xya.end());

		Q.clear();

		dp[n - 1][0] = 0;
		dp[n - 1][1] = get_kth(n - 1) - cost(n - 1);
		Q.push_back(n - 1);
	//	xya[n - 1].second -= dp[n - 1][1] + get_kth(n - 1);

		LL pre = 0;
		for (int k = n - 2; k >= 0; --k){

			leftX = 0;
			if (k > 0){
				leftX = xya[k - 1].first.first;
			}

			LL add = get_kth(k) - cost(k);
		

			dp[k][1] = add + max(dp[k+1][0], dp[k + 1][1]);


			xya[k].second -= dp[k][1] - get_kth(k)+cost(k);

			cale(k);
			LL mmax = cale_kth(Q[0], leftX);

			dp[k][0] = max(mmax,(LL)0);

			pre = mmax;

		}


		cout << max(dp[0][0], dp[0][1]) << endl;

	}


	return 0;
}





