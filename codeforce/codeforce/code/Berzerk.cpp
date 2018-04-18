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

int n;
vector<int> A[2];


void input(){
    in>>n;
    int k1,k2;
    in>>k1;
    for(int i=1;i<=k1;++i){
        int t;
        in>>t;
        A[0].push_back(t);
    }

    in>>k2;
    for(int i=1;i<=k2;++i){
        int t;
        in>>t;
        A[1].push_back(t);
    }


}

int mark[7010][2];//-1 fail  0  tie   1  win
bool vis[7010][2];
//vector<int> edge[7010][2];
int dep[7010][2];
int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

        for(int i=1;i<n;++i){
            dep[i][0] = A[0].size();
            dep[i][1] = A[1].size();
//            for(int k : A[0]){
//           //     edge[(i+k)%n][1].push_back(i);
//                dep[i][0]++;
//            }
//            for(int k : A[1]){
//         //       edge[(i+k)%n][0].push_back(i);
//                dep[i][1]++;
//            }
        }

        queue<pii> Q;
        Q.push(mp(0,0));
        Q.push(mp(0,1));
        mark[0][0]=mark[0][1]=-1;
        vis[0][0]=vis[0][1]=1;
        while(!Q.empty()){
            pii u = Q.front();
            Q.pop();
            int f = mark[u.first][u.second];
            for(int v : A[1-u.second]){
                v = (u.first - v + n)%n;
                int v2 = 1-u.second;
                if(vis[v][v2]){
                    continue;
                }
                if(f == -1){
                    mark[v][v2]=1;
                    vis[v][v2]=1;
                    Q.push(mp(v,v2));
                }
                else{
                    dep[v][v2]--;
                    if(dep[v][v2] == 0){
                        mark[v][v2]=-1;
                        vis[v][v2]=1;
                        Q.push(mp(v,v2));
                    }
                }
            }
        }

        for(int k=0;k<=1;++k) {
            for (int i = 1; i < n; ++i) {
                if(mark[i][k] == -1){
                    printf("Lose ");
                }
                else if(mark[i][k] == 0){
                    printf("Loop ");
                }
                else{
                    printf("Win ");
                }
            }
            cout<<endl;
        }






	}


	return 0;
}





