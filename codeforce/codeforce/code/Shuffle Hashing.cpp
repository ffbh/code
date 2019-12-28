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
string A, B;
int num[30];

void input() {
    in >> A >> B;

}

void _init() {
    memset(num, 0, sizeof(num));

}

bool ok() {
    for (int i = 0; i < 30; ++i)
        if (num[i] != 0)
            return 0;
    return 1;
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        if (A.length() > B.length()) {
            cout << "NO" << endl;
            continue;
        }
        int len = A.length();
        for (char c : A) {
            num[c - 'a']++;
        }
        for (int i = 0; i < len; ++i) {
            num[B[i] - 'a']--;
        }

        int p = len;
        bool yes = ok();
        while (p < B.length()) {
            num[B[p] - 'a']--;
            num[B[p - len] - 'a']++;
            if (ok())
                yes = 1;
            p++;
        }
        if (yes) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;

    }


    return 0;
}





