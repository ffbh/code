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
ifstream in("/home/ffbh/CLionProjects/acm/InOutput/input.txt");
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


LL n,L,a;


void input(){
	in>>n>>L>>a;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		LL ans = 0;
		LL now = 0;
		for(int  i=1;i<=n;++i){
			int l,r;
			in>>l>>r;
			LL rest = l-now;
			ans += rest /a;
			now = l+r;
		}
		LL ree = (L - now)/a;
		cout<<ans + ree<<endl;


	}


	return 0;
}





