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
int L[100010],R[100010];
vector<int> vi[100010];
int ans[100010];
void Init(){
    for(int i=0;i<=n;++i)
        vi[i].clear();
}


int tree[400010];

void build(int root,int l,int r){
    tree[root] = -1;
    if(l != r){
        int mid = (l+r)/2;
        build(lson,l,mid);
        build(rson,mid+1,r);
    }
}

int query(int root,int l,int r,int L,int R){


    if(l<=L && r >= R){
        return tree[root];

    }
    else if(l > R || r < L) {
        return -1;
    }
    else{
        int mid = (L+R)/2;
        int a = query(lson,l,r,L,mid);
        int b = query(rson,l,r,mid+1,R);
        return max(a,b);
    }


}


int update(int root,int L,int R,int p,int v){
    if(L == R){
        if(L == p){
            tree[root] = v;
        }

    }
    else{
        int mid = (L+R)/2;
        int val;
        if(p <= mid){
            val = update(lson,L,mid,p,v);
        }
        else{
            val = update(rson,mid+1,R,p,v);
        }
        tree[root] = max(tree[root],val);
    }

    return tree[root];

}



void input(){
    in>>n;
    Init();
    for(int i=1;i<=n;++i){
        int t;
        in>>t;
        vi[t].push_back(i);
    }

    for(int i=1;i<=n;++i){
        in>>L[i]>>R[i];
    }

}
int ppos;
int gget(int idx,int now){
    if(ppos < 0)
        return -1;
    else{
        while(ppos >=0 && vi[idx][ppos] > now){
            ppos --;
        }
        if(ppos < 0){
            return -1;
        }
        else{
            return ans[vi[idx][ppos]];
        }
    }

}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


  //      build(1,1,n);
        for(int i=1;i<=n;++i){
            int M = -1;
            ppos = (int)vi[i-1].size() - 1;

            //idx == i - 1
            if(!vi[i].empty()){
                for(int k=(int)vi[i].size()-1;k>=0;--k){
                    int idx = vi[i][k];
         //           int m = query(1,1,idx,1,n);
                    int m = gget(i-1,idx);
                    int aaa = max(m+1,L[idx]);
                    M = max(M,aaa);
//                    assert(M <= R[idx]);
                    ans[idx] = M;
              //      update(1,1,n,idx,aaa);
                }
            }

        }


        for(int i=1;i<n;++i)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);












	}


	return 0;
}





