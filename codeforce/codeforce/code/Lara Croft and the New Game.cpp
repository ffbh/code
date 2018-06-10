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


LL n,m,k;

void input(){
	in>>n>>m>>k;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if(k < n){
		    cout<<k+1<<" "<<1<<endl;
		}
		else{
            k -= n;
            LL x,y;
            x = k / (m-1);
            y = k % (m-1);
            if(x % 2 == 0){
                y += 2;
            }
            else{
                y = m - y;
            }
            x = n - x;
            cout<<x<<" "<<y<<endl;
		}












	}


	return 0;
}





