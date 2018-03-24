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
ifstream in("/home/fbh/CLionProjects/codeforce/input.txt");
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

LL n,d,b;
LL a[100010];

void input() {
    in>>n>>d>>b;
    for(int i=1;i<=n;++i)
        in>>a[i];

}

bool judge(LL ll,LL rr,LL laim,LL raim,LL share,LL k){
    laim-=k;
    raim-=k;
    if(ll >= laim){

    }
    else if(ll + share >= laim){
        share -= laim - ll;
    }
    else{
        return 0;
    }


    return rr + share >= raim;

}

int slove() {
    LL lsum, rsum, share, can_share;
    lsum = rsum = share = can_share = 0;
    LL L, R;
    L = 1, R = n;
    LL lp, rp;
    lp = 0;
    rp = n + 1;
    int Lans=0,Rans=0;
    while (L <= R) {

        LL len = L + L * d;
        LL LLL = len;
        while (lp < LLL && lp < n) {
            lp++;
            lsum += a[lp];
            if (lp >= rp) {
                can_share += a[lp];
            }

        }
        LL RR = n - len + 1;
        while (rp > RR && rp > 1) {
            rp--;
            rsum += a[rp];
            if (rp <= lp) {
                can_share += a[rp];
            }

        }


        share += can_share;
        lsum -= can_share;
        rsum -= can_share;
        can_share = 0;

        if(lsum >=b){
            lsum-=b;
        }
        else if(lsum + share >= b){
            share -= b - lsum;
            lsum=0;
        }
        else{
            Lans++;
        }

        if (L != R) {
            if(rsum >= b){
                rsum-=b;
            }
            else if(rsum + share >= b){
                share -= b-rsum;
                rsum=0;
            }
            else{
                Rans++;
            }


        }



        L++;
        R--;

    }



    return max(Lans,Rans);
}


int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        input();

        cout<<slove()<<endl;
//        LL L=0,R=n*b;
//        int ans=-1;
//        while(L<=R){
//            int mid = (L+R)/2;
//            if(slove(mid)){
//                ans = mid;
//                R = mid-1;
//            }
//            else{
//                L = mid+1;
//            }
//        }

 //       cout<<ans<<endl;






    }


    return 0;
}




