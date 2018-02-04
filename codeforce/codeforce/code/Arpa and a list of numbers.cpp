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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

#define MAXN ((int)1e6+10)
LL n, x, y;
LL data[MAXN];
LL cnt[MAXN], sum[MAXN];

void input(){
	in >> n >> x >> y;
	for (int i = 1; i <= n; ++i){
		in >> data[i];
		cnt[data[i]]++;
		sum[data[i]] += data[i];
	}
	
	/*n = 500000;
	x = 1000000000;
	y = 200;

	for (int i = 1; i <= n-1; ++i){
		cnt[669707]++;
		sum[669707] += 669707;

	}

	cnt[991733] ++;
	sum[991733] += 991733;*/
}

void getInput(){
	

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i < MAXN; ++i){
			cnt[i] += cnt[i - 1];
			sum[i] += sum[i - 1];
		}
		LL ans = (LL)1e18;
		for (int g = 2; g < MAXN; ++g){

			LL div = x / y;
			if (x%y != 0)
				div++;
			
			LL tmp = 0;
			if (g == 669707){
				int t = 0;
			}
			for (int k = 1;; ++k){
				LL en = (LL)k*g;
				LL st = en - g + 1;
				if (en >= MAXN)
					en = MAXN - 1;
				if (st > (int)1e6 || st > en)
					break;

				

				LL mid = en - div;
				if (mid < st){
					mid = st - 1;
				}
				else{
					tmp += x * (cnt[mid] - cnt[st - 1]);
				}
				LL a = (cnt[en] - cnt[mid])*en;
				LL b = (sum[en] - sum[mid]);
				LL c = a - b;
				tmp += ((cnt[en] - cnt[mid])*(k*g) - (sum[en] - sum[mid]))*y;

				
				
			}
			
			ans = min(ans, tmp);
		}

	/*	if (n == 500000 && x == 1000000000 && y == 200){
			map<int, int> mii;
			for (int i = 1; i <= n; ++i)
				mii[data[i]]++;
			for (pii p : mii){
				cout << p.first << " " << p.second << endl;
			}


		}*/


		cout << ans << endl;


	}


	return 0;
}





