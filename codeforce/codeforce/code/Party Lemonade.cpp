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



LL n, L;
LL boot[100];
LL val[100];
void input(){
	in >> n >> L;
	for (int i = 1; i <= n; ++i)
		in >> val[i];


}


LL dfs(LL L){
	if (L <= 0){
		return 0;
	}
	if (L == 1){
		int t = 0;
	}

	LL large = 1;
	int pos = -1;
	LL cost = 1e18;
	for (int k = 1; k <= n; ++k){
		if (boot[k] < L){
			large = boot[k];
			pos = k;
		}
		else{
			cost = min(cost, val[k]);
		}
	}
	if (pos == -1){
		return cost;
	}
	int mminidx = -1;
	LL mminprice = LL(1e18);

	for (int i = 1; i <= pos; ++i){
		LL now = large / boot[i] * val[i];
		if (now < mminprice){
			mminprice = now;
			mminidx = i;
		}
	}

	LL ret = L / boot[mminidx] * val[mminidx];// +dfs(L % boot[mminidx]);
	LL p = dfs(L%boot[mminidx]);
	return min(ret + p, cost);






}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		boot[1] = 1;
		for (int i = 2; i <= 50; ++i)
			boot[i] = boot[i - 1] * 2;

		

		cout << dfs(L) << endl;










	}


	return 0;
}





