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
LL a[5010];
LL sum[5010];



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];

	for (int i = 1; i <= n; ++i){
		sum[i] = sum[i - 1] + a[i];
	}

}

pll slove(int l,int r){
	if (l > r){
		return make_pair((LL)0, (LL)n+1);
	}
	
	LL all = sum[r] - sum[l - 1];
	LL ret = (LL)-1e18;
	LL idx;
	for (int i = l; i <= r; ++i){
		LL tmp = sum[i] - sum[l - 1];
		if (tmp + tmp - all > ret){
			ret = tmp + tmp - all;
			idx = i + 1;
		}
	}
	LL tmp = -all;
	if (tmp > ret){
		ret = tmp;
		idx = l;
	}

	tmp = all;
	if (tmp > ret){
		ret = tmp;
		idx = r + 1;
	}

	return make_pair(ret, idx);
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL ans = (LL)-1e18;
		LL ans1, ans2, ans3;
		for (int i = 1; i <= n; ++i){
			pll l = slove(1, i);
			pll r = slove(i + 1, n);
			if (ans < l.first + r.first){
				ans = l.first + r.first;
				ans1 = l.second;
				ans2 = i + 1;
				ans3 = r.second;
			}
		}


		cout << ans1-1 << " " << ans2-1 << " " << ans3-1 << endl;;
	
		//cout << ans << endl;







	}


	return 0;
}





