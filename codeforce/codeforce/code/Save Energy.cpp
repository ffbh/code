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


typedef unsigned long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


LL k, d, t;
double K, D, T;
void input(){
	in >> k >> d >> t;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		K = k;
		D = d;
		T = t;
		double ans;
		if (d >= k){
			double cyclelen = D;
			double fire = K + (D-K) / 2;
			ans = double(LL(T / fire));
			double rest = T - fire * ans;
			ans *= cyclelen;
			if (rest < K){
				ans += rest;
			}
			else{
				ans += K;
				rest -= K;
				ans += rest * 2;
			}
			
		}
		else{
			LL c = k / d*d;
			if (c < k)
				c += d;
			double cyclelen = c;
			double fire = K + double(c-k) / 2.0;
			ans = double(LL(T / fire));
			double rest = T - fire * ans;
			ans *= cyclelen;
			if (rest < K){
				ans += rest;
			}
			else{
				ans += K;
				rest -= K;
				ans += rest * 2;
			}
		




		}
		printf("%.10f\n", ans);













	}


	return 0;
}





