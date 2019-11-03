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
int a[400010];

void input() {
    in >> n >> m;
    for (int i = 1; i <= m; ++i)
        in >> a[i];

}

void _init() {


}

int ansL[100010], ansR[100010];
int p[100010];
int fp[100010];

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            fp[i] = i;
            ansL[i] = ansR[i] = i;
        }
        for (int k = 1; k <= m; ++k) {
            int v = a[k];
            int pos = fp[v];
            if (pos > 1) {
                int a1 = p[pos];
                int a2 = p[pos - 1];
                ansL[a1] = min(ansL[a1], pos - 1);
                ansR[a2] = max(ansR[a2], pos);
                swap(p[pos], p[pos - 1]);
                swap(fp[a1], fp[a2]);

            }

        }

    }
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", ansL[i], ansR[i]);
    }

    return 0;
}





