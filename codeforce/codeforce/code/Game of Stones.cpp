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




void input(){



}



unordered_map<LL,int> M[70];

int dfs(int p,LL key){

    for(int i=p+1;i<=62;++i){
        if(key & ((LL)1<<i)){
            key -= ((LL)1<<i);
        }
    }
	if(M[p].count(key)){
		return M[p][key];
	}

    vector<int> ans;
    for(int i=1;i<=p;++i){
        if(((LL)1<<i)&key)
            continue;
        ans.push_back(dfs(p-i,key|((LL)1<<i)));
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    int ret = ans.size();
    for(int i=0;i<ans.size();++i){
        if(ans[i] != i){
            ret = i;
            break;
        }
    }

    return M[p][key] = ret;
}

int pk[]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main(){
	int TEST_CASE = 1;
	//in >> TEST_CASE;
//    for(int i=0;i<=60;++i){
//        cout<<dfs(i,0)<<",";
//    }
	while (TEST_CASE-- > 0){
	//	input();
        int n,sg;
        in>>n;
        sg=0;
        for(int i=1;i<=n;++i){
            int t;
            in>>t;
            sg ^= pk[t];
        }
        if(sg == 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }













	}


	return 0;
}





