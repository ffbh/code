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

int n;
pair<pii,int> d[300010];


void input(){
    in>>n;
    for(int i=0;i<n;++i) {
        in >> d[i].first.first >> d[i].first.second;
        d[i].first.second = -d[i].first.second;
        d[i].second = i+1;
    }

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        sort(d,d+n);
        int mmax = -1;
        int pj = -1,pi = -1;
        for(int i=0;i<n;++i){
            d[i].first.second = -d[i].first.second;
            if(d[i].first.second > mmax){
                pi = d[i].second;
                mmax = d[i].first.second;
            }
            else{
                pj = d[i].second;
                break;
            }
        }
        if(pj != -1) {
            swap(pi,pj);
            cout << pi  << " " << pj << endl;

        }
        else{
            cout<<"-1 -1"<<endl;
        }














	}


	return 0;
}





