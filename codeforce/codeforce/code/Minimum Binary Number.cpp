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
string s;

void input(){
	in>>n>>s;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int a,b;
		a = b = 0;
		for(char c : s){
			if(c=='0'){
				a++;
			}
			else{
				b++;
			}
		}

		if(b){
			cout<<1;
		}
		for(int i=0;i<a;++i){
			cout<<0;
		}
		cout<<endl;










	}


	return 0;
}





