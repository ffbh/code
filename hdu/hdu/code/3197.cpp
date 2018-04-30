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

vector<int> vi[1010];
vector<int> root;

void Init(){
    for(int i=0;i<1010;++i)
        vi[i].clear();
    root.clear();
}

void input(){
    for(int i=0;i<n;++i){
        int t;
        in>>t;
        if(t== -1){
            root.push_back(i);
        }
        else{
            vi[t].push_back(i);
        }
    }


}


int dfs(int p){
    int sg  = 0;
    for(int son : vi[p]){
        sg ^= (dfs(son)+1);

    }
    return  sg;
}

int main(){


	while (in>>n){
        Init();
		input();

        int sg = 0;
        for(int p : root){
            sg ^= dfs(p);
        }
        if(sg ==0) {
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }















	}


	return 0;
}





