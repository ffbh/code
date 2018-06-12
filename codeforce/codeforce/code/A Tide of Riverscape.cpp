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


int n,p;
string s;


void input(){
    in>>n>>p;
    in>>s;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        bool ok = 0;

        for(int i=0;i<min(n,p);++i){
            vector<pii> V;
            bool ne = 0;
            bool mark[2] = {0,0};
            for(int j=i;j<n;j+=p){
                if(s[j] == '.'){
                    V.push_back(mp(j,-1));
                    ne = 1;
                }
                else{
                    mark[s[j]-'0']++;
                    V.push_back(mp(j,s[j]-'0'));
                }
            }
            if(V.size() == 1){
                if(V[0].second == -1){
                    s[V[0].first] = '1';
                }
            }
            else{
                if(ne){
                    ok = 1;
                    char kkk = '0';
                    if(mark[0]){
                        kkk = '1';
                    }

                    for(auto v : V){
                        if(v.second == -1){
                            s[v.first] = kkk;
                            kkk = (1 - (kkk - '0')) +'0';
                        }
                    }
                }
                else{
                    if(!mark[0] || !mark[1]){

                    }
                    else{
                        ok = 1;
                    }
                }

            }
        }


        if(ok){
            cout<<s<<endl;
        }
        else{
            cout<<"No"<<endl;
        }















	}


	return 0;
}





