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
#include <stack>

using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("/home/fbh/CLionProjects/codeforce/input.txt");
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


int n,m,h;
int u[100010];
vector<int> V[100010];

vector<pii> edge;

void input() {
    in>>n>>m>>h;
    for(int i=1;i<=n;++i)
        in>>u[i];
    for(int i=1;i<=m;++i){
        int a,b;
        in>>a>>b;
        if((u[a]+1)%h==u[b]){
            V[a].push_back(b);
            edge.push_back(mp(a,b));
        }
        if((u[b]+1)%h==u[a]){
            V[b].push_back(a);
            edge.push_back(mp(b,a));
        }
    }
}

stack<int> S;
bool vis[100010];
int FL[100010],FM[100010],ID=1;
int tree[100010],NODE=1,size[100010];
void dfs(int p){
    FL[p]=FM[p]=ID++;
    vis[p]=1;
    S.push(p);
    for(int son : V[p]){
        if(FL[son] == -1){
            dfs(son);
            FM[p]=min(FM[p],FM[son]);
        }
        else{
            if(vis[son]){
                FM[p] = min(FM[p],FM[son]);
            }
        }
    }
    if(FL[p] == FM[p]){
        while(!S.empty()){
            int top = S.top();
            S.pop();
            vis[top]=0;
            tree[top]=NODE;
            size[NODE]++;
            if(top == p)
                break;
        }
        NODE++;
    }
}

int OUT[100010];



int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        input();


        memset(FL,-1,sizeof(FL));

        for(int i=1;i<+n;++i)
            if(FL[i] == -1)
                dfs(i);

        for(pii p : edge){
            int a = tree[p.first];
            int b = tree[p.second];
            if(a != b)
                OUT[a]++;
        }

        int ans,mmin = 1000000;
        for(int i=1;i<NODE;++i){
            if(OUT[i] == 0 && size[i] < mmin) {
                ans = i;
                mmin = size[i];
            }
        }
        printf("%d\n",mmin);
        for(int i=1;i<=n;++i)
            if(tree[i] == ans)
                printf("%d ",i);
        cout<<endl;




    }


    return 0;
}




