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


int N, S;

LL mod = 1e9 + 7;

void input(){
	in >> N >> S;


}

LL quick_mod(LL a,LL p){
	a %= mod;
	LL ret = 1;
	while (p){
		if (p & 1)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if (N == S){
			printf("1\n");
		}
		else{
			printf("%lld\n", S * quick_mod(N, N - S - 1) % mod);
		}













	}


	return 0;
}





