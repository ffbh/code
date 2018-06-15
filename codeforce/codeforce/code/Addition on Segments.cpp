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

int n,q;
vector<int> vadd[10010],vdel[10010];
bool ans[10010];
LL dp[10010];
LL mod = 1e9+7;
void input(){
  //  in>>n>>q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;++i){
        int l,r,x;
    //    in>>l>>r>>x;
        scanf("%d%d%d",&l,&r,&x);
        vadd[l].push_back(x);
        vdel[r+1].push_back(x);
    }
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        int num = 0;
        dp[0] = 1;
        for(int i=1;i<=n;++i){
            for(int x : vdel[i]){
                for(int k=x;k<=n;++k) {
                    //    dp[k] = (dp[k] - dp[k - x]+mod)%mod;
                            dp[k]-=dp[k-x];
                            if(dp[k]<0)
                                dp[k]+=mod;
                }
            }

            for(int x : vadd[i]){
                for(int k=n;k>=x;--k){
                //    dp[k] = (dp[k] + dp[k-x])%mod;
                        dp[k] += dp[k-x];
                        if(dp[k] >= mod)
                            dp[k]-=mod;
                    if(dp[k] && !ans[k]){

                        ans[k] = 1;
                        num++;
                    }
                }
            }

        }


        cout<<num<<endl;
        for(int i=1;i<=n;++i){
            if(ans[i]){
                cout<<i<<" ";
            }
        }
        cout<<endl;









	}


	return 0;
}





