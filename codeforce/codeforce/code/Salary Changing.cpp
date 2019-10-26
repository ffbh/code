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

LL n, s;
pll all[200010];
LL limit[200010];

void input() {
    in >> n >> s;
    for (int i = 0; i < n; ++i) {
        in >> all[i].first >> all[i].second;
    }

}

void _init() {


}

bool ok(LL m) {
    int num = 0;
    LL S = s;
    for (int i = 0; i < n; ++i) {
        S -= all[i].first;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (all[i].first >= m) {
            num++;
        } else if (all[i].second >= m) {
            LL cost = m - all[i].first;
            if (S >= cost) {
                S -= cost;
                num++;
            }
        }
    }
    return num >= n / 2 + 1;
}


int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        sort(all, all + n);
        LL ans = 0;
        LL l = 0, r = s;
        while (l <= r) {
            LL m = (l + r) / 2;
            if (ok(m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << ans << endl;

    }


    return 0;
}


























