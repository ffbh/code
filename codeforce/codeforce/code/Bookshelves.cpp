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
#include <climits>

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



LL dp[60][60][60];//n k dig
int n,k;
LL a[60];
LL sum[60];
LL pw[70];

void input(){
	in>>n>>k;
	for(int i=1;i<=n;++i)
		in>>a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        pw[0] = 1;
        for(int i=1;i<70;++i)
            pw[i] = pw[i-1]*2;


		for(int i=1;i<=n;++i)
		    sum[i] += sum[i-1] + a[i];

        LL MMAX = pw[62] - 1L;

		LL ans = 0;

		for(int v=0;v<60;++v) {
		    memset(dp,0,sizeof(dp));
            for(int i=0;i<60;++i)
                dp[0][0][i] = MMAX;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= k; ++j) {
                    for (int d = 0; d < 60; ++d) {
                        if(ans & pw[d]){
                            continue;
                        }
                        for (int len = 1; len <= n; ++len) {
                            if (i + len <= n) {
                                LL val = sum[i + len] - sum[i];
                                bool ok = 1;
                                LL andval = val & dp[i][j][d];
                                for(int ckk = 0;ckk<60;++ckk){
                                    if(pw[ckk] & ans){
                                        if(!(pw[ckk] & andval)){
                                            ok = 0;
                                            break;
                                        }
                                    }
                                }
                                if(ok) {
                                    for (int kk = 0; kk < 60; ++kk) {
                                        if (andval & pw[kk]) {
                                            dp[i + len][j + 1][kk] = max(dp[i + len][j + 1][kk], andval);
                                        }
                                    }
                                }
                            } else
                                break;
                        }
                    }
                }
            }
            LL mmax = 0;
            for(int p=0;p<60;++p)
                mmax = max(mmax,dp[n][k][p]);
            bool modify = 0;
            for(int p=60;p>=0;--p){
                if((pw[p]&ans) == 0 && (pw[p]&mmax) !=0){
                    ans += pw[p];
                    modify = 1;
                    break;
                }
            }
            if(!modify)
                break;
        }
		cout<<ans<<endl;












	}


	return 0;
}





