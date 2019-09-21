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
ifstream in("/Users/jiazhi.zhou/CLionProjects/acm/InOutput/input.txt");
#define Debug(v) cerr<<#v<<"="<<v<<'\n'
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#define Debug(v) ;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)
#define FFLUAHALL fflush(stdin);fflush(stdout);



LL n,m,k;
LL a[100010];


void input(){
    in>>n>>m>>k;
    for(int i=1;i<=m;++i) {
        in >> a[i];
        a[i]--;
    }


}

void _init(){



}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		 _init();
		input();
		sort(a+1,a+m+1);
		LL pos = 1;
		LL ans = 0;

		while(pos <= m){
		    ans ++;
		    LL del = pos - 1;
		    LL page_first = (a[pos] - del) / k * k;

		    while(pos <= m && (a[pos] - del) / k * k == page_first){
		        pos++;
		    }
		   // cout<<pos<<endl;
		}

        cout<<ans<<endl;













	}


	return 0;
}





