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
ifstream in("/home/fbh/CLionProjects/acm/InOutput/input.txt");
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

int SG[60][60];

void Init(){
	for(int i=1;i<60;++i)
		for(int j=1;j<60;++j){
			if(i==j&&i==1){
				continue;
			}
            set<int> si;
            if(i>1&&j>1) {
                for (int x = 1; x < i; ++x) {
                    for (int y = 1; y < j; ++y) {
                        si.insert(SG[x][j] ^ SG[i][y]);
                    }
                }
            }
            else{
                for (int x = 0; x < i; ++x) {
                    for (int y = 0; y < j; ++y) {
                        si.insert(SG[x][j] ^ SG[i][y]);
                    }
                }


            }
            for(int k=0;;++k){
                if(!si.count(k)){
                    SG[i][j] = k;
                    break;
                }
            }
		}
}

int n,m;
string s[60];

void input(){

    for(int i=0;i<n;++i)
        in>>s[i];

}


int main(){
	Init();
    while(in>>n>>m) {
        if(n==0&&m==0)
            break;
        input();
        int sg = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '#') {
                    sg ^= SG[i + 1][j + 1];
                }
            }
        }
        if (sg) {
            cout << "John" << endl;
        } else {
            cout << "Jack" << endl;

        }
    }












	return 0;
}





