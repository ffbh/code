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






void input(){



}

int sg[1010];
void test(){
    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 2;
    set<int> S;
    for(int i=3;i<100;++i){

        for(int j=0;j<i;++j)
            for(int k=j;k<i;++k)
                S.insert(sg[j] ^ sg[k]);
        for(int j=0;;++j){
            if(!S.count(j)){
                sg[i] = j;
                break;
            }
        }

    }

    for(int i=1;i<100;i+=6){
        cout<<sg[i+5] - sg[i-1]<<endl;

    }

}


int main(){

    test();


	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();















	}


	return 0;
}





