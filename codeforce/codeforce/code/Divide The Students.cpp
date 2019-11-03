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

int a, b, c;
int A[3];

void input() {
    in >> a >> b >> c;

}

void _init() {


}


int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        if (a < c) {
            swap(a, c);
        }
        memset(A, 0, sizeof(A));
        int ans;
        if (c != 0) {
            A[0] = c;
            A[1] = a / 2;
            A[2] = a / 2 + a % 2;
            while (b > 0) {
                sort(A, A + 3);
                A[0]++;
                b--;
            }
            sort(A, A + 3);
            ans = A[2];
        } else {
            ans = (a + b) / 3 + ((a + b) % 3 != 0 ? 1 : 0);
        }
        cout << ans << endl;

    }


    return 0;
}





