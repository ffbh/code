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
LL si[60],ci[60];

void input(){
	for(int i=1;i<=n;++i){
		in>>si[i]>>ci[i];
	}
}

int dp[1010];
int dfs(LL p,LL all) {
    if (p * p + p >= all) {
        return  all - p;
    }
    if (dp[p] != -1) {
        return dp[p];
    }
    int &ref = dp[p];
    set<int> S;
    int M1 = 1e9, M2 = -1;
    for (int i = 1; i <= p * p; ++i) {
        if (p + i + (p + i) * (p + i) >= all) {
            M1 = all - (p + i);
            M2 = all - p * p;
            break;
        } else {
            S.insert(dfs(p + i, all));
        }
    }


    for (int i = 0;; ++i) {
        if (!S.count(i)) {
            if (i >= M1 && i <= M2) {
                i = M2;
            } else {
                ref = i;
                break;
            }
        }
    }

    return ref;

}

int main(){
    int C = 1;
	while (in>>n){
        if(n==0)
            break;
		input();
        int sg = 0;
        for(int i=1;i<=n;++i){
            if(ci[i] != 0) {
                memset(dp, -1, sizeof(dp));
                sg ^= dfs(ci[i], si[i]);
            }
        }


        printf("Case %d:\n",C++);
        if(sg == 0){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }


	}


	return 0;
}





