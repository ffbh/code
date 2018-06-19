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


int n,N;
vector<pii> A;


void input(){
	in>>n;
	A.resize(n);
	for(int i=0;i<n;++i){
		in>>A[i].first;
	}
	for(int i=0;i<n;++i){
		in>>A[i].second;
	}

}



bool cmp(pii a,pii b){
	if(a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

vector<int> v[60];
LL ppp[60];
LL sum[60];
LL dp[60][60][5010];


LL getVal(LL a ,int b){
    a*=1000;
    LL vk = ceil(double(a)/b);

    return vk;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		sort(A.begin(),A.end(),cmp);
        N = 0;
        int power = -1;
        for(int i=0;i<n;++i){
            if(power != A[i].first){
                N++;

                power = A[i].first;
                ppp[N] = power;
            }
            v[N].push_back(A[i].second);
        }

        for(int i=1;i<=N;++i){
            sum[i] = 0;
            for(LL vvv : v[i])
                sum[i] += vvv;
        }

        for(int i=0;i<60;++i)
            for(int k=0;k<60;++k)
                  for(int j=0;j<5010;++j)
                   dp[i][k][j] = (LL)1e14;
        dp[0][0][0] = 0;
        for(int i=0;i<N;++i){
            for(int j=0;j<60;++j){
                for(int k=0;k<5010;++k){
                    int size = v[i+1].size();
                    int thro = min(size,j);
                    int all = sum[i+1];
                    LL val = ((LL)v[i+1].size()) * ppp[i+1];
                    for(int e=0;e<=thro;++e){
                        assert(j-e+size-e>=0);
                     //   assert(val>=0);

                        dp[i+1][j-e+size-e][k+all] = min(dp[i][j][k] + val,dp[i+1][j-e+size-e][k+all]);

                        if(e < v[i+1].size()) {
                            all -= v[i+1][e];
                            val -= ppp[i+1];
                        }

                    }
                }
            }
        }

        LL ans = 1e18;
        for(int i=0;i<60;++i){
            for(int j=1;j<5010;++j) {
                LL ret = getVal(dp[N][i][j],j);
                if(ret == 1000){
                    int t=0;
                }
                ans = min(ans,ret );
            }
        }
        cout<<ans<<endl;





	}


	return 0;
}





