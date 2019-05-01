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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}

LL n,z;
LL a[200010];
bool vis[200010];
void input(){
	in >> n >> z;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}


}


bool ok(int mid){
	memset(vis, 0, sizeof(vis));
	int L = 1, R = mid + 1;
	int ans = 0;;
	while (R <= n){
		while (vis[L]){
			L++;
		}
		while (R <= L){
			R++;
		}
		if (R > n)
			break;
		if (a[R] - a[L] >= z){
			assert(!vis[L] && !vis[R]);
			ans++;
			vis[L] = vis[R] = 1;
		}
		R++;
	}
	return ans >= mid;



}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();


		sort(a + 1, a + n + 1);

		
		int L = 1;
		int R = n;
		int ans = 0;
		while (L <= R){
			int m = (L + R) / 2;
			if (ok(m)){
				ans = m;
				L = m + 1;
			}
			else{
				R = m - 1;
			}
		}

		cout << ans << endl;










	}


	return 0;
}





