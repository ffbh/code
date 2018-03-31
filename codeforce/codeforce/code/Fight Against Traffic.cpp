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


int n,m,s,t;
bool edge[1010][1010];
int d1[1010],d2[1010];

void input(){
	in>>n>>m>>s>>t;
	for(int i=1;i<=m;++i){
		int u,v;
		in>>u>>v;
		edge[u][v]=edge[v][u]=1;
	}

}

void bfs(int S,int* D){
	queue<int> Q;
	for(int i=1;i<1010;++i)
		D[i] = -1;

	Q.push(S);
	D[S] = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int v=1;v<=n;++v){
			if(edge[u][v] && D[v] == -1){
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}
	}
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int all = n * (n-1) / 2 - m;

		bfs(s,d1);
		bfs(t,d2);
		int len = d1[t];
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				if(!edge[i][j]){
					if(d1[i] + d2[j] + 1 < len || d1[j] + d2[i] + 1 < len ){
						all--;
					}
				}
			}




		cout<<all<<endl;










	}


	return 0;
}





