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


int n,k;

void input(){
    in>>n>>k;
}

int SG[11][510];
bool vis[510];
void cale(){
    for(int K=1;K<=10;++K){
        SG[K][0] = 0;
        for(int i=1;i<110;++i){
            int p = 0;
            memset(vis,0,sizeof(vis));
            for(int j=1;j<=min(K,i);++j){
                for(int k=0;k<=i-j;++k){
                    vis[SG[K][k] ^ SG[K][i-j-k]] = 1;
                }
            }
            for(int j=1;j<=K;++j) {
                if(i-j>=0)
                vis[SG[K][i-j]] = 1;
            }
            while(vis[p])
                p++;
            SG[K][i] = p;
        }
    }
}


int main(){



    cale();
	int TEST_CASE = 1;
	in >> TEST_CASE;
    int C = 1;
	while (TEST_CASE-- > 0){
		input();
//        bool ok = 0;
//        for(int i=1;i<=k;++i){
//            if(SG[k][n-i] == 0){
//                ok = 1;
//                break;
//            }
//
//        }
        bool ok = 0;
        if(k>1){
            if(k<n)
                 ok = 0;
            else
                ok = 1;
        }
        else{
            if(n % 2 == 1){
                ok = 1;
            }
            else{
                ok = 0;
            }
        }

        printf("Case %d: ",C++);
        if(ok){
            printf("first\n");
        }
        else{
            printf("second\n");
        }













	}


	return 0;
}





