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
ifstream in("/home/zhoujiazhi/CLionProjects/bbbb/InOutput/input.txt");
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


int vis[10010][266];

int N;
int op[10010][3];
int T;
void input(){
    in>>N;
    for(int i=1;i<=N;++i){
        string str;
        in>>str;
        if(str=="add"){
            op[i][0] = 0;
            in>>op[i][1];
        }
        else if(str == "beq"){
            op[i][0] = 1;
            in>>op[i][1]>>op[i][2];
        }
        else if(str == "bne"){
            op[i][0] = 2;
            in>>op[i][1]>>op[i][2];
        }
        else if(str  == "blt"){
            op[i][0] = 3;
            in>>op[i][1]>>op[i][2];
        }
        else{
            op[i][0] = 4;
            in>>op[i][1]>>op[i][2];
        }
    }
}

bool go(){
    int pos = 1,val = 0;
    while(pos <= N){
        if(vis[pos][val] == T){
            return 0;
        }
        vis[pos][val] = T;
        if(op[pos][0] == 0){
            val = (val + op[pos][1])%256;
            pos++;
        }
        else if(op[pos][0] == 1){
            if(op[pos][1] == val){
                pos = op[pos][2];
            }
            else{
                pos++;
            }
        }
        else if(op[pos][0] == 2){
            if(op[pos][1] != val){
                pos = op[pos][2];
            }
            else{
                pos++;
            }
        }
        else if(op[pos][0] == 3){
            if(op[pos][1] > val){
                pos = op[pos][2];
            }
            else{
                pos++;
            }
        }
        else{
            if(op[pos][1] < val){
                pos = op[pos][2];
            }
            else{
                pos++;
            }
        }

    }
    return 1;
}

int main(){

    for(int i=0;i<10010;++i)
        for(int j=0;j<266;++j){
            vis[i][j] = 1e9;
        }

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
        T = TEST_CASE + 1;

        if(go()){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }






	}


	return 0;
}




