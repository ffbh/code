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


int n, k;
LL a[100010];
void input(){
	in >> n >> k;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}

}
LL ans;
inline void update(LL s,LL e){
	LL t = e * k - s;
	ans = min(ans, t);
}

int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a + 1, a + n + 1);

		int sl = 1;
		int sr = k;
		LL sum = 0;
		ans = (LL)1e18;
		for (int i = sl; i <= sr; ++i)
			sum += a[i];
		update(sum, a[sr]);
		while (sr < n){
			sum -= a[sl];
			sl++;
			sr++;
			sum += a[sr];
			update(sum, a[sr]);
		}

		//cout << ans << endl;
		printf("Case #%d: %lld\n", CPP++, ans);











	}


	return 0;
}





