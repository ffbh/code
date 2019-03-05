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

LL f[100010];
LL inv[100010];
LL inv2[100010];
LL inv3[100010];
LL mod = 1e9 + 7;


void input(){
	in >> n >> m;
	// scanf("%lld%lld",&n,&m);


}

LL quick_mod(LL a, LL p){
	a %= mod;
	LL res = 1;
	while (p>0){
		if (p & 1)
			res = res*a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return res;
}

void Init(){
	f[0] = 1;
	for (int i = 1; i<100010; ++i)
		f[i] = f[i - 1] * i%mod;

	inv[100009] = quick_mod(f[100009], mod - 2);
	inv2[100009] = quick_mod(quick_mod(2, 100009), mod - 2);
	for (int i = 100008; i >= 0; --i){
		inv[i] = inv[i + 1] * (i + 1) % mod;
		inv2[i] = inv2[i + 1] * 2 % mod;
		inv3[i] = inv[i] * inv2[i] % mod;
	}
}

LL C(LL a, LL b){
	return f[a] * inv[b] % mod * inv[a - b] % mod;
}

LL B(LL a, LL b){


	if (b == 0)
		return 1;


	LL slot = a - b + 1;

	if (a <= 0){

		return 0;
	}
	if (slot < b){
		return 0;
	}
	else{
		return C(slot, b);
	}
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	Init();


//	cout << B(0, 0) << endl;

	while (TEST_CASE-- > 0){
		input();
	
	

		if (m > n){
			printf("0\n");
			continue;
		}

		if (m == 0){
			printf("1\n");
			continue;
		}

		cout << inv2[1] << endl;

		if (m == n){
			printf("%lld\n", f[n - 1] * inv2[1] % mod);
		}


		LL ans = 0;
		LL block = n - m;
		for (int k = max(0, int(n - 2 * m)); k <= n - m - 1; ++k){
			LL special_block = block - k;



			LL num = C(n, k) * B(max(int(n - k - 1 - 2), 0), n - k - 1 - m) % mod *
				inv3[special_block] % mod
				*f[n - k] % mod;

			//
			//            cout<<"k:"<<" "<<k<<endl;
			//            cout<<"C(n,k):"<<" "<<C(n,k)<<endl;
			//            cout<<"B(n-k-1,n-k-1-m):"<<" "<<B(n - k - 1,n-k-1-m)<<endl;
			//            cout<<"inv[special_block]:"<<" "<<inv[special_block]<<endl;
			//            cout<<"inv2[special_block]:"<<" "<<inv2[special_block]<<endl;
			//            cout<<"f[n-k]:"<<" "<<f[n-k]<<endl;
			//            cout<<"num"<<" "<<num<<endl;
			//            cout<<endl;
			//


			ans = (ans + num) % mod;
		}
		printf("%lld\n", ans);


	}


	return 0;
}




