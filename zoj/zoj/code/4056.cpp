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


LL a,b,c,d,v,t;


void input(){
   // in>>a>>b>>c>>d>>v>>t;
   scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);


}

LL gcd(LL k1 ,LL k2){
    if(k1 == 0)
        return k2;
    else
        return gcd(k2%k1,k1);
}

LL getAns(LL limit){
    LL count = b + d -1;
    LL mmax = v;
    LL A = 1,C = 1;
    while( A * a != C * c ){
 //       assert();
//          if(A * a == C * c){
//              cout<<A<<" "<<C<<endl;
//
//          }



        if(A * a < C * c){
            if(A * a > limit){
                break;
            }
            if(A * a <= mmax){
                count += b;
            }
            else{
                count += b-1;
            }
            mmax = A * a + v;
            A++;
        }
        else{
            if(C * c > limit){
                break;
            }
            if(C * c <= mmax){
                count += d;
            }
            else{
                count += d-1;
            }
            mmax = C * c + v;
            C++;
        }

    }
    return count;

}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        if(a <= v || c <= v){
            printf("%lld\n",(t/a+1)*b + (t/c+1)*d-1);
            continue;
        }

        LL lcm = a / gcd(a,c)*c;
        LL time = t / lcm;
        LL rest = t % lcm;


//        LL all = getAns(lcm-1);
//        LL rr = getAns(rest);
//        cout<<all<<" "<<rr<<endl;

        printf("%lld\n",getAns(lcm - 1) * time + getAns(rest));




	}


	return 0;
}




