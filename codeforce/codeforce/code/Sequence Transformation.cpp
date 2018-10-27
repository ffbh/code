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



int n;

void input(){
	in>>n;


}


void ppp(int v ,int time){
    for(int i=1;i<=time;++i){
        printf("%d ",v);
    }
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		int need = n;
		int mul = 1;
		int limit = n;
		while(need > 1){
		    int aim = 2;
		    int len = limit / 2;
		   while(aim <= limit &&limit / (aim + 1) == len){
		       aim++;
		   }
		   ppp(mul,limit - len);
		   mul *= aim;
		   need -= (limit - len);
		   limit = len;

		}
        assert(need == 1);
		cout<<mul<<endl;















	}


	return 0;
}





