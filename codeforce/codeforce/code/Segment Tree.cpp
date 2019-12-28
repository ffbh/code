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
pii data[500010];
map<int, int> M;
set<int> join;

void input() {
    in >> n;
    for (int i = 0; i < n; ++i) {
        in >> data[i].first >> data[i].second;
    }
}

void _init() {
    M.clear();
    join.clear();

}

bool work() {

    for (int i = 0; i < n; ++i) {
        int l = data[i].first;
        int r = data[i].second;
        while (!M.empty()) {
            if (M.begin()->first < l) {
                if (M.begin()->first == M.begin()->second) {
                    return 0;
                }
                M.erase(M.begin());
            } else {
                break;
            }
        }
        int right = r;
        for (auto &m : M) {
            if (m.first > l && m.first < r) {
                if (m.first != m.second) {
                    if (m.second < r)
                        return 0;
                    right = m.second;
                    m.second = r;
                } else {
                    m.second = r;
                }
            } else {
                break;
            }
        }
        M[r] = right;
    }
    int cnt = 0;
    for (auto &m : M) {
        if (m.first == m.second)
            cnt++;
    }
    return cnt <= 1;
}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        sort(data, data + n);
        if (work()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}





