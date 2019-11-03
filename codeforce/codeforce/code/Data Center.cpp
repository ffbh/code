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

void input() {
    in >> n;

}

void _init() {


}


int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        int ans = n * 4;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                int m = n / i;
                ans = min(ans, m + m + i + i);
            }

        }
        cout << ans << endl;
    }


    return 0;
}





