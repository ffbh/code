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


bool deq(double a,double b){
	return fabs(a - b) < 1e-8;
}

int n;
double t;

int main(){
	cout << 637.0 / 500  << endl;
	while (in >> n >> t){
		if (n == 0)
			break;
		t = (t + 1) / 2.0;
		double ans = 1;
		for (int i = 1; i <= n; ++i)
			ans = ans * 2 * t;
		printf("%.3f\n", ans);



	}






	return 0;
}





