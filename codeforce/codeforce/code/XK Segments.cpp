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


LL n, x, k;
LL a[100010];
LL ans;

vector<pll> all;




void input(){
	in >> n >> x >> k;
	for (int i = 0; i < n; ++i)
		in >> a[i];


}

pll cale(LL s){

	if (s == 10){
		int t = 0;
	}

	LL aim = s + k * x;
	if (s%x == 0){
		aim -= x;
	}

	LL mod = x - 1 - s%x;
	LL up = aim + mod;
	LL down = aim / x*x;
	if (down < s)
		down = s;
	
	
	return mp(down, up);
}

LL sum[100010];


LL search(LL p){
	int L = 0, R = all.size() - 1;
	LL ret = 0;
	while (L <= R){
		int mid = (L + R) / 2;
		if (all[mid].first <= p){
			ret = sum[mid];
			L = mid + 1;
		}
		else{
			R = mid - 1;
		}
	}
	assert(ret >= 0);
	return ret;
}

LL cale(pll & p){
	if (p.first > p.second)
		return 0;
	LL lf = search(p.first - 1);
	LL rt = search(p.second);
	return rt - lf;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(a, a + n);

		for (int i = 0; i < n; ++i){
			if (all.empty() || all.back().first != a[i]){
				all.push_back(mp(a[i], 1));
			}
			else{
				all.back().second++;
			}
		}

		sum[0] = all[0].second;
		for (int i = 1; i < all.size(); ++i)
			sum[i] = sum[i - 1] + all[i].second;

		ans = 0;
		
		for (pii lf : all){
			pll p = cale(lf.first);
			
			ans += lf.second * cale(p);
		}

		
		cout << ans << endl;











	}


	return 0;
}





