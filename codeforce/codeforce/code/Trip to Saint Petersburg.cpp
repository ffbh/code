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
vector<pll > V[200010];
pll tag[200010];

void input() {
    in >> n >> k;
    for (int i = 1; i <= n; ++i) {
        LL l, r, p;
        in >> l >> r >> p;
        tag[i] = mp(l, r);
        V[l].push_back(mp(r, p));
    }
}

void _init() {


}

LL a[1600010];
LL idx[1600010];
LL lazy[1600010];
vector<int> seq;

void build(int root, int l, int r) {
    a[root] = 0;
    lazy[root] = 0;
    idx[root] = l;
    if (l < r) {
        int m = (l + r) / 2;
        build(lson, l, m);
        build(rson, m + 1, r);
    }
}

void pushdown(int root) {
    if (lazy[root]) {
        a[lson] += lazy[root];
        a[rson] += lazy[root];
        lazy[lson] += lazy[root];
        lazy[rson] += lazy[root];
        lazy[root] = 0;
    }
}

LL update(int root, int l, int r, int L, int R, LL add) {
    if (L <= l && r <= R) {
        a[root] += add;
        lazy[root] += add;
    } else if (l > R || r < L) {

    } else {
        pushdown(root);
        int m = (l + r) / 2;
        LL lret = update(lson, l, m, L, R, add);
        LL rret = update(rson, m + 1, r, L, R, add);
        a[root] = max(lret, rret);
        if (lret > rret) {
            idx[root] = idx[lson];
        } else {
            idx[root] = idx[rson];
        }
    }
    return a[root];
}

pll query(int root, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return mp(a[root], idx[root]);
    } else if (l > R || r < L) {
        return mp((LL) -1e18, -1);
    } else {
        pushdown(root);
        int m = (l + r) / 2;
        pll lret = query(lson, l, m, L, R);
        pll rret = query(rson, m + 1, r, L, R);
        return max(lret, rret);
    }


}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        build(1, 1, 200000);
        for (int i = 1; i <= 200000; ++i) {
            update(1, 1, 200000, i, 200000, -k);
        }
        for (int i = 1; i <= 200000; ++i) {
            for (auto x : V[i]) {
                update(1, 1, 200000, x.first, 200000, x.second);
            }
        }
        LL ans = (LL) -1e18;
        LL ansl, ansr;
        for (int i = 1; i <= 200000; ++i) {
            pll q = query(1, 1, 200000, i, 200000);
            if (q.first > ans) {
                ans = q.first;
                ansl = i;
                ansr = q.second;
            }
            for (auto x : V[i]) {
                update(1, 1, 200000, x.first, 200000, -x.second);
            }
            update(1, 1, 200000, i, 200000, k);

        }
        if (ans > 0) {
            seq.clear();
            for (int i = 1; i <= n; ++i) {
                if (tag[i].first >= ansl && tag[i].second <= ansr) {
                    seq.push_back(i);
                }
            }
            printf("%lld %lld %lld %d\n", ans, ansl, ansr, (int) seq.size());
            for (int k : seq) {
                printf("%d ", k);
            }
            cout << endl;
        } else {
            cout << 0 << endl;
        }
    }


    return 0;
}





