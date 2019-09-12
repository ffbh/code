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
ifstream in("/Users/jiazhi.zhou/CLionProjects/acm/InOutput/input.txt");
#define Debug(v) cerr<<#v<<"="<<v<<'\n'
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#define Debug(v) ;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)
#define FFLUAHALL fflush(stdin);fflush(stdout);



int n;
int a[100010];

void input(){
    in>>n;
    for(int i=1;i<=n;++i){
        in>>a[i];
    }


}

void _init(){



}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		 _init();
		input();


        LL val = -1;
        int odd = 0;
        bool ok = false;
        sort(a+1,a+n+1);
        int num = 0;
        for(int i=1;i<=n;++i){
            if(i > 1 && a[i] == a[i-1]){
                num++;
                if(a[i] == 0){
                    ok = true;
                }
                else if(i >= 3 && a[i-2] >= a[i] - 1){
                    ok = true;
                }

            }
            if(a[i] & 1)
                odd++;
        }
        odd += n / 2;
        odd &= 1;
        if(!ok && num < 2){
            if(odd == 0){
                cout<<"cslnb"<<endl;
            }
            else{
                cout<<"sjfnb"<<endl;
            }
        }
        else{
            cout<<"cslnb"<<endl;
        }












	}


	return 0;
}





