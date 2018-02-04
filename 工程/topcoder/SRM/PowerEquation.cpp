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
using namespace std;

long long mod = 1e9 + 7;

bool vis[(int)1e5 + 10];

int gcd(int a, int b){
	if (b == 0)
		return a;
	else{
		return gcd(b, a%b);
	}
}

class PowerEquation {
public:
	int count(int N) {
		long long n = N;
		memset(vis, 0, sizeof(vis));
		long long p = floor(sqrt(n));
		long long ans = 0;
		ans = (ans + n*(2 * n - 1)) % mod;
		for (int i = 2; i <= p; ++i){
			if (vis[i])
				continue;
			long long mmax = 1;
			long long val = i;
			while (val <= n){
				if (val <= p)
					vis[val] = 1;
				val *= i;
				mmax++;
			}
			mmax--;
			for (int j = 1; j <= mmax; ++j)
			for (int k = j + 1; k <= mmax; ++k){
				int g = gcd(j, k);
				ans = (ans + n / (k / g) * 2) % mod;
			}

		}



		return (int)ans;
	}
};


#if 0
int main(){






	PowerEquation so;
	cout << so.count(100) << endl;


	return 0;
}
#endif






// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
