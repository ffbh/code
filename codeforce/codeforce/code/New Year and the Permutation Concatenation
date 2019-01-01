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

LL n;
LL mod = 998244353;

void input(){
	in >> n;


}

LL P[1000010];

void add(LL& a, LL b){
	assert(b >= 0);
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0)
		a += mod;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		P[1] = 1;
		for (int i = 2; i <= n; ++i)
			P[i] = P[i - 1] * i%mod;

		LL ans = P[n];

		LL mul = 1;
		for (LL k = n; k > 1; --k){
			add(ans, k * mul%mod * ((P[k - 1] - 1+ mod)%mod));
			mul = mul * k%mod;
		}
		cout << ans << endl;











	}


	return 0;
}





