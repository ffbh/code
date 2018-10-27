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

LL n,x,y;
string s;



void input(){
	in>>n>>x>>y;
	in>>s;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		char pre = '1';
		LL num = 0;
		for(char c : s){
			if(c=='1') {
				pre = '1';
			}
			else{
				if(pre != '0'){
					num++;
					pre = '0';
				}
			}
		}

        if(num == 0){
		    cout<<0<<endl;
		}
		else{
		    cout<<min(num*y,(num-1)*x+y)<<endl;

		}











	}


	return 0;
}





