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

void input(){
	in>>n;


}


LL mod = 1000000007;

LL dp[10010][3];
//0-->kong need
//1-->kong not
//2-->full

LL pw[10010];

void add(LL& a,LL b){
    a%=mod;
    b%=mod;
    a+=b;
    a%=mod;
    if(a<0)
        a+=mod;
}

LL dfs(int len,int mark){
    assert(len > 0);
    LL& ref = dp[len][mark];
    if(ref != -1)
        return ref;
    if(len == 1){
        return ref = 1;
    }
    ref = 0;
    if(mark == 0){
        ref = pw[len-1];

    }
    else if(mark == 1){
      //  add(ref,2L*dfs(len,0));
        add(ref,2L*dfs(len-1,0));
        add(ref,dfs(len,2));
        add(ref,2L*dfs(len-1,2));
    }
    else{

        add(ref,2L * dfs(len-1,1));
    }

    return ref;


}

int main(){
    memset(dp,-1,sizeof(dp));
    pw[0] = 1;
    for(int i=1;i<10010;++i)
        pw[i] = pw[i-1] * 2 % mod;



	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if(n == 1){
		    cout<<2<<endl;
		}
		else{
		    LL ans = 0;
		    for(int i=1;i<=n;++i){
		        if(i==1 || i == n){
		            add(ans,2L * dfs(n,1));
		        }
		        else{

		            LL t1 = dfs(i,0) * dfs(n-i+1,2) % mod;
		            add(t1,t1);
		            LL t2 = dfs(n-i+1,0) * dfs(i,2) % mod;
		            add(t2,t2);
		            add(ans,t1+t2);
		      //      cout<<t1+t2<<endl;
		        }
		    }
		    printf("%lld\n",ans);
		}














	}


	return 0;
}





