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
pll all[200010];

void input() {
    in >> n;
    for (int i = 0; i < n; ++i) {
        in >> all[i].first >> all[i].second;
    }
}


void _init() {


}


int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        sort(all, all + n);
        multiset<LL> S;
        LL ans = 0;
        int p = 0;
        for (int i = n - 1; i >= 0; --i) {
            S.insert(all[i].second);
            if (all[i].first - p > i) {
                p++;
                ans += *S.begin();
                S.erase(S.begin());
            }
        }
        cout << ans << endl;

    }


    return 0;
}





