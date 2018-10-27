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
string str[1010];
bool mark[1010][1010];
int dirs[8][2]={1,0,0,1,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};



bool IN(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}



void input(){
	in>>n>>m;
	for(int i=0;i<n;++i){
		in>>str[i];
	}
}

bool judge(int i,int j){
    for(int k=0;k<8;++k){
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        if(IN(x,y)){
            if(str[x][y] != '#')
                return false;
        }
        else{
            return false;
        }
    }
    return true;
}


void fill(int i,int j){
    for(int k=0;k<8;++k){
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        assert(IN(x,y));
        mark[x][y]=1;
    }
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(str[i][j]=='#'){
					for(int k=0;k<8;++k){
					    int x = i + dirs[k][0];
					    int y = j + dirs[k][1];
					    if(IN(x,y) && judge(x,y)){
                            fill(x,y);
					    }
					}
				}
		}

		bool ans = true;
		for(int i=0;i<n;++i)
		    for(int j=0;j<m;++j){
		    if(!mark[i][j] && str[i][j] == '#' || mark[i][j] && str[i][j] !='#'){
		        ans = false;
		    }
		}

        if(ans){
		    cout<<"YES"<<endl;
		}
		else{
		    cout<<"NO"<<endl;
		}











	}


	return 0;
}





