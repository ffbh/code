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

LL a, b;

void input() {
    in >> a >> b;

}

void _init() {


}

LL binary(LL m) {
    return m * (m + 1) / 2;
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        LL diff = abs(a - b);
        LL l = 0, r = diff, ans = 0;
        while (l <= r) {
            LL m = (l + r) / 2;
            if (binary(m) <= diff) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        LL sum = diff - binary(ans);
        while (sum != 0) {
            ans++;
            sum += ans;
            sum %= 2;
        }
        cout << ans << endl;


    }


    return 0;
}





