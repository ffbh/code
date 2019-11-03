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

int c[10];

void input() {
    for (int i = 0; i < 10; ++i)
        in >> c[i];

}

void _init() {


}

bool ok(int len) {
    if (len == 0)
        return 1;
    bool ok = 1;
    for (int i = 1; i <= 9; ++i) {
        if (c[i] == 0) {
            ok = 0;
            break;
        }
        c[i]--;
        for (int j = 0; j <= 9; ++j) {
            if (c[j] < len - 1) {
                ok = 0;
                break;
            }
        }
        c[i]++;
    }
    return ok;
}

int ans[1000010];

void dfs(int pos, int len) {
    if (len == pos) {
        return;
    }
    int st = 1;
    if (pos != 0)
        st = 0;
    for (int i = st; i <= 9; ++i) {
        if (c[i]) {
            c[i]--;
            ans[pos] = i;
            if (ok(len - pos - 1)) {
                c[i]++;
            } else {
                dfs(pos + 1, len);
                break;
            }
        } else {
            assert(pos == len - 1);
            ans[pos] = i - 1;
            break;
        }
    }
}

int work() {
    for (int i = 1; i <= 9; ++i) {
        if (c[i] == 0) {
            ans[0] = i;
            return 1;
        }
    }
    for (int len = 2;; ++len) {
        if (!ok(len)) {
            if (c[0] >= len - 1) {
                dfs(0, len);
                ans[len - 1]++;
                for (int k = len - 1; k >= 0; --k) {
                    while (ans[k] > 9) {
                        ans[k] -= 10;
                        ans[k - 1]++;
                    }
                }
            } else {
                ans[0] = 1;
                for (int p = 1; p < len; ++p)
                    ans[p] = 0;
            }
            return len;
        }
    }
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        int len = work();
        for (int i = 0; i < len; ++i)
            printf("%d", ans[i]);
        cout << endl;


    }


    return 0;
}





