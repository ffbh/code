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

int n, k;
int a[8010];

void input() {
    in >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int t;
        in >> t;
        a[t]++;
    }


}

void _init() {


}


int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        sort(a + 1, a + k + 1);
        set<int> S;
        for (int i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= k; ++j) {
                if (a[i] + a[j] >= a[k])
                    S.insert(a[i] + a[j]);
            }
        }
        S.insert(a[k]);
        LL ans = 1e18;
        for (LL s : S) {
            int L, R;
            L = 1;
            R = k;
            LL rides = 0;
            while (L <= R) {
                if (a[L] + a[R] <= s) {
                    L++;
                }
                R--;
                rides++;
            }
            ans = min(ans, rides * s);
        }
        cout << ans << endl;

    }


    return 0;
}





