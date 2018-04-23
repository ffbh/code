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


LL n;



vector<int> ans;

void add(int p) {
    vector<pii > all;
    ans.push_back(p);
    all.push_back(mp(p, 0));
    int pos = 1;
    while (!all.empty()) {
        while (!all.empty() && (pos - all.back().second) * 2 >= all.back().first) {
            all.pop_back();
        }
        if (!all.empty()) {
            int v = pos - all.back().second;
            ans.push_back(v);
            all.push_back(mp(v, pos));
        }
        pos++;
    }
}

int p[]={-1,1,1,2,1,2,3,1,2,3,4};

int cale(LL k){
    if(k < 10){
        return p[k];
    }
    LL a = 1,b=2,sum=1;
    LL pos = -1;
    while(sum < k){
        sum += b;
        if(sum >= k){
            LL diff = sum - k;
            pos = b - diff;
            break;
        }
        LL c = a + b;
        a = b;
        b = c;
    }
    assert(pos >= 1);
    return pos;
}

int ppp[]={0,0,1,2,3,1,5,1,2};

int ccc(int k){
    if(k <= 3){
        return ppp[k];
    }
    int sum = 3;
    while(sum < k){
     //   cout<<sum<<endl;
        ans.clear();
        add(sum);
        int ad = ans.size();
        if(sum + ad < k) {
            sum += ad;
        }
        else{

            return  ans[k - sum - 1];
        }
    }
    assert(0);
    return -1;

}

int main(){

    while(in>>n){
       // ans.clear();

       // LL p = 1;
        //ans.push_back(0);
//        int ok = -1;
//        while(p<=n){
//            if(ans.size()==3){
//                int t = 0;
//            }
//            add(ans.size());
//            if(p + ans.size() >= n){
//                ok = ans[n-p-1];
//                break;
//            }
//            p += ans.size();
//        }
//        cout<<sk<<endl;

        n--;
        int ok = cale(n);
        ok = ccc(ok);
        if(ok){
            printf("%d\n",ok);
        }
        else{
            printf("lose\n");
        }







    }


    return 0;
}




