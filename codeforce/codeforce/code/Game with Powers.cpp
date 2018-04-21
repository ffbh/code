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


LL n;

void input(){
	in>>n;


}

unordered_map<int,int> mmp;

int get(int p,int pos){
	pos++;
	vector<int> bin;
	bin.push_back(0);
	while(p){
		bin.push_back(p%2);
		p/=2;
	}
	for(int i=pos;i<bin.size();i+=pos){
		bin[i] = 0;
	}
	int ans=0;
	for(int i=(int)bin.size()-1;i>=1;--i){
		ans = ans * 2 + bin[i];
	}
	return ans;

}

int dfs(int p){

	if(mmp.count(p)){
		return mmp[p];
	}
	vector<int> ans;

	for(int i=0;i<31;++i){
		if((1<<i) & p){
			int son = get(p,i);
			ans.push_back(dfs(son));
		}
	}

	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	int ret = (int)ans.size();
	if(p==255){
		int t=0;
	}
	for(int i=0;i<ans.size();++i) {
		if (ans[i] != i) {
			ret = i;
			break;
		}
	}
	return mmp[p] = ret;


}

map<int,int> M;
bool vis[100010];


int pk[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};

int main(){
//	mmp[0] = 0;
//	for(int i=1;i<2e9;i=i*2+1){
//		cout<<dfs(i)<<",";
//cout<<i<<" "<<dfs(i)<<endl;
//	}

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		mmp.clear();
		mmp[0]=0;
		LL S = sqrt(n);
		LL sg = 1;
		LL rest = n - S;
		for(int i=2;i<=S;++i){
			if(vis[i]){
				continue;
			}
			LL x = i;
			LL num = 0;
			while(x<=n){
				if(x <= S)
					vis[x] = 1;
				else
					rest--;
				num ++;
				x *= i;

			}
	//		cout<<i<<" "<<num<<endl;
//			M[num]++;
			sg ^= pk[num];
//			cout<<sg<<endl;
		}
//		cout<<mmp[3]<<endl;
//		cout<<mmp[15]<<endl;
//		cout<<mmp[255]<<endl;
//		cout<<mmp[8191]<<endl;
		sg ^= (rest % 2);
		if(sg == 0){
			cout<<"Petya"<<endl;
		}
		else{
			cout<<"Vasya"<<endl;
		}











	}


	return 0;
}





