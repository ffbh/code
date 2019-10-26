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
vector<string> vs;

void input() {
    in >> n;
    for (int k = 0; k < n; ++k) {
        string s;
        in >> s;
        vs.push_back(s);
    }


}

void _init() {
    vs.clear();

}


void ch(int &v) {
    if (v % 2 == 1) {
        v--;
    }
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        vector<int> vv;
        int a, b;
        a = b = 0;
        for (string s : vs) {
            vv.push_back(s.length());
            for (char c : s) {
                if (c == '0') {
                    a++;
                } else {
                    b++;
                }
            }
        }
        sort(vv.begin(), vv.end());
        int ans = 0;
        for (int v : vv) {
            ch(v);
            int t;
            t = min(a, v);
            ch(t);
            a -= t;
            v -= t;
            t = min(b, v);
            ch(t);
            b -= t;
            v -= t;
            if (v == 0) {
                ans++;
            } else {
                break;
            }
        }
        cout << ans << endl;

    }


    return 0;
}





