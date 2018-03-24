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


typedef  long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)

LL n,q;

void input() {
    in>>n>>q;

}

bool bound(LL b){
    while(b != 1){
        if(b % 2 == 1)
            return 0;
        b/=2;
    }
    return 1;
}

LL sum;

void dfs(LL len,LL aim,LL now,LL ALL){
    if(len / 2 + 1 == aim)
        sum += now;
    else if(aim <= len / 2 ){
        sum += ALL;
        dfs(len / 2 , aim,now* 2-1,ALL*2);
    }
    else{
        sum += ALL;
        dfs(len/2,aim-len/2-1,now*2,ALL*2);
    }
}

LL slove(LL k){
    if(k % 2 == 1 && k <= n){
        return (k+1)/2;
    }
    LL blank = n - (k/2);
    if(bound(blank))
        return n;
    LL now = 0;
    LL all = 0;
    while(all < blank){
        all += 1 + now;
        now = now * 2 + 1;
    }
    now/=2;
    LL exceed = all - blank;
    LL aim = now - exceed ;
    sum=0;
    dfs(now,aim,1,1);
    return n - sum;
}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        input();
        while(q--){
            LL k;
            in>>k;
            printf("%lld\n",slove(k));





        }



    }


    return 0;
}
