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

bool ok(int a,int b){
    while(a<b){
        if(s[a] != s[b])
            return 1;
        a++;
        b--;
    }
    return 0;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        int ans = 0;
		for(int i=0;i<s.length();++i)
			for(int j=i;j<s.length();++j){
				if(ok(i,j)){
				    ans = max(ans,j-i+1);
				}

		    }

         cout<<ans<<endl;


	}


	return 0;
}





