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



string s;

void input(){
	in>>s;


}

LL dp[110][10][2][2];
LL mod = 1000000007;
void add(LL& a,LL b){
    a+=b;
    a%=mod;
    if(a<0)
        a+=mod;
}

string aim;

LL dfs(int pos,int pre,int f,int ok){
	LL& ref = dp[pos][pre][f][ok];
	if(ref != -1)
	    return ref;
	ref = 0;
	if(pos == aim.length()){
	    return ref = 1;
	}
	int mm = 9;
	if(!ok){
	    mm = aim[pos]-'0';
	}
	int st = 0;
	if(pos == 0)
	    st = 1;
	for(int i=st;i<=mm;++i){
	    if(pre > i && f)
            continue;
        add(ref,dfs(pos+1,i,i>pre||f,ok||i<mm));
	}
    return ref;
}


LL ppp[110];

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	ppp[0] = 0;
    aim = "9";
    while(aim.length() < 108){
        memset(dp,-1,sizeof(dp));
        ppp[aim.length()] = dfs(0,9,0,0);
        add(ppp[aim.length()],ppp[aim.length()-1]);
        aim += '9';
    }

	while (TEST_CASE-- > 0){
		input();
		while(s.length() > 1 && s[0] == '0'){
			s = s.substr(1);
		}


        LL sum = ppp[s.length()-1];
        aim = s;
        memset(dp,-1,sizeof(dp));
        add(sum,dfs(0,9,0,0));

        printf("%lld\n",sum);








	}


	return 0;
}





