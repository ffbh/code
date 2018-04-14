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
string b[1000010];
string r,d;
bool vis[1000010];
int R[1000010],D[1000010];
bool edge[1000010];

void Init(){
    for(int i=0;i<n;++i){
        R[i]=r[i]-'0';
        D[i]=d[i]-'0';
        vis[i]=0;
    }
}

void input(){
	in>>n>>m;
	for(int i=0;i<n;++i)
		in>>b[i];
	in>>r>>d;
}
int len,start;
int getlen(int p){
    start = -1;
    for(int i=0;i<m;++i){
        if(b[p][i] == 'X'){
            if(start == -1){
                start = i;
            }
            else{
                return i-start;
            }
        }
    }
    return -1;
}


pii bbb(int S){
    int ne;
    bool ok=1;
    bool mark = 0;
    for(int i=S;i!=S||ok;i=ne){
        ok = 0;
        ne = (i+len)%n;
        vis[i] = 1;
        mark ^= D[i];
        mark ^= edge[i];

    }



    ok=1;
    int oo = 0,ol = 0,ll = 0;
    for(int i=S;i!=S||ok;i=ne){
        ok=0;
        ne = (i+len)%n;
        if(ne != i) {
            if (D[i] == 0) {
                if (edge[i] == 0) {//00
                    oo++;
                } else {//01
                    ol++;

                    D[ne] ^= 1;
                }
            } else {
                if (edge[i] == 0) {//11
                    ll++;

                    D[i] ^= 1;
                    D[ne] ^= 1;
                } else {//10
                    D[i] ^= 1;
                    ol++;

                }
            }
        }
        else{
            if (D[i] == 0) {
                if (edge[i] == 0) {//00
                    oo++;
                } else {//01
                    ol++;
          //          return mp(-1,-1);
//                    ol++;
//
                    D[ne] ^= 1;
                }
            } else {
                if (edge[i] == 0) {//11
 //                   return mp(-1,-1);
                    ll++;
//                    D[ne] ^= 1;
                } else {//10
                    ol++;

                    D[ne] = 0;
                }
            }


        }
    }
    if(D[S] == 1){
        assert(mark == 1);
        return mp(-1,-1);
    }

    assert(mark == 0);

    return mp(ol+2*oo,ol+2*ll);

}



int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		Init();


        len = getlen(0);



        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(b[i][j] == '1'){
             //       cout<<i<<" "<<j<<" "<<(i+j)%n<<endl;
                    R[i]^=1;
                    D[(i+j)%n]^=1;
                }
            }
        }
    //    cout<<"TEST"<<TEST_CASE<<endl;
        for(int i=0;i<n;++i){
            if(R[i] == 0){//00 11
                edge[(i+start)%n] = 0;
            }
            else {//01 10
                edge[(i+start)%n] = 1;
            }
        }
//
//        n = 2;
//        D[0]=0;
//        D[1]=1;
//        len=2;
//        edge[0]=0;
//        edge[1]=1;


        pii ans = mp(0,0);
        bool ok = 1;
        for(int i=0;i<n;++i){
            if(vis[i])
                continue;
            pii ret = bbb(i);
            if(ret.first == -1 || ret.second == -1){
                ok=0;
                break;
            }
            if(ret.first > ret.second){
                swap(ret.first,ret.second);
            }
            ans.first += ret.first;
            ans.second += ret.second;

        }
        if(ok){
            printf("%d %d\n",ans.first,ans.second);
        }
        else{
            printf("No Solution\n");
        }












	}


	return 0;
}





