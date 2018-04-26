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


int n,a[10010];

void input(){
	in>>n;
	for(int i=1;i<=n;++i)
		in>>a[i];


}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int one = 0;
		int sg = 0;
		int num = 0;
		for(int i=1;i<=n;++i){
			if(a[i] == 1){
				one++;
			}
			else if(a[i] > 1){
				sg ^= a[i];
				num++;
			}
		}
        one %= 2;
		if(num == 1 ){
			cout<<1<<endl;
		}
		else if(num == 0){
			if(one % 2 == 1){
				cout<<2<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
        else{
            if(sg ^ one != 0){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }












	}


	return 0;
}





