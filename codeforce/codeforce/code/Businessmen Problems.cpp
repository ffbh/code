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


unordered_map<LL,LL> M;
int n,m;

void input(){
	in>>n;
	for(int i=1;i<=n;++i){
		LL x,y;
		in>>x>>y;
		if(M.count(x)){
			y = max(y,M[x]);
		}
		M[x] = y;
	}
	in>>m;
	for(int i=1;i<=m;++i){
		LL x,y;
		in>>x>>y;
		if(M.count(x)){
			y = max(y,M[x]);
		}
		M[x] = y;
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		LL sum = 0;
		for(auto k : M){
			sum += k.second;
		}

		cout<<sum<<endl;










	}


	return 0;
}





