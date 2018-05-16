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

pii H[610];
int HH[610][610];
int pppp;

LL dp[610][210];
vector<pll> vi[210];
int n;

void Init(){
    for(int i=1;i<=n;++i)
       vi[i].clear();
    for(int i=0;i<=3*n;++i)
        for(int j=0;j<=3*n;++j)
                dp[i][j] = -1;
    pppp = 0;

}

void input(){
    in>>n;
    Init();
    for(int i=1;i<n;++i){
        LL u,v,w;
        in>>u>>v>>w;
        vi[u].push_back(mp(v,w));
        vi[v].push_back(mp(u,w));
        H[pppp].first = u;
        H[pppp].second = vi[u].size()-1;
        HH[u][vi[u].size()-1] = pppp;
        pppp++;
        H[pppp].first = v;
        H[pppp].second = vi[v].size()-1;
        HH[v][vi[v].size()-1] = pppp;
        pppp++;
    }
}

LL size[210];
LL val[210];

LL first_dfs(int p,int f){

    size[p] = 0;
    val[p] = 0;

    for(pii son : vi[p]){
        if(son.first == f)
            continue;
        LL num = first_dfs(son.first,p);
        size[p] += num;
        val[p] += num * son.second;
        val[p] += val[son.first];
    }
    if(size[p] == 0)
        size[p] = 1;

    return size[p];
}

LL dfs(int h,int c,int f) {
    if(c<0){
        return (LL)1e18;
    }
    int a = H[h].first;
    int b = H[h].second;



    LL &ref = dp[h][c];
    if (ref != -1)
        return ref;
    ref = (LL)1e18;

    if (vi[a].size() == 1) {
        if (c <= 1) {
            return ref = 0;
        } else {
            return ref = (LL)1e18;
        }
    }

    if (b == vi[a].size()) {
        //   assert(c==0);
        if (c == 0)
            return ref = 0;
        else
            return ref = (LL)1e18;
    }

    if(vi[a][b].first == f){
        ref = dfs(HH[a][b+1],c,f);
    }
    else {
        if (c == 0) {
       //     int vk = val[vi[a][b].first];
       //     int vb = dfs(a, b + 1, c, f);
            return ref = val[vi[a][b].first] +
                    dfs(HH[a][b + 1], c, f) +
                    size[vi[a][b].first] * vi[a][b].second;
        }

   //     assert(val[vi[a][b].first] ==  dfs(HH[vi[a][b].first][0], 0, a));

        int mmin = 0;
        int mmax = (int)size[vi[a][b].first];
     // //  int v1 = dfs(HH[a][b + 1], c, f);
     //   int v2 = dfs(HH[vi[a][b].first][0], 0, a);
     //   int v3 = size[vi[a][b].first] * vi[a][b].second;
        ref = dfs(HH[a][b + 1], c, f) +
                dfs(HH[vi[a][b].first][0], 0, a) +
                size[vi[a][b].first] * vi[a][b].second;
        for (int k = 1; k <= mmax; ++k) {
            ref = min(ref, dfs(HH[a][b + 1], c - k, f) +
                           dfs(HH[vi[a][b].first][0], k, a)
                           + (LL) k * vi[a][b].second);
        }
    }
    return ref;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        first_dfs(1,0);

        for(int i=1;i<=n;++i){
            H[pppp].first = i;
            H[pppp].second = (int)vi[i].size();
            HH[i][vi[i].size()] = pppp;
            pppp++;
        }

        LL ans = 0;
        for(pii p : vi[1]){
            LL mmin = (LL)1e18;
           // cout<<p.first<<endl;
            for(int k=1;k<=size[p.first];++k) {
                mmin = min(mmin, dfs(HH[p.first][0], k, 1) +
                        (LL) k * p.second);
            }

            ans += mmin;

        }
        printf("%lld\n",ans);

	}


	return 0;
}





