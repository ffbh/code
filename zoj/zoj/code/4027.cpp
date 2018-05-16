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

int n;
string s;
LL v[1010];

void input(){
    in>>n;
    in>>s;
    for(int i=1;i<=n;++i)
        in>>v[i];



}

LL mmax[1010],pre[1010];
LL sum[1010];
void Init(){
    for(int i=0;i<=n+1;++i) {
        pre[i] = 0;
        mmax[i] = -1e18;
    }

}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0) {
        input();
        Init();
        sum[0] = 0;
        s = string("-") + s;
        for(int i=1;i<=n;++i){
            if(s[i] == ')'){
                sum[i] = sum[i-1]+v[i];
            }
            else{
                sum[i] = sum[i-1];
            }
        }


        LL ans = 0;
        for(int i=n;i>=1;--i){
            if(i==1){
                int t=0;
            }

            if(s[i] == '('){
                for(int j=n;j>=i;--j){
                    LL vj = sum[j]-sum[i-1];
                    LL add = v[i] * vj;
                    mmax[j] = add + pre[j];
                //    mmax[j] = max(mmax[j],dp[i][j]);
                    ans = max(ans,mmax[j]);
                }
                for(int k=n-1;k>=1;--k){
                    mmax[k] = max(mmax[k] ,mmax[k+1]);
                }
                for(int i=0;i<=n;++i)
                    pre[i] = mmax[i];
            }


        }
        cout<<ans<<endl;













    }


	return 0;
}





