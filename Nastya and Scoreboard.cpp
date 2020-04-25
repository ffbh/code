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
int h[266];
int d[2010];
int dp[266][10];

int paste(string s) {
    int v = 0;
    for (char c: s) {
        v = v * 2 + c - '0';
    }
    return v;
}

int diff(int a, int b) {
    int num = 0;
    for (int i = 0; i < 20; ++i) {
        int now = a & (1 << i);
        int next = b & (1 << i);
        if (!now && next) {
            num++;
        } else if (now && !next) {
            return -1;
        }
    }
    return num;
}

void input() {
    in >> n >> k;
    for (int i = 1; i <= n; ++i) {
        string s;
        in >> s;
        d[i] = paste(s);
    }

}

void _init() {
    memset(h, -1, sizeof(h));
    h[119] = 0;
    h[18] = 1;
    h[93] = 2;
    h[91] = 3;
    h[58] = 4;
    h[107] = 5;
    h[111] = 6;
    h[82] = 7;
    h[127] = 8;
    h[123] = 9;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 266; ++i)
        for (int j = 0; j < 266; ++j) {
            int dd = diff(i, j);
            if (dd >= 0) {
                dp[i][dd] = max(dp[i][dd], h[j]);
            }
        }
}

int vis[2010][2010];
int ans[2010][2010];
int stick[2010][2010];


int dfs(int pos, int rest) {
    if (pos > n)
        return rest == 0;
    if (vis[pos][rest] != 0)
        return vis[pos][rest];
    vis[pos][rest] = -1;
    for (int i = 0; i <= min(rest, 7); ++i) {
        if (dp[d[pos]][i] != -1 && dfs(pos + 1, rest - i) == 1) {
            vis[pos][rest] = 1;
            if (ans[pos][rest] <= dp[d[pos]][i]) {
                ans[pos][rest] = dp[d[pos]][i];
                stick[pos][rest] = i;
            }
        }
    }
    return vis[pos][rest];
}


void print(int pos, int rest) {
    if (pos > n)
        return;
    cout << ans[pos][rest];
    print(pos + 1, rest - stick[pos][rest]);

}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        int ok = dfs(1, k);
        if (ok != -1) {
            print(1, k);
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }


    return 0;
}





