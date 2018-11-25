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

void input(){
	in >> n;



}



int dfs(int v,int add){
	set<int> ss;
	int vv = 1;
	while (vv <= 50){
		ss.insert(vv);
		vv *= 2;
	}
	bool dd = 0;
	while (!ss.count(v)){
		v++;
		dd = 1;
	}
	int ans = 0;
	if (add || dd){
		ans++;
	}
	while (v != 1){
		ans++;
		v /= 2;
	}
	return ans;



	
}

int main(){





	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (n == 1){
			cout << 1 << " " << 0 << endl;
		}
		else{
			vector<pii> vp;
			for (int i = 2; i <= sqrt(n); ++i){
				int v1 = i;
				int v2 = 0;
				while (n % i == 0){
					v2++;
					n /= i;
				}
				if (v2){
					vp.push_back(mp(v1, v2));
				}
			}
			if (n != 1){
				vp.push_back(mp(n, 1));
			}

			set<int> all;
			int mmax = 0;
			int ans = 1;
			for (pii p : vp){
				mmax = max(mmax, p.second);
				ans *= p.first;
				all.insert(p.second);
			}
			int fff = 0;
			if (all.size() != 1){
				fff = 1;
			}
			cout << ans << " " << dfs(mmax,fff)  << endl;

	
		}














	}


	return 0;
}





