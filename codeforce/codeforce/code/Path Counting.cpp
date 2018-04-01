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


LL mod = 1e9+7;
int n;
LL a[5010];
LL c[5010];
void input(){
	in>>n;
	a[1]=1;
	for(int i=2;i<=n;++i)
	//	in>>a[i];
    scanf("%d",&a[i]);
}

LL f[5010][5010];
LL dp[2][10010];
LL ans[10010];

void add(LL& a,LL b){
	a%=mod;
	b%=mod;
	a+=b;
	a%=mod;
	if(a<0)
		a+=mod;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		c[1] = 1;
		for(int i=2;i<=n;++i)
			c[i] = c[i-1]*a[i]%mod;


		for(int i=1;i<=n;++i) {
			f[i][0] = 1;
			for (int j = 1; i+j <= n; ++j) {
				f[i][j] = f[i][j-1] * a[i+j] % mod;
				add(ans[j],c[i] * f[i][j] % mod);
			}
		}



		for(int i=1;i<=n;++i){
            int now = i%2;
            int pre = 1-now;

			dp[now][0] = 1;
			for(int j=1;j<=2*n-2;++j){
				dp[now][j] = dp[pre][j-1];
				if(j>=2 && i > 1) {
                    if(j-2<5010)
                         add(dp[now][j], f[i][j - 2]* (a[i] - 1)%mod);
                }

				add(ans[j],c[i] * dp[now][j]% mod);
			}
		}

        LL kk = mod + 1;
        kk /= 2;
		for(int i=1;i<=2*n-2;++i){
			printf("%lld ",ans[i]* kk % mod);
		}
        cout<<endl;






	}


	return 0;
}





