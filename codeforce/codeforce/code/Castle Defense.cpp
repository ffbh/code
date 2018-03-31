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


typedef unsigned long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


LL n,r,k;
LL a[500010];
LL b[1500010];
void input(){
	in>>n>>r>>k;
	for(int i=1;i<=n;++i)
		in>>a[i];



}



bool ok(LL m){
	for(int i=1;i<=n;++i)
		b[i]=0;
    for(int i=1;i<=n;++i)
        b[i+n] = a[i];
    for(int i=1;i<=n;++i)
        b[i+2*n]=0;
	LL sum = 0;
	LL rest = k;
    int R = 2 * r +1;
	for(int i=n+1;i<=n+r;++i)
		sum += b[i];
	int pos = n+r+1;
	bool f = 0;
    while(pos <= 2*n+r){
        f = 1;
        sum += b[pos];
        if(sum + rest < m){
            return 0;
        }
        else if(sum < m){
            LL need = m - sum;
            rest -= need;
            b[pos] += need;
            sum += need;
        }
        pos++;
        sum -= b[pos - R];
    }
	return f || sum + rest >= m;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();



		LL L = 0,R = (LL)2e18,ans=0;
		while(L<=R){
			LL mid = (L+R)/2;
            if(mid == 9){
                int t=0;
            }
			if(ok(mid)){
				ans = mid;
				L = mid+1;
			}
			else{
				R = mid-1;
			}

		}

		cout<<ans<<endl;



	}


	return 0;
}





