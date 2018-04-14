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

LL k1,k2,c;
int n,m;
LL dp[2010][2010];

LL suma[2010],sumb[2010];

int s1[2010],s2[2010];

void input(){
    in>>k1>>k2>>c;
	in>>n>>m;
    for(int i=1;i<=n;++i)
        in>>s1[i];
    for(int i=1;i<=m;++i)
        in>>s2[i];

}

void Init(){
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
            dp[i][j]=0;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        Init();
        sort(s1+1,s1+n+1);
        sort(s2+1,s2+m+1);
        for(int i=1;i<=n;++i)
            suma[i] = suma[i-1] + s1[i];
        for(int i=1;i<=m;++i)
            sumb[i] = sumb[i-1] + s2[i];


        LL ans = 0;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j){
                if(i+1<=n){
                    LL space = c - suma[i] - sumb[j] - s1[i+1];
                    if(space >= 0){
                        dp[i+1][j] = max(dp[i+1][j],dp[i][j] + space * k1);
                        ans = max(ans,dp[i+1][j]);
                    }
                }

                if(j+1<=m){
                    LL space =  c - suma[i] - sumb[j] - s2[j+1];
                    if(space >= 0){
                        dp[i][j+1] = max(dp[i][j+1],dp[i][j]+space * k2);
                        ans = max(ans,dp[i][j+1]);
                    }
                }

            }




            cout<<ans<<endl;










	}


	return 0;
}





