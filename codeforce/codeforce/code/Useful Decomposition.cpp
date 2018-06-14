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




int n;
vector<int> vi[100010];

void input(){
    in>>n;
    for(int i=1;i<n;++i){
        int a,b;
        in>>a>>b;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
}
vector<int> leaf;
void dfs(int p,int f){
    bool end = 1;
    for(int son : vi[p]){
        if(son == f)
            continue;
        end = 0;
        dfs(son,p);
    }
    if(end){
        leaf.push_back(p);
    }
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int root = -1;
		int maybe = -1;
		for(int i=1;i<=n;++i){
		    if(vi[i].size()>=3){
		        if(root != -1){
		            cout<<"No"<<endl;
		            return 0;
		        }
                else{
		            root = i;
		        }
		    }
		    else if(vi[i].size() == 1){
		        maybe = i;
		    }
		}

        cout<<"Yes"<<endl;
        if(root == -1){
            root = maybe;
        }

        dfs(root,-1);
        cout<<leaf.size()<<endl;
        for(int s : leaf){
            cout<<root<<" "<<s<<endl;
        }



	}


	return 0;
}





