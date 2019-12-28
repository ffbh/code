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
int A[100010], B[100010];
map<int, int> M;

void input() {
    in >> n;
    for (int i = n; i >= 1; --i)
        in >> A[i];
    for (int i = 1; i <= n; ++i)
        in >> B[i];

}

void _init() {
    M.clear();

}

int gget(int m, int diff) {
    return diff - m;

}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (A[i] == 1)
                sum++;
            if (B[i] == 1)
                sum++;
        }
        int diff = sum - (2 * n - sum);
        M[0] = 0;
        int m = 0;
        for (int i = 1; i <= n; ++i) {
            if (B[i] == 1) {
                m++;
            } else {
                m--;
            }
            if (!M.count(m)) {
                M[m] = i;
            }
        }
        int ans = 2 * n;
        if (diff == 0) {
            ans = 0;
        }
        m = 0;
        if (M.count(gget(m, diff))) {
            ans = min(ans, M[gget(m, diff)]);
        }
        for (int i = 1; i <= n; ++i) {
            if (A[i] == 1) {
                m++;
            } else {
                m--;
            }
            if (M.count(gget(m, diff))) {
                int cost = i + M[gget(m, diff)];
                ans = min(ans, cost);
            }
        }
        cout << ans << endl;
    }


    return 0;
}





