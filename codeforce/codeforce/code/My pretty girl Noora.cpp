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
using namespace std;
#define MMAX (((int)5e6)+10)
//#define MMAX (100)
int V[MMAX];
const long long mod = (long long)1e9 + 7;
int t, l, r;

long long  f[MMAX], tmm[MMAX];
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	

	in >> t >> l >> r;
	tmm[0] = 1;
	for (int i = 1; i < MMAX; ++i){
		V[i] = -1;
		tmm[i] = tmm[i - 1] * t%mod;
	}
	f[0] = 0;
	f[1] = 0;
	for (int k = 2; k <= r; ++k){
		f[k] = ((long long)k*(k - 1)) / 2;
		if (V[k] != -1){
			int p = V[k];
			long long tmp = min(f[p] + f[k / p] * p, f[k / p] + f[p] * (k / p));
			if (tmp < f[k]){
				f[k] = tmp;
			}
		}
		for (int j = k + k; j <= r; j += k)
		if (V[j] == -1){
			V[j] = k;
		}
	}
	long long ans = 0;
	for (int i = l; i <= r; ++i){
		ans = (ans + f[i]%mod * tmm[i-l] % mod) % mod;
	}
	

	cout << ans << endl;











	return 0;
}



