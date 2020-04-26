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
int n, m;
int d[10010];
int G, R;

int dp[10010][1010];


void input() {
    in >> n >> m;
    for (int i = 1; i <= m; ++i)
        in >> d[i];
    in >> G >> R;

}

void _init() {
    for (int i = 0; i < 10010; i++)
        for (int j = 0; j < 1010; ++j)
            dp[i][j] = 1e9;

}


int bfs() {
    deque<pii > Q;
    Q.push_back(mp(1, G));
    dp[1][G] = 0;
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop_front();
        int now = u.first;
        int l = u.first - 1;
        int r = u.first + 1;

        if (l >= 1 && d[now] - d[l] <= u.second) {
            int rest = u.second - (d[now] - d[l]);
            if (rest > 0) {
                if (dp[l][rest] > dp[u.first][u.second] + d[now] - d[l]) {
                    dp[l][rest] = dp[u.first][u.second] + d[now] - d[l];
                    Q.push_front(mp(l, rest));
                }
            } else {
                if (dp[l][G] > dp[u.first][u.second] + d[now] - d[l] + R) {
                    dp[l][G] = dp[u.first][u.second] + d[now] - d[l] + R;
                    Q.push_back(mp(l, G));
                }
            }
        }
        if (r <= m && d[r] - d[now] <= u.second) {
            int rest = u.second - (d[r] - d[now]);
            if (rest > 0) {
                if (dp[r][rest] > dp[u.first][u.second] + d[r] - d[now]) {
                    dp[r][rest] = dp[u.first][u.second] + d[r] - d[now];
                    Q.push_front(mp(r, rest));
                }
            } else {
                if (dp[r][G] > dp[u.first][u.second] + d[r] - d[now] + R) {
                    dp[r][G] = dp[u.first][u.second] + d[r] - d[now] + R;
                    Q.push_back(mp(r, G));
                }
            }
        }


    }
    int ans = 1e9;
    for (int i = 0; i < 1010; ++i)
        ans = min(ans, dp[m][i]);
    if (dp[m][G] != 1e9)
        ans = min(ans, dp[m][G] - R);
    if (ans == 1e9)
        ans = -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        sort(d + 1, d + m + 1);
        cout << bfs() << endl;
    }


    return 0;
}