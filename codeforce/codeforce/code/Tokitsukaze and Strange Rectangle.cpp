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
ifstream in("/Users/jiazhi.zhou/CLionProjects/acm/InOutput/input.txt");
#define Debug(v) cerr<<#v<<"="<<v<<'\n'
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#define Debug(v) ;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)
#define FFLUAHALL fflush(stdin);fflush(stdout);



int n;
pii A[200010];

int a[400010];
int mark[200010];
inline int lowbit(int x){
    return x&(-x);
}
inline void update(int x,int v){
    while(x <= n){
        a[x]+=v;
        x += lowbit(x);
    }
}

inline int query(int x){
    int sum=0;
    while(x>0){
        sum += a[x];
        x-=lowbit(x);
    }
    return sum;
}




void input(){
    in>>n;
    for(int i=1;i<=n;++i){
        in>>A[i].first>>A[i].second;
    }


}

void _init(){



}

void change(){
    set<int> S;
    for(int i=1;i<=n;++i){
        S.insert(A[i].first);
    }
    unordered_map<int,int> M;
    int cnt = 1;
    for(int s : S){
        M[s] =cnt++;
    }
    for(int i=1;i<=n;++i){
        A[i] = mp( A[i].second, M[A[i].first]);
    }
}

inline LL query_range(int l,int r){
    if(l <= r)
        return query(r) - query(l-1);
    else
        return 0;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		 _init();
		input();

        change();
        sort(A+1,A+n+1);

        for(int i=1;i<=n;++i) {
            mark[A[i].second]++;
            if (mark[A[i].second] == 1)
                update(A[i].second, 1);
        }

        LL ans = 0;
        int pos = 1;
        while(pos <= n){
            vector<int> X;
            int y = A[pos].first;
            while(pos <= n && A[pos].first == y){
                X.push_back(A[pos].second);
                pos++;
            }
            X.push_back(n+1);
            LL all = query_range(1,n);
            LL add = all * (all + 1) / 2;

            int pre = 0;
            sort(X.begin(),X.end());
            LL del = 0;
            for(int x : X){
                LL sub = query_range(pre, x - 1);
                del += sub * (sub + 1) / 2;
                pre = x + 1;
            }
            for(int x : X){
                mark[x]--;
                if(mark[x] == 0){
                    update(x , -1);
                }
            }
            ans += add - del;
         //   cout<<add<< " "<<del<<endl;

        }


        cout<<ans<<endl;












	}


	return 0;
}





