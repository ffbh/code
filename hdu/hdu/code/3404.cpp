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


int sg[110][110];

void Init(){
    for(int i=1;i<=50;++i)
        for(int j=1;j<=50;++j){
            if(i==1&&j==1){
                continue;
            }
            set<int> S;
            for(int ki=1;ki<=i;++ki)
                for(int kj=1;kj<=j;++kj){
                    int s = 0;
                    for(int p=ki;p<=i;++p)
                        for(int q=kj;q<=j;++q){
                            if(ki!=p||kj!=q){
                                s ^= sg[p][q];
                            }
                        }
                    S.insert(s);
                }
            for(int k=0;;++k)
                if(!S.count(k)){
                    sg[i][j] = k;
                    break;
                }
        }
}

void input(){



}





int main(){
    Init();
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();















	}


	return 0;
}





