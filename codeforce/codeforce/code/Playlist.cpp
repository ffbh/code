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


LL n, k;
pll tb[300010];
vector<int> V[1000010];


void input(){
	in >> n >> k;
	for (int i = 1; i <= n; ++i){
		in >> tb[i].first >> tb[i].second;
	}

}


bool cmp(pii a, pii b){
	return a.first > b.first;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sort(tb+1, tb + n+1,cmp);
		LL limit = 1;
		LL ans = 0;
		int num = 0;
		int pos = 0;
		LL all = 0;
		while (limit <= (int)1e6){
			while (num < k && pos < n ){
				pos++;
				if (tb[pos].second >= limit){
					V[tb[pos].second].push_back(tb[pos].first);
					all += tb[pos].first;
					num++;
				}
			}
			ans = max(ans, all * limit);
		
			for (int k : V[limit]){
				all -= k;
				num--;
			}
			limit++;
		}
		
		cout << ans << endl;







			 



	}


	return 0;
}





