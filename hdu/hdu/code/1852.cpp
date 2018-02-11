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

ifstream in("C:\\input.txt");
//istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  




void input(){



}

LL N, K;

int MM[10010];
LL mod;

LL quick_mod(LL a,LL p,LL mod){
	a %= mod;
	LL ret = 1;
	while (p){
		if (p & 2)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

int main(){
	
	while (in >> N >> K){
		if (N == 0 && K == 0)
			break;


		memset(MM, -1, sizeof(MM));
		MM[0] = 1;
		LL pre = 1;
		for (int i = 1;; ++i){
			pre = pre * 2008 % K;
			if (MM[pre] == -1){
				MM[pre] = i;
			}
			else{
				mod = i - MM[pre];
				break;
			}
		}

		LL v2 = 3 * N;
		LL v251 = N;
		LL lf = (quick_mod(2, v2 + 1, mod) + mod - 1) % mod;
		LL rt = (quick_mod(251, v251, mod) + mod - 1) % mod*quick_mod(250, mod - 2, mod) % mod;




	}
	




	return 0;
}





