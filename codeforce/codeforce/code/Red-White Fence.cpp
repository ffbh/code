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
vector<int> A;
vector<int> B;
LL mod = 998244353;
LL dp[5][1200010];

void add(LL &a, LL b) {
    a %= mod;
    b %= mod;
    a += b;
    a %= mod;
    if (a < 0) {
        a += mod;
    }
}

void input() {
    //  in >> n >> k;
    scanf("%d%d", &n, &k);
    A.resize(n);
    B.resize(k);
    for (int i = 0; i < n; ++i) {
        //    in >> A[i];
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < k; ++i) {
        //   in >> B[i];
        scanf("%d", &B[i]);
        dp[i][0] = 1;
    }

}

void _init() {
    A.clear();
    B.clear();
}


int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        sort(A.begin(), A.end());
        int pre = -1;
        int num = 0;

        for (int a : A) {
            if (a == pre) {
                num++;
            } else {
                if (num >= 2)
                    num = 2;
                if (num >= 1 && num <= 2) {
                    for (int p = 0; p < k; ++p) {
                        int b = B[p];
                        if (pre >= b)
                            continue;
                        for (int i = 1200000; i >= 2; --i) {
                            add(dp[p][i], dp[p][i - 2] * 2);
                            if (i >= 2 * 2 && num == 2) {
                                add(dp[p][i], dp[p][i - 2 * 2]);
                            }
                        }
                    }
                }
                num = 1;
                pre = a;
            }
        }
        if (num >= 2)
            num = 2;
        assert(num >= 1 && num <= 2);
        for (int p = 0; p < k; ++p) {
            int b = B[p];
            if (pre >= b)
                continue;
            for (int i = 1200000; i >= 2; --i) {
                add(dp[p][i], dp[p][i - 2] * 2);
                if (i >= 2 * 2 && num == 2) {
                    add(dp[p][i], dp[p][i - 2 * 2]);
                }
            }
        }

        int Q;
        //  in >> Q;
        scanf("%d", &Q);
        while (Q-- > 0) {
            int q;
            //  in >> q;
            scanf("%d", &q);
            LL ans = 0;
            for (int p = 0; p < k; ++p) {
                int aim = q - 2 * B[p] - 2;
                if (aim >= 0) {
                    add(ans, dp[p][aim]);
                }
            }
            cout << ans << endl;
        }


    }


    return 0;
}





