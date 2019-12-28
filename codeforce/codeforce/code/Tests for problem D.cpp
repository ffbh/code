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
vector<int> vi[500010];
pii ans[500010];
int all[500010];
int direct_son[500010];

void input() {
    in >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        in >> a >> b;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
}

void _init() {


}

int pre_dfs(int p, int f) {
    all[p] = 0;
    direct_son[p] = 0;
    for (int son : vi[p]) {
        if (son == f)
            continue;
        direct_son[p]++;
        all[p] += pre_dfs(son, p);
    }
    all[p]++;
    return all[p];
}

void dfs(int p, int f, int l, int r) {
    if (direct_son[p] == 0) {
        ans[p].second = r;
        return;
    }
    ans[p].second = l + direct_son[p] + 1;
    int ls = l + 1;
    int rs = r;
    for (int son : vi[p]) {
        if (son == f)
            continue;
        ans[son].first = ls++;
        int lls = rs - all[son] * 2 + 2;
        dfs(son, p, lls - 1, rs);
        rs = lls - 1;
    }
}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        pre_dfs(1, -1);
        ans[1].first = 1;
        dfs(1, -1, 1, 2 * n);

        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }

    }


    return 0;
}





