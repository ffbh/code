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

LL n, k, a, b, len;
LL gcd(LL p1,LL p2){
	if (p2 == 0)
		return p1;
	else{
		return gcd(p2, p1%p2);
	}
}

LL min_ans, max_ans;

void input(){
	in >> n >> k;
	in >> a >> b;


}


inline void update(LL A,LL B){
	LL l = B - A;
	if (l <= 0){
		l = n * k - l;
	}
	LL all = len;
	LL g = gcd(l, all);
	LL val = all / g;
	min_ans = min(min_ans, val);
	max_ans = max(max_ans, val);

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		min_ans = 1e15;
		max_ans = 0;

		len = n*k;

		for (int i = 0; i < n; ++i){
			update(a, b + i * k);
			update(a, (i + 1)*k - b);
			update(k - a, b + i * k);
			update(k - a, (i + 1)*k - b);
		}


		cout << min_ans << ' ' << max_ans << endl;









	}


	return 0;
}





