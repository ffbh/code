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

int n,m;
vector<bool> vi[100010];
vector<int> ans[100010];
int sx,sy,ex,ey;
void Init(){
	for(int i=0;i<n;++i) {
		vi[i].clear();
		ans[i].clear();
	}
}

void input(){
	in>>n>>m;
	Init();

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int t;
			in>>t;
			vi[i].push_back(t);
			ans[i].push_back(-1);
		}
	}

	in>>sx>>sy>>ex>>ey;

}
int dirs[4][2]={1,0,0,1,-1,0,0,-1};

bool IN(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}

int bfs(){
	queue<pii> Q;
	sx--;
	sy--;
	ex--;
	ey--;
	ans[sx][sy]=0;
	Q.push(mp(sx,sy));
	while(!Q.empty()){
		pii u = Q.front(),v;
		Q.pop();
	//	cout<<u.first<<" "<<u.second<<endl;
		if(u.first==ex && u.second == ey){
			return ans[u.first][u.second];
		}
		int S = (vi[u.first][u.second] + ans[u.first][u.second])%2;
		for(int i=S;i<4;i+=2){
			v.first = u.first + dirs[i][0];
			v.second = u.second + dirs[i][1];
			if(IN(v.first,v.second) && ans[v.first][v.second] == -1){
				ans[v.first][v.second] = ans[u.first][u.second] + 1;
				Q.push(v);
			}
		}
	}
	return -1;
}

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		printf("%d\n",bfs());


	}


	return 0;
}





