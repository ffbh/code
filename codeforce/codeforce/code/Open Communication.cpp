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

int n,m;
vector<pii> A,B;


void input(){
	in>>n>>m;
	A.resize(n);
	B.resize(m);
	for(int i=0;i<n;++i){
		in>>A[i].first>>A[i].second;
	}
	for(int i=0;i<m;++i){
		in>>B[i].first>>B[i].second;
	}

}

int getS(pii a,pii b){
    set<int> s;
    s.insert(a.first);
    s.insert(a.second);
    s.insert(b.first);
    s.insert(b.second);
    return s.size();

}

int getkey(pii a,pii b){
    if(a.first == b.first || a.first == b.second)
        return a.first;
    return a.second;
}

bool M[15][15];

bool ok(vector<int> k){
    for(int kk : k){
        if(kk != 1){
            return 0;
        }
    }
    return 1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        vector<int> aa;
        int ans = -1;

        bool ojbk = 1;
        for(pii a : A){
            set<int> S;
            for(pii b : B){
                int size = getS(a,b);
                assert(size >= 2);
                if(size == 2){

                }
                else if(size == 3){

                    int pk = getkey(a,b);
                    if(ans == -1 || ans == pk){
                        ans = pk;
                    }
                    else{
                        ojbk = 0;
                    }
                    S.insert(pk);
                }
                else{

                }

            }


            if(S.size() > 0){
                aa.push_back(S.size());
            }



        }


        vector<int> bb;
        for(pii b : B){
            set<int> S;
            for(pii a : A){
                int size = getS(a,b);
                assert(size >= 2);
                if(size == 2){

                }
                else if(size == 3){
                    S.insert(getkey(a,b));
                }
                else{

                }
            }

            if(S.size() > 0){
                bb.push_back(S.size());
            }
        }



        if(ojbk){
            cout<<ans<<endl;
        }
        else if(ok(aa)&&ok(bb)){
            cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }







	}


	return 0;
}





