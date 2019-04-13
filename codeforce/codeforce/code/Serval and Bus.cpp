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


int n, t;
int a[100010], b[100010];
void input(){
	in >> n >> t;
	for (int i = 1; i <= n; ++i)
		in >> a[i] >> b[i];

}

int Get(int p){
	if (t <= a[p]){
		return a[p];
	}
	int dd = t - a[p];
	int v = b[p] - dd % b[p];
	v %= b[p];
	return t + v;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		int ans = 0;
		int mmin = 1e9;
		for (int i = 1; i <= n; ++i){
			int tt = Get(i);
			if (tt < mmin){
				mmin = tt;
				ans = i;
			}



		}


		cout << ans << endl;










	}


	return 0;
}





