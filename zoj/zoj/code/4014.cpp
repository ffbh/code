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


int a[110][110],A,B,n,m;

void input(){
	in>>n>>m>>A>>B;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			in>>a[i][j];


}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if(A > B){
			cout<<"No Solution"<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(a[i][j] < A || a[i][j] > B){
					ans++;
					}
			cout<<ans<<endl;
		}














	}


	return 0;
}





