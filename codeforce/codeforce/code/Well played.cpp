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

int n,a,b;
pll d[200010];
bool mark[200010];
void input(){
	in>>n>>a>>b;
	for(int i=1;i<=n;++i)
		in>>d[i].first>>d[i].second;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        if(b==0){
            LL sum = 0;
            for(int i=1;i<=n;++i){
                sum += d[i].second;
            }
            cout<<sum<<endl;
            return 0;
        }

        LL mul = 1;
        for(int i=0;i<a;++i)
            mul *= 2;
		vector<pll> all;
		for(int i=1;i<=n;++i){
            if(d[i].first > d[i].second){
                all.push_back(mp(d[i].second-d[i].first,i));
            }
		}
        sort(all.begin(),all.end());
		LL sum = 0;
		bool has = 0;
		if(b > all.size()){
		    has = 1;
		}
        for(int i=0;i<b&&i<all.size();++i){
		    mark[all[i].second] = 1;
		    sum -= all[i].first;
		}

		LL useless = 0;
		if(has){
		    if(!all.empty()){
		        useless = -all.back().first;
		    }
		}
		else{
            useless = -all[b-1].first;
		}

        LL ckk = 0;
        for(int i=1;i<=n;++i){
            if(mark[i]){
                ckk += d[i].first;
            }
            else{
                ckk += d[i].second;
            }
        }
		LL ans = ckk;
        for(int i=1;i<=n;++i){
            LL val = d[i].first * mul;
            LL tmp;
            if(mark[i]){
                tmp = ckk - d[i].first + val;
            }
            else if(has){
                tmp = ckk - d[i].second + val;
            }
            else{
                tmp = ckk - d[i].second + val - useless;
            }
            ans = max(ans,tmp);

        }


        cout<<ans<<endl;












	}


	return 0;
}





