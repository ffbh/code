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



//int A[1010], B[1010];
//int M[1010];
// wrong
//void fun(int a, int b, int num) {
//    set<int> S;
//    for (int i = b; i <= num; ++i) {
//        S.clear();
//        for (int lf = 0; lf <= i - b; ++lf) {
//            int rg = i - lf - b;
//            S.insert(A[lf] ^ A[rg]);
//        }
//        for (int k = 0;; ++k) {
//            if (!S.count(k)) {
//                B[i] = k;
//                break;
//            }
//        }
//
//        if (i < a)
//            continue;
//        S.clear();
//        int max_R = 0;
//        memset(M, -1, sizeof(M));
//        for (int lf = 0; lf <= i - a; ++lf) {
//            int rg = i - lf - a;
//            if (lf > rg)
//                continue;
//            if (!S.count(B[lf] ^ B[rg])) {
//                S.insert(B[lf] ^ B[rg]);
//                max_R = lf;
//                M[i] = B[lf] ^ B[rg];
//            }
//
////            cout << i << " " << (B[lf] ^ B[rg]) << " index:" << lf << endl;
//        }
//
//        for (int k = 0;; ++k) {
//            if (!S.count(k)) {
//                A[i] = k;
//                break;
//            }
//        }
//        set<int> test;
//        for (int k = 0; k <= max_R; ++k) {
//            if (M[i] >= 0 && M[i] < A[i]) {
//                test.insert(M[i]);
//            }
//            if (test.size() == A[i]) {
//                max_R = k;
//                break;
//            }
//        }
//        cout << "final " << i << "  -> " << max_R << endl;
//
//    }
//    for (int i = 0; i <= num; ++i) {
//        if (A[i] > 1)
//            A[i] = 1;
//    }
//}

int a, b;
string s;

void input() {
    in >> a >> b;
    in >> s;

}

void _init() {


}


bool ok(vector<int> V) {
    if (V.empty()) {
        return 0;
    }
    sort(V.begin(), V.end());
    int limit = 2 * b - 1;
    if (V.back() > a + 2 * limit)
        return 0;
    if (V.size() >= 2 && V[V.size() - 2] >= 2 * b) {
        return 0;
    }
    if (V[0] < a) {
        return 0;
    }
    int special = V.back();
    int time = V.size() - 1;

    if (special >= 3 * a) {
        int rest = special - a - (b - 1);
        if (rest < 2 * b) {
            return 1;
        } else {
            return time % 2 == 0;
        }
    } else if (special >= 2 * a) {
        if (special - a - 2 * (b - 1) <= 0) {
            return 1;
        } else {
            if (special - a - (b - 1) < 2 * b) {
                return time % 2 == 1;
            } else {
                return 0;
            }
        }
    } else {
        if (special - a - (b - 1) < b) {
            return time % 2 == 0;
        }
        else{
            return 0;
        }
    }

//    bool t1 = special >= 2 * a;//a can
//    bool t2 = special - a - 2 * (b - 1) <= 0;//b can not
//
//    if (t1 && t2) {
//        return 1;
//    } else if (!t1 && t2) {
//        return time % 2 == 0;
//    } else if (t1 & !t2) {
//        return time % 2 == 1;
//    } else {
//        return 0;
//    }
}

int main() {


//    a = 7;
//    b = 6;
//    cout << ok({}) << endl;

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        int len = 0;
        vector<int> V;
        for (char c : s) {
            if (c == 'X') {
                if (len >= b) {
                    V.push_back(len);
                }
                len = 0;
            } else {
                len++;
            }
        }
        if (len >= b) {
            V.push_back(len);
        }
        len = 0;
        if (ok(V)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}





