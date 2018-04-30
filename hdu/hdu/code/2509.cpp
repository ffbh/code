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


int SG[110];
bool vis[510];
void cale() {
	SG[0] = 0;
	for (int i = 1; i <= 100; ++i) {
		int p = 0;
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j <= i; ++j) {
			for (int k = 0; k <= i - j; ++k) {
				vis[SG[k] ^ SG[i - j - k]] = 1;
			}

		}
		for(int j=0;j<i;++j)
			vis[SG[i]] = 1;
		while (vis[p])
			p++;
		SG[i] = p;
	}

}




int main(){

	cale();
	int n;
	while(in>>n){
		int sg = 0;
        int one = 0;
        int num = 0;
		for(int i=1;i<=n;++i){
			int t;
			in>>t;
            if(t == 1){
                one ++;
            }
            else if(t > 1){
                sg ^= SG[t];
                num++;
            }

		}
        one %= 2;
        if(num == 0){
            if(one == 0){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else if(num == 1){
            printf("Yes\n");
        }
        else{
            if(sg ^ one == 0){
                printf("No\n");
            }
            else{
                printf("Yes\n");
            }


        }

	}

	return 0;
}





