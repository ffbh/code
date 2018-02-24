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


LL n, mod, b0, A, B;
LL a[2000010], b[2000010], sum[2000010];

LL fac[2000010], inv[2000010];

LL qm(LL base,LL p){
	LL ret = 1;
	while (p){
		if (p & 1){
			ret = (ret*base) % mod;
		}
		base = (base*base) % mod;
		p /= 2;
	}
	return ret;
}

void Init(){
	fac[0] = 1;
	for (int i = 1; i <= 2 * n; ++i)
		fac[i] = fac[i - 1] * i%mod;
	inv[2 * n] = qm(fac[2 * n], mod - 2);
	for (int i = 2 * n - 1; i >= 0; --i){
		inv[i] = inv[i + 1] * (i+1)%mod;
	}
}

LL CNM(int N, int M){
	return fac[N] * inv[M] % mod*inv[N - M] % mod;

}

LL caleKTL(int N){
	return ((CNM(2 * N, N) - CNM(2 * N, N - 1)) % mod + mod) % mod;
}


int main(){

	int T;
	in >> T;
	while (T-- > 0){
	//	in >> n >> mod >> b0 >> A >> B;
		scanf("%lld%lld%lld%lld%lld", &n, &mod, &b0, &A, &B);
		a[0] = 0;
		b[0] = b0;
		for (int i = 1; i <= 2 * n; ++i){
			b[i] = (b[i - 1] * A + B) % mod;
		}
		for (int i = 1; i <= 2 * n; ++i){
			a[i] = (a[i - 1] + b[i] + 1) % mod;
		}
		sum[0] = 0;
		for (int i = 1; i <= 2 * n; ++i){
			sum[i] = (sum[i - 1] + a[i])%mod;
		}

		Init();

		LL ans = 0;
		for (int len = 2; len <= 2 * n; len += 2){
			LL lf = sum[2 * n - len + 1];
			LL rt = ((sum[2 * n] - sum[len - 1]) % mod + mod) % mod;
			LL add = ((rt - lf) % mod + mod) % mod;
			LL mul = caleKTL(len / 2 - 1)*caleKTL(n - len / 2) % mod;
			ans = (ans + add * mul) % mod;
		}

		ans = ans * qm(caleKTL(n),mod-2) % mod;

		printf("%lld\n", ans);


	}

	return 0;
}





