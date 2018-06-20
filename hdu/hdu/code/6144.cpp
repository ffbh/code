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


string str;


void input(){
	in>>str;


}

LL pw[10010];
LL mod =  1000000007;

void add(LL& a,LL b){
    a%=mod;
    b%=mod;
    a+=b;
    a%=mod;
    if(a<0)
        a+=mod;
}


string getval(int &p){
    int en = p;
    p--;
    while(isdigit(str[p])){
        p--;
    }
    assert(str[p] == '(');
    p--;
    return str.substr(p+2,en - p - 2);
}

int main(){

    pw[0] = 1;
    for(int i=1;i<10010;++i){
        pw[i] = pw[i-1] * 10 % mod;
    }

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		int pos = str.length()-1;
		LL ans = 0;
		int ten = 0;
		while(pos >= 0){
		    if(isdigit(str[pos])){
                add(ans,pw[ten] * (str[pos]-'0'));
                pos--;
                ten++;
		    }
		    else if(str[pos]==')'){
                string time = getval(pos);
                assert(str[pos]=='#');
                pos--;
                assert(str[pos]==')');
                string dig = getval(pos);
                for(int k=1;k<=time[0]-'0';++k){
                    for(int j=(int)dig.length()-1;j>=0;--j){
                        add(ans,pw[ten] * (dig[j]-'0'));
                        ten++;
                    }
                }
		    }
		    else{
		        assert(0);
		    }
		}

        printf("%lld\n",ans);

	}


	return 0;
}





