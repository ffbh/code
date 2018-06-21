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

int n;
string s;



void input(){
	in>>s;



}

int mod = 9973;
int H[100010];
int pw[100010];

int qpow(int a,int b){
    if(a == 0)
        return a;
    int ret = 1;
    while(b){
        if(b&1){
            ret = (ret * a) % mod;
        }
        a = a*a%mod;
        b/=2;
    }
    return ret%mod;
}

int main(){

	int TEST_CASE = 1;

	while (in>>n){
		input();
        int len = s.length();
        s = "-"+s;
        H[0] = 1;
		for(int i=1;i<=len;++i){
		   H[i] = ((int)s[i]-28) * H[i-1] % mod;
		}
        while(n-->0){
		    int a,b;
		    in>>a>>b;
		    if(a>b)
		        swap(a,b);
		    int ans = H[b];
		    int div = qpow(H[a-1],mod-2);
            printf("%d\n",ans * div % mod);

		}













	}


	return 0;
}





