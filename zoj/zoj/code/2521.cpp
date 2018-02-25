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
ifstream in("C:\\input.txt");
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


vector<int> V[10];

void Init(){
	for (int i = 0; i < 10; ++i){
		if (i != 8){
			V[8].push_back(i);
		}
	}
	V[0].push_back(7);
	V[0].push_back(1);
	V[3].push_back(1);
	V[3].push_back(7);
	V[4].push_back(1);
	V[6].push_back(5);
	V[7].push_back(1);    
	V[9].push_back(1);
	V[9].push_back(3);
	V[9].push_back(4);
	V[9].push_back(5);
	V[9].push_back(7);

}

void input(){



}


int main(){

	Init();

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();















	}


	return 0;
}





