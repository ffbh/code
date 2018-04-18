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


struct Node{
	int next[30];
}data[200010];
int size,root;

int MALLOC(){
	memset(data[size].next,-1,sizeof(data[size].next));
	return size++;
}


void insert(string s){
	int p = root;
	for(char c : s){
		int nn = c-'a';
		if(data[p].next[nn] == -1){
			data[p].next[nn] = MALLOC();
		}
		p = data[p].next[nn];
	}
}


int n,k;
void input(){
    in>>n>>k;
    string s;
    for(int i=0;i<n;++i){
        in>>s;
        insert(s);
    }
}

bool dp[200010][2];//0 fail  1 win
void dfs(int p,int deep){
    bool ok = 0;
    for(int i=0;i<30;++i){
        if(data[p].next[i] != -1){
            ok = 1;
            int d = data[p].next[i];
            dfs(d,deep+1);
            bool a = dp[d][0];
            bool b = dp[d][1];
            if(a&&b){
               // assert(0);
            }
            else if(a&&!b){

                dp[p][1] = 1;
            }
            else if(!a&&b){
                dp[p][0] = 1;
            }
            else{
              //  assert(0);
                dp[p][0]=dp[p][1]=1;
            }

        }
    }
    if(!ok){
        dp[p][0] = 1;
    }
    else if(!dp[p][0] && !dp[p][1]) {

    }
}

bool win(int p){

}




int main(){
	size = 0;
	root = MALLOC();
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        dfs(0,0);
        if(dp[0][0] && dp[0][1]){
            cout<<"First"<<endl;
        }
        else if(!dp[0][0] && dp[0][1]){
            if(k % 2 == 1 )
                cout<<"First"<<endl;
            else{
                cout<<"Second"<<endl;
            }

        }
        else if(dp[0][0] && !dp[0][1]){
            cout<<"Second"<<endl;
        }
        else{
          //  assert(0);
            cout<<"Second"<<endl;
        }












	}


	return 0;
}





