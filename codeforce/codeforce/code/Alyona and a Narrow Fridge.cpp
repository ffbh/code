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


LL n, k;
LL a[1010];

void input(){
	in >> n >> k;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}
LL b[1010];
bool ok(LL m){
	for (int i = 1; i <= m; ++i){
		b[i] = a[i];
	}
	sort(b + 1, b + m + 1);
	LL sum = 0;
	for (int i = m; i >= 1; i -= 2){
		sum += b[i];
	}
	return sum <= k;


}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL l = 0;
		LL r = n;
		LL ans = 0;
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

		cout << ans << endl;












	}


	return 0;
}





