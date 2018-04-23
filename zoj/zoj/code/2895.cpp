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
int a[1000010];

int b[1010][2];

bool vis[1010];
bool mem[1010];
void Init(){
	for(int i=0;i<1010;++i) {
        b[i][0] = 1e8;
        b[i][1] = -1;

    }

}


int main(){
    ios::sync_with_stdio(false);
	while(in>>n){
        if(n==0){
            cout<<0<<endl;
            continue;
        }
		Init();
		for(int i =1;i<=n;++i) {
			in >> a[i];
		//	scanf("%d",&a[i]);
			b[a[i]][0] = min(b[a[i]][0],i);
            b[a[i]][1] = i;
		}

        vector<pii> all;
        for(int i=0;i<1010;++i){
            if(b[i][1] != -1){
                all.push_back(mp(b[i][0],i));
                all.push_back(mp(b[i][1],i));
            }
        }
		sort(all.begin(),all.end());
        int ans = -1;
        for(int i=1;i<=5000;++i){
            memset(vis,0,sizeof(vis));
            memset(mem,0,sizeof(mem));
            bool ok = 1;
            for(pii p : all){
                int m = p.second % i;
                if(vis[p.second]){
                    mem[m] = 0;
                }
                else{
                    vis[p.second] = 1;
                    if(mem[m]){
                        ok=0;
                        break;
                    }
                    mem[m] = 1;
                }
            }
            if(ok){
                ans = i;
                break;
            }
        }
        assert(ans>=0);

      //  printf("%d\n",ans);
        cout<<ans<<endl;

	}



	return 0;
}





