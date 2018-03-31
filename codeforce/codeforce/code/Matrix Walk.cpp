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


int n,a[200010];

void input(){
	in>>n;
	for(int i=1;i<=n;++i)
		in>>a[i];


}

bool judge(int y){
    for(int i=1;i<n;++i){
        if(abs(a[i]-a[i+1]) == 1){
            if((a[i]-1)/y!=(a[i+1]-1)/y)
                return 0;
        }

    }
    return 1;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        set<int> d;
        for(int i=1;i<n;++i){
            int diff = abs(a[i]-a[i+1]);
            if(diff == 0){
                cout<<"NO"<<endl;
                return 0;
            }
            d.insert(diff);
            if(d.size()>2){
                cout<<"NO"<<endl;
                return 0;
            }
        }

        if(d.empty()){
            cout<<"YES"<<endl;
            cout<<(int)1e9<<" "<<(int)1e9<<endl;
        }
        else if(d.size()==1){
            cout<<"YES"<<endl;
            cout<<(int)1e9<<" "<<*d.begin()<<endl;
        }
        else{
            if(*d.begin() != 1){
                cout<<"NO"<<endl;
            }
            else{
                int Y = *(++d.begin());
                if(judge(Y)) {
                    cout << "YES" << endl;
                    cout << (int) 1e9 << " " << Y << endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }

        }













	}


	return 0;
}





