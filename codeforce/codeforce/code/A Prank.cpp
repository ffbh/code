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
int a[110];

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

		int ans = 0;
		int pos = 1;
		while (pos <= n){
			int np = pos + 1;
			while (np <= n &&a[np] == a[np - 1] + 1){
				np++;
			}
			np--;
			int v1 = a[pos];
			int v2 = a[np];
			if (v1 == 1 || v2 == 1000){
				ans = max(ans, v2 - v1 + 1 - 1);
			}
			else{
				ans = max(ans, v2 - v1 + 1 - 2);
			}

			pos = np + 1;
		}

		cout << ans << endl;













	}


	return 0;
}





