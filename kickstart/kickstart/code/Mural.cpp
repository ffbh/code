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
string s;

void input(){
	in >> n;
	in >> s;



}


inline int getScore(int pos){
	return s[pos] - '0';
}




int main(){

	int TEST_CASE = 1;
	int CPP = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int n = s.length() - s.length() / 2;
		int sum = 0;
		for (int i = 0; i < n; ++i){
			sum += getScore(i);
		}
		int ans = sum;
		int sl = 0, sr = n - 1;
		while (sr < s.length() - 1){
			sum -= getScore(sl);
			sl++;
			sr++;
			sum += getScore(sr);
			ans = max(ans, sum);
		}
		printf("Case #%d: %d\n", CPP++, ans);




	}


	return 0;
}





