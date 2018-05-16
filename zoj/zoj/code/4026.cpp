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


int n;
int num[20];
int a[20],b[20];
void Init(){
    memset(num,0,sizeof(num));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
}



void input(){
    in>>n;
    for(int i=1;i<=n;++i){
        char c;
        in>>c;
        int v;
        if(c == 'A')
            v = 1;
        else if(c == 'J'){
            v = 11;
        }
        else if(c == 'Q'){
            v = 12;
        }
        else{
            v = c-'0';
            if(v == 1){
                v = 10;
                in>>c;
            }
        }
        num[v]++;

    }


}


LL dp[10][10];

LL gcd(LL a,LL b){
    if(a > b)
        swap(a,b);
    if(a == 0){
        return b;
    }
    else{
        return gcd(a,b%a);
    }
}




void PPP(int k){
    if(a[k] == 0){
        printf(" 0");
    }
    else if(a[k] == b[k]){
        printf(" 1");
    }
    else{
        int g = (int)gcd(a[k],b[k]);
        printf(" %d/%d",a[k]/g,b[k]/g);
    }

}

int main(){

    int TEST_CASE = 1;
    in >> TEST_CASE;

    while (TEST_CASE-- > 0){

        Init();
        input();
        a[1] = b[1] = 1;
        for(int pp=2;pp<=12;++pp){
            int A = num[1];
            int B = num[pp];
            memset(dp,0,sizeof(dp));
            dp[A][B] = 1;

            for(int i=A;i<4;++i) {
                for (int j = B; j <= 4; ++j) {
                    dp[i + 1][j] += dp[i][j];
                    dp[i][j + 1] +=  dp[i][j];
                }
            }
            a[pp] = b[pp] = 0;
            for(int i=0;i<=4;++i) {
                if (i == 4) {
                    a[pp] += dp[4][i];
                }
                b[pp] += dp[4][i];
            }
        }

        printf("1");
        for(int i=2;i<=12;++i)
            PPP(i);
        cout<<endl;



    }


    return 0;
}





