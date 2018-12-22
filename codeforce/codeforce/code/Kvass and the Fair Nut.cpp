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

LL n, s;
LL a[1010];


void input(){
	in >> n >> s;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

bool judge(LL m){
	LL sum = 0;
	for (int i = 1; i <= n; ++i){
		if (a[i] < m){
			return 0;
		}
		sum += a[i] - m;;
	}
	return sum >= s;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL sum = 0;
		for (int i = 1; i <= n; ++i){
			sum += a[i];
		}
		if (sum < s){
			cout << -1 << endl;
		}
		else{
			LL l = 0, r = 1e9, ans = 0;
			while (l <= r){
				LL mid = (l + r) / 2;
				if (l == 0 && r == 1){
					int t = 0;
				}
				if (judge(mid)){
					ans = mid;
					l = mid + 1;
				}
				else{
					r = mid - 1;
				}
			}
			cout << ans << endl;

		}











	}


	return 0;
}





