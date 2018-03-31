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

#define double long double
typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)

int n,T;
pii all[200010];
double Exp = 2e-7;

void input(){
    in>>n>>T;
    for(int i=1;i<=n;++i) {
        //	in>>all[i].second;

        scanf("%d",&all[i].second);

    }
    for(int i=1;i<=n;++i) {
        //	in>>all[i].first;

        scanf("%d",&all[i].first);


    }
}

bool eq(double a,double b){
    return fabs(a-b)<Exp;
}
bool ok(double x){
    double aim = x * T;
    double mmin = 0;
    double rest = x;
    for(int i=1;i<=n;++i){
        if(rest > all[i].second){
            rest -= all[i].second;
            mmin += (double)all[i].first * all[i].second;
        }
        else{
            mmin += rest * all[i].first;
            break;
        }
    }

    double mmax = 0;
    rest = x;
    for(int i=n;i>=1;--i){
        if(rest > all[i].second){
            rest -= all[i].second;
            mmax += (double)all[i].first * all[i].second;
        }
        else{
            mmax += rest * all[i].first;
            break;
        }
    }
    if(eq(mmin,aim)||eq(mmax,aim)){
        return 1;
    }
    else{
        return mmin < aim && aim < mmax;
    }

}

int main(){

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0){
        input();

        double L,R,ans=0;
        L=R=0;
        for(int i=1;i<=n;++i)
            R += all[i].second;

        sort(all+1,all+n+1);
        while(R-L>Exp){
            double mid = (R+L)/2;
            if(ok(mid)){
                ans = mid;
                L = mid;
            }
            else{
                R = mid;
            }
        }

        printf("%.9Lf\n",ans);














    }


    return 0;
}