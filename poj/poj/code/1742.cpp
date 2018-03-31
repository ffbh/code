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

bool vis[100010];
int num[100010];
int n,m;
int A[110],C[110];
void Init(){
	memset(vis,0,sizeof(vis));
}


int main(){
	while(in>>n>>m){
		if(n+m==0)
			break;
		Init();
		vis[0]=1;
		for(int i=1;i<=n;++i)
			in>>A[i];
		for(int i=1;i<=n;++i)
			in>>C[i];

		for(int k = 1;k<=n;++k){
			memset(num,0,sizeof(num));
			for(int i=A[k];i<=m;++i){
				if(vis[i-A[k]]){
					num[i]=1;
				}
				else if(num[i-A[k]]>0&&num[i-A[k]] < C[k]) {
					num[i] = num[i - A[k]] + 1;
				}
			}
			for(int i=1;i<=m;++i)
				if(num[i])
					vis[i]=1;


			int t=0;
			t++;
		}

		int ans=0;
		for(int i=1;i<=m;++i)
			if(vis[i])
				ans++;
		printf("%d\n",ans);




	}






	return 0;
}





