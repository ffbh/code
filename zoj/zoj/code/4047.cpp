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
ifstream in("/home/zhoujiazhi/CLionProjects/bbbb/InOutput/input.txt");
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


bool ok(int mid){
    if(mid == 0)
        return m==0;
    int cnt = m / mid;
    int rest = m % mid;
    int need = cnt * (mid + 1);
    if(rest == 0){
        need--;
    }
    else{
        need += rest;
    }
    return need <= n;
}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int L = 0,R = m,ans = m;
		while(L<=R){
		    int mid = (L+R)/2;
            if(ok(mid)){
                ans = mid;
                R = mid-1;
            }
            else{
                L =mid+1;
            }
		}
        printf("%d %d\n",m,ans);

	}


	return 0;
}





