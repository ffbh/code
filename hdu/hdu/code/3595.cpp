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


int dp[1010][1010];

int dfs(int x,int y){
    if(x > y)
        swap(x,y);
    assert(x>=0);
    if(dp[x][y] != -1)
        return dp[x][y];
    int& ref = dp[x][y];
    ref = 0;
    if(x <= 0){

    }
    else{
        set<int> s;
        for(int i=1;i<=y/x;++i){
            s.insert(dfs(x,y-i*x));
        }
        for(int i=0;;++i){
            if(!s.count(i)){
                ref = i;
                break;
            }
        }
    }
    return ref;

}



int main(){

	memset(dp,-1,sizeof(dp));
	int n;
    while(in>>n){
        int sg = 0;
        for(int i=1;i<=n;++i){
            int a,b;
            in>>a>>b;
            sg ^= dfs(a,b);

        }
        if(sg == 0){
            printf("GG\n");
        }
        else{
            printf("MM\n");
        }




    }

	return 0;
}





