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



int n = 9;
int a[100010];
bool mark[100010];//bool
LL mmin_limit;
bool judge(LL l, LL r){//LL
	mmin_limit = 1e15;
	for (int i = 0; i <= n + 1; ++i)
		mark[i] = 1;
	for (int i = 1; i <= n; ++i){
		if (mark[i] == 0){
			continue;
		}

		if (a[i] >= l&&a[i] <= r){
			mmin_limit = min(mmin_limit, (LL)a[i]);
		}
		else if (mark[i - 1] == 1 && a[i] + a[i - 1] >= l && a[i] + a[i - 1] <= r){
			mmin_limit = min(mmin_limit, (LL)(a[i]+a[i-1]));
		}
		else if (a[i] + a[i + 1] >= l && a[i] + a[i + 1] <= r){
			mmin_limit = min(mmin_limit, (LL)(a[i] + a[i + 1]));
			mark[i + 1] = 0;
		}
		else{
			return false;
		}
	}
	return true;
}


void input(){
	//in >> n;
	//for (int i = 1; i <= n; ++i)
	//	in >> a[i];
	    scanf("%d",&n);
	    for(int i=1;i<=n;++i)
	        scanf("%d",&a[i]);


}



int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;

	while (TEST_CASE-- > 0){
		input();

		LL limit = (LL)1e15;//LL
		set<int> S;//int
		for (int i = 1; i <= n; ++i){
			LL this_limit = max(max(a[i], a[i] + a[i + 1]), a[i] + a[i - 1]);
			limit = min(limit, this_limit);
		}



		for (int i = 1; i <= n; ++i){
			if (a[i] <= limit ){
				S.insert(a[i]);
			}
			if (a[i] + a[i - 1] <= limit ){
				S.insert(a[i] + a[i - 1]);
			}
			if (a[i] + a[i + 1] <= limit ){
				S.insert(a[i] + a[i + 1]);
			}
		}

	//	assert(S.size() < 1000);


		LL ans = (LL)1e15;//LL
		LL up_limit = -1e15;
		for (int down : S){
			if (down < up_limit)
				continue;
			LL l = 0, r = (LL)1e15;//LL
			while (l <= r){
				LL mid = (l + r) / 2;//LL
				if (judge(down, down + mid)){
					ans = min(ans, mid);
					r = mid - 1;
					up_limit = max(mmin_limit,up_limit);
				}
				else {
					l = mid + 1;
				}
			}
		}

		printf("%lld\n", ans);


	}


	return 0;
}




