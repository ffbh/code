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


LL p, q;

LL gcd(LL a,LL b){
	if (b == 0)
		return a;
	else{
		return gcd(b, a%b);
	}
}

LL lcm(LL a, LL b){
	return a / gcd(a, b)*b;
}
int main(){
	while (in >> p >> q){
		if (p > q)
			swap(p, q);
		if (p == q){
			printf("%lld\n", p);
		}
		else{
			LL ans = 1e18;

			for (int base = 0; base <= p; base++){
				LL ret = base + lcm(p-base)
			}
			LL g = gcd(p, (q - p));
			LL ans = p / g * (q - p) + p;
			printf("%lld\n", ans);
		
		}
	}
	return 0;
}





