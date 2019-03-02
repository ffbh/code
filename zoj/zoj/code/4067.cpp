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

int n, m;
LL a[100010];


void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}


int get(LL mid){
	int num = 0;
	for (int i = 1; i <= n; ++i){
		if (mid >= a[i]){
			num++;
			mid -= a[i];
		}
	}
	return  num;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (m == n){
			printf("Richman\n");
			continue;
		}

		int zero = 0;
		for (int i = 1; i <= n; ++i){
			if (a[i] == 0){
				zero++;
			}
		}

		if (zero > m){
			printf("Impossible\n");
		}
		else{
			LL sum = 0;
			int need = m - zero;
			int pos = 1;
			while (need){
				if (a[pos] != 0){
					need--;
					sum += a[pos];
				}
				pos++;
			}
			LL mmin = 1e18;
			while (pos <= n){
				if (a[pos] != 0){
					mmin = min(a[pos], mmin);
				}
				pos++;
			}
			sum += mmin - 1;
			printf("%lld\n", sum);

		}



		/*LL sum = 0;
		for (int i = 1; i <= m; ++i){
			sum += a[i];
		}
		for (
			)


		sum += a[m + 1] - 1;

		if (a[m + 1] == 0){
			printf("Impossible\n");
		}
		else{
			printf("%lld\n", sum);
		}
*/



		//LL l = 0, r = (LL)1e17, ans = -1;
		//while (l <= r){
		//	LL mid = (l + r) / 2;
		//	int num = get(mid);


		//	if (num == m){
		//		ans = mid;
		//		l = mid + 1;
		//	}
		//	else if (num < m){
		//		l = mid + 1;
		//	}
		//	else{
		//		r = mid - 1;
		//	}
		//}
	
		//if (ans == -1){
		//	printf("Impossible\n");
		//}
		//else{
		//	/*printf("%lld\n", ans);*/


		//}











	}


	return 0;
}





