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
#include <random>

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

LL n, k;
LL a[200010];
LL b[200010];

void input() {
    in >> n >> k;
    for (int i = 1; i <= n; ++i)
        in >> a[i];
    for (int i = 1; i <= n; ++i)
        in >> b[i];
    a[n + 1] = b[n + 1] = 0;
}

void _init() {


}

int A, B, tail;
LL sumA, sumB;

void go() {
    while (A <= n && sumA < k) {
        A++;
        sumA += a[A];
    }
    while (B <= n && sumB < k) {
        B++;
        sumB += b[B];
    }
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();

        A = B = tail = 0;
        sumA = sumB = 0;
        vector<int> cuts;
        bool win = false;
        LL ca, cb;
        ca = cb = 0;
        LL last = 0;
        int final = 0;
        while (true) {
            go();

            if (A > B) {
                if (tail)
                    cuts.push_back(tail);
                win = true;
                break;
            } else if (A == B) {
                if (A == n + 1) {
                    break;
                }
            }
            if (B == n + 1) {
                break;
            }

            if (tail == final) {
                if (tail)
                    cuts.push_back(tail);
                final = A - 1;
            }
            tail++;
            if(tail > final){
                break;
            }
            ca += a[tail];
            cb += b[tail];
            LL now_min = min(ca, cb);
            sumA -= (now_min - last);
            sumB -= (now_min - last);
            last = now_min;
        }
        if (win) {
            printf("%d\n", (int) cuts.size());
            for (int c : cuts) {
                printf("%d ", c);
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }

    }


    return 0;
}





