#pragma comment(linker, "/STACK:809600000,809600000")
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
#include <stack>

using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("/home/fbh/CLionProjects/acm/InOutput/input.txt");
ofstream ou("/home/fbh/CLionProjects/acm/InOutput/input2.txt");
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

char str[500010];
int n;
void input(){
	in>>str;
  //  scanf("%s",str);
}

bool ok(vector<pii>& p){
    for(pii& K : p){
        if(K.first == 0)
            return 0;
    }
    return 1;
}



bool f[500010],mark[500010];
int oop[500010][2];
vector<pii> all[500010];
bool CLEAR[500010];
pii k[250010];
int tmp[500010];
pii ret[250010];

void clearall(int t){
    f[t]=0;
    mark[t]=0;
    oop[t][0]=oop[t][1]=0;
    all[t].clear();
    CLEAR[t]=0;
    k[t]= mp(0,0);
    tmp[t]=0;
    ret[t]=mp(0,0);
}
pii cale(int deep) {

    clearall(deep);
    f[deep] = 0;
    oop[deep][0] = 0;
    oop[deep][1] = 3;

    all[deep].clear();
    all[deep].resize(0);
    for (int i = 0; i <= n; ++i) {

        CLEAR[deep] = 0;
        k[deep].second = 1;
        mark[deep] = 0;
        if (str[i] == '!') {
            f[deep] = 1 - f[deep];
        } else if (str[i] == 'T') {
            k[deep].first = 1 ^ f[deep];
            f[deep] = 0;
            mark[deep] = 1;
        } else if (str[i] == 'F') {
            k[deep].first = 0 ^ f[deep];
            f[deep] = 0;
            mark[deep] = 1;
        } else if (str[i] == '(') {
            deep++;
            clearall(deep);
            f[deep] = 0;
            all[deep].clear();
            all[deep].resize(0);
            oop[deep][0] = 0;
            oop[deep][1] = 3;
            mark[deep] = 0;
        }else if(str[i] ==')') {
            if (ok(all[deep])) {
                oop[deep][1] = 0;
                tmp[deep] = 3;
                for (pii &p : all[deep]) {
                    tmp[deep] = min(tmp[deep], p.second);
                }
                oop[deep][0] += tmp[deep];
            } else {
                tmp[deep] = 0;
                for (pii &p : all[deep]) {
                    if (p.first == 0) {
                        tmp[deep] += p.second;
                    }
                }
                oop[deep][1] = min(oop[deep][1], tmp[deep]);
            }
            all[deep].clear();
            ret[deep] = mp(0, 0);
            if (oop[deep][0] == 0) {
                ret[deep].first = 0;
                ret[deep].second = oop[deep][1];
            } else {
                ret[deep].first = 1;
                ret[deep].second = oop[deep][0];

            }
            deep--;
            k[deep] = ret[deep+1];
            k[deep].first ^= f[deep];
            k[deep].second = 1;
            f[deep] = 0;
            mark[deep]=1;
        }
        else if (str[i] == '&') {


        } else {

            CLEAR[deep] = 1;
        }
        if (mark[deep]) {
            all[deep].push_back(k[deep]);
        }

        if (CLEAR[deep]) {
            if (ok(all[deep])) {
                oop[deep][1] = 0;
                tmp[deep] = 3;
                for (pii &p : all[deep]) {
                    tmp[deep] = min(tmp[deep], p.second);
                }
                oop[deep][0] += tmp[deep];
            } else {
                tmp[deep] = 0;
                for (pii &p : all[deep]) {
                    if (p.first == 0) {
                        tmp[deep] += p.second;
                    }
                }
                oop[deep][1] = min(oop[deep][1], tmp[deep]);
            }
            all[deep].clear();
        }

    }
    if (ok(all[deep])) {
        oop[deep][1] = 0;
        tmp[deep] = 3;
        for (pii &p : all[deep]) {
            tmp[deep] = min(tmp[deep], p.second);
        }
        oop[deep][0] += tmp[deep];
    } else {
        tmp[deep] = 0;
        for (pii &p : all[deep]) {
            if (p.first == 0) {
                tmp[deep] += p.second;
            }
        }
        oop[deep][1] = min(oop[deep][1], tmp[deep]);
    }
    all[deep].clear();
 //   cout<<oop[deep][0]<<" "<<oop[deep][1]<<endl;
    ret[deep] = mp(0, 0);
    if (oop[deep][0] == 0) {
        ret[deep].first = 0;
        ret[deep].second = oop[deep][1];
    } else {
        ret[deep].first = 1;
        ret[deep].second = oop[deep][0];

    }

    return ret[deep];

}

void ppp(int K){
    K = min(K,2);
    printf("%d\n",K);
}



int main(){

//    get_input(5);
//    return 0;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		n = strlen(str);
		n--;



        pii ans = cale(0);
        if(ans.first == 1){
            ppp(0);
        }
        else{
            ppp(ans.second);
        }










	}


	return 0;
}





