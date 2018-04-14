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

LL N,C,F;
pll data[100010];
LL L[100010],R[100010];

void input(){
    in>>N>>C>>F;
    for(int i=1;i<=C;++i)
        in>>data[i].first>>data[i].second;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


        sort(data+1,data+C+1);
        int need = N / 2;
        priority_queue<LL> Q;
        LL sum = 0;
        for(int i=1;i<=C;++i){
            sum += data[i].second;
            Q.push(data[i].second);
            if(Q.size() > need){
                sum -= Q.top();
                Q.pop();
            }
            if(Q.size() == need){
                L[i] = sum;
            }
            else{
                L[i] = (LL)1e12;
            }
        }

        while(!Q.empty())
            Q.pop();
        sum = 0;
        for(int i=C;i>=1;--i){
            sum += data[i].second;
            Q.push(data[i].second);
            if(Q.size() > need){
                sum -= Q.top();
                Q.pop();
            }
            if(Q.size() == need){
                R[i] = sum;
            }
            else{
                R[i] = 1e12;
            }
        }
        L[0] = (LL)1e12;
        R[C+1] = (LL)1e12;
        LL ans = -1;
        for(int i=1;i<=C;++i){
            LL all = L[i-1]+R[i+1]+data[i].second;
            if(all <= F)
                ans = data[i].first;

        }

        cout<<ans<<endl;







	}


	return 0;
}





