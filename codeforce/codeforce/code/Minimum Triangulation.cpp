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


int n;


LL dp[510][510];

void input(){
	in >> n;


}

//ll dfs(int a,int b){
//	ll& ref = dp[a][b];
//	if (ref != -1){
//		return ref;
//	}
//	ref = (ll)1e18;
//	int st = a;
//	int en = a + b - 1;
//	assert(st + 1 >= en);
//	for (int k = st + 1; k < en; ++k){
//		ref = min(ref, st * k * (k+1) + dfs()
//	}
//	
//
//
//
//
//}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		LL ans = 0;
		for (int i = 2; i < n; ++i){
			ans += i*(i + 1);
		}
		cout << ans << endl;














	}


	return 0;
}





