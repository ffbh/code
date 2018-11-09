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
ifstream in("/home/zhoujiazhi/CLionProjects/bbbb/InOutput/input.txt");
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

string str;



void input(){
    in>>str;


}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		reverse(str.begin(),str.end());

		LL ans = 0;
		LL p ,rp;
		p = rp = 0;
		LL len = 0;
		for(char c : str){
		    LL now,nnow;
		    len ++;
		    if(c == '0'){
		        now = 2 * (len) + p;
		        nnow = len + p;
		    }
		    else{
		    	now = len + rp;
                nnow = 2 * (len ) + rp;
            }

		    p = now;
		    rp = nnow;
		    ans += now;
	//	    printf("now : %lld  p %lld rp %lld\n",now,p,rp);
		}

		printf("%lld\n",ans);
//cout<<endl;
	}


	return 0;
}




