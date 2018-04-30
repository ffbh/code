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


int n,a[10010];

void input(){
    in>>n;
    for(int i=1;i<=n;++i){
        in>>a[i];
    }
}

int mark[10010];

void build(){
    memset(mark,-1,sizeof(mark));

    for(int i=1;i<=10000;++i){
        if(mark[i] == -1){
            mark[i] = 0;
        }
        for(int k=3;i+k<=10000;k+=6){
            int aim = k - i;
            if(aim <= i)
                continue;
//            if(mark[i] == mark[aim]){
//               cout<<k<<" "<<i<<endl;
//            }
        //    assert(mark[k] != mark[i]);
            mark[aim] = 1 - mark[i];
        }
    }
}



int main(){

    build();


	int TEST_CASE = 1;
	in >> TEST_CASE;
    int C = 1;
	while (TEST_CASE-- > 0){
		input();
        int sg = 0;

        for(int i=1;i<=n;++i){
            if(mark[i] == 1)
                sg ^= a[i];
        }

        printf("Case %d: ",C++);
        if(sg == 0){
            printf("Bob\n");
        }
        else{
            printf("Alice\n");
        }














	}


	return 0;
}





