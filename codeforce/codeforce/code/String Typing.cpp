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
string str;


void input(){
in>>n>>str;


}

bool ok(int len){
	int off = len;
	for(int i=0;i<len;++i){
		if(str[i] != str[len+i])
			return 0;
	}
	return 1;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for(int i=n/2;i>=1;--i){
			if(ok(i)){
				cout<<n-i+1<<endl;
				return 0;
			}
		}
		cout<<n<<endl;















	}


	return 0;
}





