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
ifstream in("/home/fbh/CLionProjects/acm/InOutput/input.txt");
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



LL n,A,B;

bool ok(LL a,LL b){

    while(a!=1){
        b/=2;
        if(b==1)
            return 1;
        a/=2;
    }
    return 0;

}

int getMin(LL k){
    if(k==1)
        return 1;
    LL l,r;
    l = 1;
    r = k;
    LL ans = 0;
    while(l<=r){
        LL m = (l+r)/2;
        if(ok(m,k)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    assert(ans > 0);
    return ans;
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
    int C = 1;
	while (TEST_CASE-- > 0){
		A = B = 0;
		in>>n;
		for(int i=1;i<=n;++i){
			LL x,y;
            in>>x>>y;
            if(x > y){
                LL d = getMin(y);
                A += x/d-1;
            }
            else if(x < y){
                LL d = getMin(x);
                B += y/d-1;

            }
		}

        printf("Case %d: ",C++);

        if(A > B){
            printf("Alice\n");
        }
        else{
            printf("Bob\n");
        }













	}


	return 0;
}





