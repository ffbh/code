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
int a[100010], b[100010], c[100010];

void input() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> a[i];

}

void _init() {
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

}


int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        bool ok = 1;
        for (int i = 1; i <= n; ++i) {
            b[a[i]]++;
            if (b[a[i]] == 2) {
                ok = 0;
            }
        }
        if (ok) {
            int pre = 0;
            for (int k = n; k >= 1; --k) {
                if (a[k] > pre) {
                    pre = a[k];
                } else if (a[k] + 1 == pre) {
                    pre = a[k];
                } else {
                    ok = 0;
                    break;
                }

            }


        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }


    }


    return 0;
}





