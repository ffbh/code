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
int a[30];

void input(){
	in>>n;
	for(int i=1;i<=n;++i)
		in>>a[i];


}

bool clockwise(){
	for(int i=1;i<=n;++i){

		if(a[i] == 0){
            int edge = i - 1;
			return edge % 2 == 1;
		}
	}
	assert(0);
}


bool unclockwise(){
    for(int i = n;i>=1;--i){
        if(a[i] == 0){
            int edge = n - i;
            return edge % 2 == 1;
        }

    }
    assert(0);

}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        if(clockwise() || unclockwise()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
















	}


	return 0;
}





