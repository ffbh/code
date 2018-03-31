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




void input(){



}

LL n,a[500010],sum[500010];

LL ANS;

LL ABS(LL a){
    if(a>=0)
        return a;
    return -a;
}

int bs(int l,int r,LL all){
    int L = l;
    int R = r;
    int ans = -1;
    while(L<=R){
        int mid = (L+R)/2;
        LL lf = sum[mid] - sum[l-1];
        LL rg = all - lf;
        if(lf < rg){
            L = mid + 1;
        }
        else{
            ans = mid;
            R = mid-1;
        }
    }
    LL diff = (sum[ans]-sum[l-1])  - all + (sum[ans]-sum[l-1]);

    if(ans > l){
        LL dd =  (sum[ans-1]-sum[l-1])  - all + (sum[ans-1]-sum[l-1]);
        if(ABS(dd) <= ABS(diff))
            ans--;
    }
    return ans;
}

void slove(int l,int r){
    if(l == r){
        return ;
    }
    LL all = sum[r] - sum[l-1];
    ANS += all;
    int mid = bs(l,r,all);
    slove(l,mid);
    slove(mid+1,r);



}

int main(){
    while(in>>n&&n){
        for(int i=1;i<=n;++i) {
            in >> a[i];
        }

        sum[0]=0;
        for(int i=1;i<=n;++i)
            sum[i] = sum[i-1]+a[i];
        ANS=0;
        slove(1,n);
        printf("%lld\n",ANS);







    }







	return 0;
}





