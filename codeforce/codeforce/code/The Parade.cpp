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


LL n, k;
LL a[30010];
LL b[30010];

void input() {
    in >> n >> k;
    for (int i = 1; i <= n; ++i)
        in >> a[i];

}

void _init() {


}

bool ok(LL m) {
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
    }
    LL rows = 0;

    for (int i = 1; i <= n; ++i) {
        if (b[i - 1] + b[i] >= m) {
            rows++;
            b[i] -= (m - b[i - 1]);

            b[i - 1] = 0;
        }
        rows += b[i] / m;
        b[i] %= m;
    }
    if (m == 6) {
        int t = 0;
    }
    if (rows >= k)
        return 1;

//    for (int i = 1; i <= n; ++i) {
//        b[i] = a[n - i + 1];
//    }
//    rows = 0;
//    rest = 0;
//    for (int i = 1; i <= n; ++i) {
//        if (rest + b[i] >= m) {
//            rows++;
//            rest = 0;
//            b[i - 1] = 0;
//            b[i] -= (m - rest);
//        }
//        rows += b[i] / m;
//        rest = b[i] % m;
//        b[i] = rest;
//    }
//    if (rows >= k)
//        return 1;

//    if (m == 6) {
//        for (int i = 1; i <= n; ++i) {
//            if (b[i]) {
//                Debug(i);
//                Debug(b[i]);
//                cout << endl;
//            }
//        }
//        LL sum = 0;
//        for (int i = 1; i <= n; ++i)
//            sum += a[i];
//        Debug(sum);
//        Debug(sum / k);
//        Debug(sum % k);
//
//    }

    return 0;
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        LL L = 1;
        LL R = 1e17;
        LL ans = 0;

        while (L <= R) {
            LL mid = (L + R) / 2;
            if (ok(mid)) {
                ans = mid * k;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        cout << ans << endl;

    }


    return 0;
}





