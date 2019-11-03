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

int n, m, k;
string s[60];
vector<pii > vi[60];
vector<int> ans;
int vis[60];

void input() {
    in >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        in >> s[i];


}

void _init() {
    memset(vis, -1, sizeof(vis));
    ans.clear();
    for (int i = 0; i < 60; ++i)
        vi[i].clear();

}

int cmp(string a, string b) {
    int A, B;
    A = B = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] == b[i])
            A++;
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < m; ++i) {
        if (a[i] == b[i])
            B++;
    }
    if (A < k && B < k) {
        return -1;
    } else if (A >= k && B >= k) {
        return 0;
    } else if (A >= k) {
        return 1;
    } else {
        return 2;
    }
}

int cale(int now, int mark) {
    if (mark == 1) {
        return now;
    } else if (mark == 2) {
        return 3 - now;
    } else {
        assert(0);
    }
}

set<int> all[3];

bool dfs(int v) {
    all[vis[v]].insert(v);
    for (pii son : vi[v]) {
        int aim = cale(vis[v], son.second);
        if (vis[son.first] == -1) {
            vis[son.first] = aim;
            if (!dfs(son.first))
                return false;
        }
        if (vis[son.first] != aim) {
            return false;
        }
    }
    return true;

}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        bool fail = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int ret = cmp(s[i], s[j]);
                if (ret == -1) {
                    fail = true;
                } else if (ret == 0) {
                    //ignore
                } else {
                    vi[i].emplace_back(mp(j, ret));
                    vi[j].emplace_back(mp(i, ret));
                }
            }
        }


        if (!fail) {
            for (int i = 1; i <= n; ++i) {
                if (vis[i] == -1) {
                    vis[i] = 1;
                    all[1].clear();
                    all[2].clear();
                    bool r = dfs(i);
                    if (!r) {
                        fail = true;
                        break;
                    }
                    if (all[1].size() < all[2].size()) {
                        for (auto _b : all[1]) {
                            ans.push_back(_b);
                        }
                    } else {
                        for (auto _b : all[2]) {
                            ans.push_back(_b);
                        }
                    }
                }
            }
        }
        if (fail) {
            printf("-1\n");
        } else {
            printf("%d\n", (int) ans.size());
            for (int c : ans) {
                printf("%d ", c);
            }
            printf("\n");
        }

    }


    return 0;
}





