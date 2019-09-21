//
// Created by Jiazhi Zhou on 2019/9/14.
//
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
int a[110];


void input() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> a[i];


}

void _init() {


}


int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        set<int> S;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 2048)
                continue;
            int aim = a[i];
            while (aim < 2048) {
                if (S.count(aim)) {
                    S.erase(aim);
                    aim *= 2;
                } else {
                    break;
                }
            }
            S.insert(aim);
            if (aim == 2048)
                break;
        }
        if (S.count(2048)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}





