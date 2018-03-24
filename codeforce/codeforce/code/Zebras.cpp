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
ifstream in("/home/fbh/CLionProjects/codeforce/input.txt");
//istream& in = cin;
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL, LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)

string str;

void input() {
    in>>str;

}

stack<int> zero,one;
bool S[200010];
int nn[200010];
int num;
bool slove(){
    for(int i=0;i<str.length();++i){
        if(str[i]=='0'){
            if(!one.empty()){
                nn[one.top()] = i;
                one.pop();
            }
            else{
                S[i]=1;
                num++;
            }
            zero.push(i);
        }
        else{
            if(zero.empty())
                return 0;
            nn[zero.top()]=i;
            zero.pop();
            one.push(i);
        }


    }
    return one.empty();
}
vector<int> all;
void dfs(int k){
    all.push_back(k);
    if(nn[k] != -1)
        dfs(nn[k]);
}

int main() {

    int TEST_CASE = 1;
    //in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        input();

        memset(nn,-1,sizeof(nn));
        num=0;
        if(slove()){
            printf("%d\n",num);
            for(int i=0;i<str.length();++i){
                if(S[i]){
                    all.clear();
                    dfs(i);
                    printf("%d ",all.size());
                    for(int p : all){
                        printf("%d ",p+1);
                    }
                    printf("\n");
                }
            }
        }
        else{
            cout<<-1<<endl;
        }







    }


    return 0;
}




