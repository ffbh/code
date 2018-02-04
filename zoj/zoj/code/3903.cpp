#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
const long long mod = 1000000007;
int T;
long long L;
long long inv2, inv6;
long long quick_mod(long long a,long long m){
	a %= mod;
	long long ret = 1;
	while (m){
		if (m & 1){
			ret = (ret*a) % mod;
		}
		a = (a*a) % mod;
		m /= 2;
	}
	return ret;
}

long long cf(long long n){
	return (n%mod)*((n + 1) % mod) % mod*inv2%mod;
}


long long pf(long long n){
	return (n%mod)*((n + 1) % mod) % mod*((2 * n + 1) % mod) % mod*inv6%mod;
}

long long lf(long long n){
	long long p = (n%mod)*((n + 1) % mod) % mod*inv2%mod;
	return p*p%mod;
}



int main(){
	ifstream in("C:\\input.txt");
	inv2 = quick_mod(2, mod - 2);
	inv6 = quick_mod(6, mod - 2);
	cin >> T;
	while (T-- > 0){
		cin >> L;
		long long time = cf(L);
		long long ans = 0;
		ans = (ans + time * (L%mod)%mod * (L%mod)) % mod;

		long long a = ((pf(L) - lf(L)) % mod + mod) % mod;
		long long b = ((quick_mod(L, 2) + L) % mod)*(cf(L)) % mod;

		ans = (ans + a + b ) % mod;

		long long k = (2 * quick_mod(L, 4) + 3 * quick_mod(L, 3) + quick_mod(L, 2)) % mod*inv6%mod;

		long long k1 = (-8 * lf(L)) % mod;
		long long k2 = (((6 * L + 9) % mod)*pf(L)) %mod;
		long long k3 =( mod-cf(L))%mod;
		
		long long sumk = ((k1 + k2 + k3) % mod*inv6%mod + mod) % mod;
		ans = (ans + k + sumk) % mod;


		cout << (ans%mod+mod)%mod << endl;



	}

	return 0;
}