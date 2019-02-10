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
int a[1010];

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		int ansT, ans = (int)1e8;
		for (int t = 1; t <= 100; ++t){
			int sum = 0;
			for (int i = 1; i <= n; ++i){
				if (a[i] != t){
					sum += min(abs(a[i] - t - 1), abs(a[i] - t + 1));
				}
			}
			if (sum < ans){
				ans = sum;
				ansT = t;
			}

		}

		cout << ansT << " " << ans << endl;










	}


	return 0;
}





