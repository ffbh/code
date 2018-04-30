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


int n,m;

void input(){
	in>>n>>m;


}

int sg[1010][1010];

int dfs(int x,int y){
    if(sg[x][y] != -1)
        return sg[x][y];
    if(y>x){
        return sg[x][y] = 0;
    }
    set<int> S;
    for(int i=0;i<=x-y;++i){
        S.insert(dfs(i,y)^dfs(x-y-i,y));
    }
    for(int i=0;;++i){
        if(!S.count(i)){
            sg[x][y] = i;
            break;
        }
    }
    return sg[x][y];
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	int C = 1;
    memset(sg,-1,sizeof(sg));

//
//    for(int i=1;i<1000;++i) {
//        for (int j = 1; j < 1000; ++j) {
//            dfs(i, j);
//        }
//    }

	while (TEST_CASE-- > 0){
		input();


		printf("Case #%d: ",C++);

		if(m==1){
			if(n%2==1){
				printf("aekdycoin\n");
			}
			else{
				printf("abcdxyzk\n");
			}
		}
		else if(n < m){
            printf("abcdxyzk\n");
		}
        else{
            int ans = dfs(n-m,m);
            if(ans == 0){
                printf("aekdycoin\n");
            }
            else{
                printf("abcdxyzk\n");
            }
        }














	}


	return 0;
}





