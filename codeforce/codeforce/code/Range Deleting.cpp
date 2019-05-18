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

int n, x;
int a[1000010];
int w[1000010];
int max_w[1000010];

void input(){
	in >> n >> x;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		for (int i = 1; i <= x; ++i){
			w[i] = x;
		}

		set<int> S;
		S.insert(0);
		int E = 1;
		for (int i = 1; i <= n; ++i){
			if (a[i] < *(--S.end())){
				int v = *S.upper_bound(a[i]);
				w[a[i]] = min(w[a[i]], v);
				max_w[a[i]] = max(max_w[a[i]], *(--S.end()));
				E = max(E, a[i]);
			}
			S.insert(a[i]);
		}


		LL ans = 0;
		int end = x;
		for (int i = 1; i <= end; ++i){
			E = max(E, i);
			ans += x - E + 1;
			end = min(end, w[i]);
			E = max(E, max_w[i]);
		}

		cout << ans << endl;












	}


	return 0;
}





