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
#include <deque>
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
 
 
 
int n,k;
string s;
int _0_l,_0_r,_1_l,_1_r;
 
void input(){
    in>>n>>k;
    in>>s;
 
 
}
 
 
void _init(){
 
 
 
}
 
deque<int> L[2],R[2];
 
int get_first(int now ,int aim,int pos){
    if(!L[aim].empty()){
        return L[aim][0];
    }
    else if(aim == now){
        return pos;
    }
    else {
        assert(R[aim].size());
        return R[aim][0];
    }
}
 
int get_last(int now,int aim,int pos){//and_pos = pos + k - 1
    if(!R[aim].empty()){
        return R[aim].back();
    }
    else if(aim == now){
        return pos + k - 1;
    }
    else{
        assert(L[aim].size());
        return L[aim].back();
    }
}
 
deque<int> Q;
bool cale(int now){
    L[0].clear();
    R[0].clear();
    L[1].clear();
    R[1].clear();
    Q.push_back(1);
    for(int i=k+1;i<=n;++i){
        int k = s[i]-'0';
        R[s[i]-'0'].push_back(i);
    }
    for(int pos = 1 ;pos + k -1 <= n;++pos){
        int l0 = get_first(now,0,pos);
        int r0 = get_last(now,1,pos);
        int l1 = get_first(now,1,pos);
        int r1 = get_last(now,0,pos);
        if(r0-l0+1<=k || r1-l1+1<=k){
            //fail
        }
        else{
            return true;
        }
 
        L[s[pos]-'0'].push_back(pos);
 
        if(R[0].empty()){
            R[1].pop_front();
        }
        else if(R[1].empty()){
            R[0].pop_front();
        }
        else if(R[0][0] < R[1][0]){
            R[0].pop_front();
        }
        else{
            R[1].pop_front();
        }
    }
    return false;
}
 
 
int main(){
 
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		 _init();
		input();
        s = '-' + s;
        _0_l = _1_l = 1e9;
        _0_r = _1_r = -1;
        for(int i=1;i<=n;++i){
            if(s[i] == '0'){
                _0_l = min(_0_l,i);
                _0_r = i;
            }
            else{
                _1_l = min(_1_l,i);
                _1_r = i;
            }
        }
 
//        cale(0);
//        cale(0);
        if(_0_r == -1 || _1_r == -1 || _0_r - _0_l + 1 <= k || _1_r - _1_l + 1 <= k){
            cout<<"tokitsukaze"<<endl;
        }
        else if(!cale(0) && !cale(1)){
            cout<<"quailty"<<endl;
        }
        else{
            cout<<"once again"<<endl;
        }
 
 
 
 
 
 
 
 
 
 
 
 
 
	}
 
 
	return 0;
}
 
