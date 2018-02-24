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
#define lson (root<<1)  
#define rson (root<<1|1)  

int mod = 2008;

int quick_mod(int a,int p,int m){
	a %= m;
	int ret = 1;
	while (p){
		if (p & 1)
			ret = ret*a%m;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

void sub(int& a,int b){
	a %= mod;
	b %= mod;
	a -= b;
	a %= mod;
	if (a < 0)
		a += mod;
}

unordered_map<int, int> M;

int dfs(int n){
	if (M.count(n)){
		return M[n];
	}
	int S = (int)sqrt(n);
	int all = quick_mod(2, n, mod);
	for (int i = 1; i <= S; ++i){
		if (n % i == 0){
			sub(all, dfs(i));
			int p = n / i;
			if (p != n && p != i){
				sub(all, dfs(p));
			}
		}
	}
	return M[n] = all;
}

int main(){

	M[1] = M[2] = 2;
	int N;
	while (in>>N){
		printf("%d\n", dfs(N));



	}


	return 0;
}





