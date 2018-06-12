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


vector<LL>  ll,lr,rl,rr;

LL n,L,mmax;

void input(){
    in>>n>>L>>mmax;

    for(int i=1;i<=n;++i){
        LL a,b,c;
        in>>a>>b;
        if(b == 1){
            c = a;

            if(c<0){
                lr.push_back(c);
            }
            else{
                rr.push_back(c);
            }
        }
        else{
            c = a+L;

            if(c>0){
                rl.push_back(c);
            }
            else{
                ll.push_back(c);
            }
        }
    }


}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


        sort(ll.begin(),ll.end(),greater<int>());
        sort(lr.begin(),lr.end(),greater<int>());
        sort(rl.begin(),rl.end());
        sort(rr.begin(),rr.end());


        LL ans = 0;
        ans += ((LL)lr.size()) * ((LL)rl.size());

        if(mmax > 1) {
            int pos;

            pos = -1;
            for (auto k : lr) {
//                if (k + L >= 0) {
//                    continue;
//                }
                LL p1 = -k;
                while(pos + 1 < ll.size()){
                    LL p2 = -ll[pos+1];
                    if (p1 * (mmax-1) > p2 * (mmax+1)){
                        pos ++;
                    }
                    else{
                        break;
                    }
                }
                ans += pos + 1;

            }
            pos = -1;
            for(auto k : rl){
//                if(k<=L){
//                    continue;
//                }
                LL p1 = k;
                while(pos + 1 < rr.size()){
                    LL p2 = rr[pos + 1];
                    if (p1 * (mmax-1) > p2 * (mmax+1)){
                        pos++;
                    }
                    else{
                        break;
                    }

                }

                ans += pos + 1;
            }
        }



        cout<<ans<<endl;

	}


	return 0;
}





