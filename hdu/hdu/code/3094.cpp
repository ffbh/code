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
vector<int> vi[100010];
void Init(){
    for(int i=0;i<=n;++i)
        vi[i].clear();


}
void input(){
    in>>n;
    Init();
    for(int i=1;i<n;++i){
        int a,b;
      //  in>>a>>b;
        scanf("%d%d",&a,&b);
        vi[a].push_back(b);
        vi[b].push_back(a);
    }


}

int dfs(int p,int f){
    int sg = 0;
    for(int son : vi[p]){
        if(son == f)
            continue;
        int ret = dfs(son,p);
        ret++;
        sg ^= ret;
    }

    return sg;

}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){

		input();

        int sg = dfs(1,-1);
        if(sg == 0){
            printf("Bob\n");
        }
        else{
            printf("Alice\n");
        }













	}


	return 0;
}





