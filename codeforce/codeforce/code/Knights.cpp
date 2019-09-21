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
int mark[110][110];
int dirs[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

bool IN(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void input() {
    in >> n;

}

void _init() {


}

void dfs(int x, int y) {
    for (int k = 0; k < 8; ++k) {
        int nx = x + dirs[k][0];
        int ny = y + dirs[k][1];
        if (IN(nx, ny) && mark[nx][ny] == 0) {
            mark[nx][ny] = 3 - mark[x][y];
            dfs(nx, ny);
        }
    }
}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (mark[i][j] != 0)
                    continue;
                mark[i][j] = 1;
                dfs(i, j);
            }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mark[i][j] == 1) {
                    cout << "W";
                } else {
                    cout << "B";
                }
            }
            cout << endl;
        }
    }


    return 0;
}





