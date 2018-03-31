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

LL n,m;
vector<pll> seg[3];
int idx[3];
void input(){
	in>>n>>m;
	for(int i=1;i<=n;++i){
		LL a,b,c;
		in>>a>>b>>c;
		seg[a-1].push_back(mp(b,c));
	}


}

LL mod = 1e9+7;

void add(LL& a,LL b){
    a%=mod;
    b%=mod;
    a+=b;
    a%=mod;
    if(a<0)
        a+=mod;
}


void mul(LL a[3][3],LL b[3][3],LL ret[3][3],int size){
    LL tmp[3][3];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            for(int k=0;k<size;++k){
                add(tmp[i][j],a[i][k]*b[k][j]);
            }
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            ret[i][j]=tmp[i][j];
}

void quick_mod(LL p,LL mat[3][3],int size){
    LL a[3][3];
    memset(a,0,sizeof(a));
    for(int i=0;i<3;++i)
        a[i][i]=1;
    while(p){
        if(p&1){
            mul(a,mat,a,size);
        }
        mul(mat,mat,mat,size);
        p/=2;
    }
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            mat[i][j]=a[i][j];
}

LL qmod(LL a,LL p){
    LL ret = 1;
    while(p){
        if(p&1)
            ret = ret * a %mod;
        a = a*a%mod;
        p/=2;
    }
    return ret;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for(int i=0;i<3;++i)
			sort(seg[i].begin(),seg[i].end());
		for(int i=0;i<3;++i){
			vector<pll> tmp = seg[i];
			seg[i].clear();
			for(pll p : tmp){
				if(!seg[i].empty() && seg[i].back().second + 1 >= p.first){
					seg[i].back().second = max(seg[i].back().second ,p.second);
				}
				else{
					seg[i].push_back(p);
				}
			}
		}



		LL now = 2;
		LL ans[3];
		ans[0]=ans[2] = 0;
		ans[1]=1;
		while(now < m){

			int key = 0;
			LL E = m -1;
			for(int i=0;i<3;++i) {
				while (idx[i] < seg[i].size() && seg[i][idx[i]].second < now) {
					idx[i]++;
				}
                if(idx[i] < seg[i].size()) {
                    pll S = seg[i][idx[i]];
                    LL limit;
                    if (S.first <= now) {
                        limit = S.second;
                        key += 1<<i;
                    } else {
                        limit = S.first - 1;
                    }
                    E = min(E, limit);
                }

			}
            LL len = E - now + 1;
            if(key == 0){
                LL mat[3][3];
                for(int i=0;i<3;++i)
                    for(int j=0;j<3;++j)
                        mat[i][j]=1;

                mat[0][2]=mat[2][0]=0;
                quick_mod(len,mat,3);
                LL t[3]={0};
                for(int k=0;k<3;++k)
                    for(int i=0;i<3;++i)
                        add(t[k],mat[k][i]*ans[i]);
                for(int i=0;i<3;++i)
                    ans[i] = t[i];
            }
            else if(key == 1){
                LL t[3];
                for(int i=0;i<3;++i) {
                    t[i] = ans[i];
                    ans[i] = 0;
                }
                if(len == 1){
                    add(ans[1],t[0]+t[1]+t[2]);
                    add(ans[2],t[1]+t[2]);
                }
                else{
                    LL ak,bk;
                    ak=bk=0;
                    add(ak,t[0]+t[1]+t[2]);
                    add(bk,t[1]+t[2]);
                    len--;
                    LL ck=0;
                    add(ck,ak+bk);
                    LL m2 = qmod(2,len-1);
                    ans[0] = 0;
                    ans[1]=ans[2] = m2 * ck % mod;
                }
            }
            else if(key == 2){
                add(ans[0],ans[1]);
                add(ans[2],ans[1]);
                ans[1]=0;


            }
            else if(key == 3){
                add(ans[2],ans[1]);
                ans[0]=ans[1]=0;

            }
            else if(key == 4){
                LL t[3];
                for(int i=0;i<3;++i) {
                    t[i] = ans[i];
                    ans[i] = 0;
                }
                if(len == 1){
                    add(ans[1],t[0]+t[1]+t[2]);
                    add(ans[0],t[1]+t[0]);
                }
                else{
                    LL ak,bk;
                    ak=bk=0;
                    add(ak,t[0]+t[1]+t[2]);
                    add(bk,t[1]+t[0]);
                    len--;
                    LL ck=0;
                    add(ck,ak+bk);
                    LL m2 = qmod(2,len-1);
                    ans[2] = 0;
                    ans[1]=ans[0] = m2 * ck % mod;
                }
            }
            else if(key == 5){
                add(ans[1],ans[0]+ans[2]);
                ans[0]=ans[2]=0;
            }
            else if(key == 6){
                add(ans[0],ans[1]);
                ans[1]=ans[2]=0;
            }
            else {
                memset(ans,0,sizeof(ans));
                break;
            }
            now = E + 1;
//            for(int i=0;i<3;++i)
//                cout<<ans[i]<<" ";
//            cout<<endl;
		}

        cout<<(ans[0]+ans[1]+ans[2])%mod<<endl;










	}


	return 0;
}





