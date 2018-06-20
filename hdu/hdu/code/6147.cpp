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


LL dirs[4][2]={0,1,1,0,0,-1,-1,0};

int n;
LL x[1000010];

pll pi[1000010];
void input(){
    in>>n;
    for(int i=1;i<=n;++i)
        in>>x[i];


}


bool In(pll& a,pll& b,pll& c){
    if(a.first == b.first){
        LL l = min(a.second,b.second);
        LL r = max(a.second,b.second);
        return c.second >=l && c.second <= r;
    }
    else{
        LL l = min(a.first,b.first);
        LL r = max(a.first,b.first);
        return c.first >=l && c.first <= r;
    }
}


bool inter(pll& a,pll& b,pll& c,pll& d){
    if(a.first == b.first){
        LL l = min(c.first,d.first);
        LL r = max(c.first,d.first);
        return l<=a.first && a.first <=r;
    }
    else{
        LL l = min(c.second,d.second);
        LL r = max(c.second,d.second);
        return l<=a.second && a.second <=r;
    }
}

bool intersection(pll& a,pll& b,pll& c,pll& d){
    return inter(a,b,c,d)&&inter(c,d,a,b);
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        pi[0] = mp(0L,0L);
        for(int i=1;i<=n;++i){
            pi[i] = mp(pi[i-1].first + dirs[(i-1)%4][0] * x[i],
                     pi[i-1].second + dirs[(i-1)%4][1] * x[i]);
        }
        int pos = -1,ans = -1;
        for(int i = 3;i<=n;++i){
            if(In(pi[i-3],pi[i-2],pi[i])){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            while(pos < n){
                if(pos == n-1){
                    int t = 0;
                }
                if(intersection(pi[pos-3],pi[pos-2],pi[pos],pi[pos+1])
                        || intersection(pi[pos-5],pi[pos-4],pi[pos],pi[pos+1])

                        ){
                    ans = pos + 1;
                    break;
                }
                pos++;
            }
        }

        if(ans == -1){
            printf("Catch you\n");
        }
        else{
            printf("%d\n",ans);
        }









	}


	return 0;
}





