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
LL a[300010], b[300010];
LL dp[300010][3];

void input() {
    // in >> n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        // in >> a[i] >> b[i];
        scanf("%lld%lld", &a[i], &b[i]);

}

void _init() {


}


int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        for (int k = 0; k <= 2; ++k)
            dp[1][k] = k * b[1];
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= 2; ++j) {
                LL mmin = ((LL) 1e18) + 10;
                for (int k = 0; k <= 2; ++k) {
                    if (a[i - 1] + k != a[i] + j) {
                        mmin = min(mmin, dp[i - 1][k]);
                    }
                }
                dp[i][j] = mmin + b[i] * j;
            }
        }
        printf("%lld\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));

    }


    return 0;
}





