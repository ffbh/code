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
ifstream in("/home/ffbh/CLionProjects/acm/InOutput/input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)


vector<pair<int,char> > P;


void input(){
	P.resize(4);
	for(int i=0;i<4;++i) {
		in >> P[i].first;
		P[i].second = 'A' + i;
	}
}

pii NE(pii now) {
    if(now.second + 2 > 50) {


        return mp(now.first+2,1);
    }
    else{
        return mp(now.first,now.second+ 2);

    }
}

char mmp[60][60];
int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0) {
        input();


        sort(P.begin(), P.end());

        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 50; ++j) {
                mmp[i][j] = '-';
            }
        }


        int need = P[0].first - 1;
        pii now = mp(1, 1);
        for (int i = 1; i <= need; ++i) {
            mmp[now.first][now.second] = P[0].second;
            now = NE(now);
        }


        need = P[1].first - 1;
        now = mp(11, 1);
        for (int i = 1; i <= need; ++i) {
            mmp[now.first][now.second] = P[1].second;
            now = NE(now);
        }


        need = P[2].first - 1;
        now = mp(21, 1);
        for (int i = 1; i <= need; ++i) {
            mmp[now.first][now.second] = P[2].second;
            now = NE(now);
        }

        need = P[3].first - 1;
        now = mp(31, 1);
        for (int i = 1; i <= need; ++i) {
            mmp[now.first][now.second] = P[3].second;
            now = NE(now);
        }


        for (int i = 1; i <= 10; ++i)
            for (int j = 1; j <= 50; ++j) {
                if (mmp[i][j] == '-') {
                    mmp[i][j] = P[2].second;
                }
            }

        for (int i = 11; i <= 20; ++i)
            for (int j = 1; j <= 50; ++j) {
                if (mmp[i][j] == '-') {
                    mmp[i][j] = P[3].second;
                }
            }


        for (int i = 21; i <= 30; ++i)
            for (int j = 1; j <= 50; ++j) {
                if (mmp[i][j] == '-') {
                    mmp[i][j] = P[0].second;
                }
            }


        for (int i = 31; i <= 50; ++i)
            for (int j = 1; j <= 50; ++j) {
                if (mmp[i][j] == '-') {
                    mmp[i][j] = P[1].second;
                }
            }


        cout << 50 << " " << 50 << endl;
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 50; ++j) {
                cout<<mmp[i][j];
            }
            cout<<endl;

        }


    }


	return 0;
}





