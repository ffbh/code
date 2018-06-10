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

int n,m,k,s;
int type[100010];
vector<int> vi[100010];
vector<int> V[110];
int d[100010][110];

void input(){
    in>>n>>m>>k>>s;
    for(int i=1;i<=n;++i)
        in>>type[i];
    for(int i=1;i<=m;++i){
        int u,v;
        in>>u>>v;
        vi[u].push_back(v);
        vi[v].push_back(u);
    }

}

void bfs(int p){
    queue<int> qi;
    for(int v : V[p]){
        qi.push(v);
        d[v][p] = 0;
    }
    while(!qi.empty()){
        int u = qi.front();
        qi.pop();
        for(int v : vi[u]){
            if(d[v][p] == -1){
                d[v][p] = d[u][p] + 1;
                qi.push(v);
            }
        }
    }
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        memset(d,-1,sizeof(d));
		for(int i=1;i<=n;++i){
		    V[type[i]].push_back(i);
		}

        for(int i=1;i<=k;++i){
		    bfs(i);
		}

        for(int i=1;i<=n;++i){
		    sort(d[i]+1,d[i]+k+1);
		    int ans = 0;
		    for(int j=1;j<=s;++j){
		        ans += d[i][j];
		    }
		    printf("%d ",ans);
		}
        printf("\n");



	}


	return 0;
}





