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
int a[1010][1010];


void input(){



}


int main(){

	while (in >> n && n != 0){
		for (int i = 1; i <= n;++i)
		for (int j = 1; j <= n; ++j){
			in >> a[i][j];
		}
		bool ok = 1;
		for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= n; ++j){
			if (a[i][j] + a[i - 1][j - 1] != a[i - 1][j] + a[i][j - 1]){
				ok = 0;
			}
		}
		if (ok){
			cout << "homogeneous" << endl;
		}
		else{

			cout << "not homogeneous" << endl;
		}

	}

	return 0;
}





