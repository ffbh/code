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


LL cale(LL n,LL m){
	if (m > n)
		return -1;
	LL k = n / m;
	
	return n*n - k*k;


}

LL x;
void input(){
	in >> x;
	//scanf("%lld", &x);


}


bool caa(LL n){
	LL L = 1, R = n;
	while (L <= R){
		LL mid = (L + R) / 2;
		LL ans = cale(n, mid);
		if (ans == x){
			printf("%lld %lld\n", n, mid);
			return 1;
		}
		else if (ans < x){
			L = mid + 1;
		}
		else{
			R = mid - 1;
		}

	}
	return 0;
}


int main(){
	
	
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		if (x == 0){
			printf("1 1\n");
			continue;
		}

		bool ok = 0;
		
		for (LL n = (LL)sqrt(x);  cale(n,2)<=x; n++){
			if (n == 36514){
				int t = 0;
			}
			if (caa(n)){
				ok = 1;
				break;
			}

		}
		if (!ok)
			printf("-1\n");












	}


	return 0;
}





