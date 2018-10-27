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

set<int> si;
int limit;

void dfs(int pos,int num){
	if(pos == limit){
		si.insert(num);
	}
	else{
		dfs(pos+1,num+1);
		dfs(pos+1,num+5);
		dfs(pos+1,num+10);
		dfs(pos+1,num+50);
	}
}

void input(){



}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        int pre = 0;
        int nnnn = 0;
        for(int i=1;i<=20;++i){
            si.clear();
            limit = i;
            dfs(0,0);
            int now = si.size() - pre;
            cout<<i<<"   :"<<si.size()<<"     :"<<si.size()-pre<<"    :"<<now - nnnn<<endl;
            pre = si.size();
            nnnn = now;

        }












	}


	return 0;
}





