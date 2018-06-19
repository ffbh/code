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


int N,M,K;
bool g[35][35];
bool h[35];
bool dp[35][(1<<16)+10];
int pw[30];
void Init(){
    memset(g,0,sizeof(g));
    memset(h,0,sizeof(h));
    memset(dp,0,sizeof(dp));
}

void input(){
	in>>N>>M>>K;
    for(int i=1;i<=M;++i){
        int x,y;
        in>>x>>y;
        g[x][y] = g[y][x] =1;
    }
    for(int i=1;i<=K;++i){
        int t;
        in>>t;
        h[t] = 1;
    }

}

int COUNT(int p){
    int num = 0;
    for(int i=0;i<20;++i)
        if(pw[i] & p)
            num++;
    return num / 2;
}

int hp[35][2];
int pp[2];
int main(){

    pw[0] = 1;
    for(int i=1;i<30;++i)
        pw[i] = pw[i-1] * 2;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
	    Init();
		input();


		pp[0] = pp[1] = 0;
		for(int i=1;i<=N;++i){
		    if(h[i]){
		        hp[pp[1]++][1] = i;
		    }
		    else{
                hp[pp[0]++][0] = i;
		    }
		}


		int ans = 0;
        dp[0][0] = 1;
        for(int i=0;i<N-K;++i){
            for(int mask=0;mask<(1<<K);++mask){
                if(!dp[i][mask])
                    continue;
                dp[i+1][mask] = 1;
                int lp_real = hp[i][0];
                for(int j=0;j<K;++j) {
                    int hp_real1 = hp[j][1];
                    if(pw[j] & mask || !g[lp_real][hp_real1])
                        continue;
                    for (int k = j + 1; k < K; ++k) {
                        int hp_real2 = hp[k][1];
                        if(pw[k] & mask || !g[lp_real][hp_real2])
                            continue;
                        int nxmask = mask | pw[j] | pw[k];
                        ans = max(ans,COUNT(nxmask));
                        dp[i+1][nxmask] = 1;
                    }
                }

            }


        }

        printf("%d\n",ans);









	}


	return 0;
}





