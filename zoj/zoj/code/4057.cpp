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


int N;
vector<int> Vi[40];
void Init(){
	for(int i=0;i<40;++i)
		Vi[i].clear();
}

void input(){
in>>N;


}


int getH(LL v) {
	for (int i = 39; i >= 0; --i) {
		if ((1L << i) & v) {
			return i;
		}
	}
	assert(0);
	return -1;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){

		input();
		Init();
		for(int i=1;i<=N;++i){
			int b;
			in>>b;
			Vi[getH(b)].push_back(i);
		}
		int ans=  0;
		for(int i=0;i<40;++i)
			ans = max(ans,(int)Vi[i].size());
		cout<<ans<<endl;












	}


	return 0;
}





