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
ifstream in("C:\\input.txt");
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

vector<int> vi[1010];
vector<int> w;


int dp[1010];


class StonesOnATree{
public :


	int cale(int p){
		int sum = 0;
		for (int son : vi[p]){
			sum += w[son];
		}
		return sum;
	}

	int dfs(int p,int add){
		if (dp[p] != -1){
			return dp[p] + add;
		}
		int &ref = dp[p];
		ref = 0;
		if (vi[p].size() == 0){
			ref = w[p];
			return ref + add;
		}
		else if (vi[p].size() == 1){
			int pp = dfs(vi[p][0],0);
			ref = max(pp, w[p] + w[vi[p][0]]);
			return ref + add;
		}
		else{
			
			int tlf = dfs(vi[p][0], 0);
			int trt = dfs(vi[p][1], 0);

			int lf = dfs(vi[p][0], w[vi[p][1]]);
			int rt = dfs(vi[p][1], w[vi[p][0]]);
	//		int llf = cale(vi[p][0]);
	//		int rrt = cale(vi[p][1]);
			int a = w[p] + w[vi[p][0]] + w[vi[p][1]];
	//		int b = w[vi[p][0]] + w[vi[p][1]] + min(llf, rrt);
			int t = min(max(tlf, rt), max(trt, lf));
			ref = max(a, t);
		}
		return dp[p] + add;
	}

	int minStones(vector <int> p, vector <int> _w){
		for (int i = 0; i < p.size(); ++i){
			vi[p[i]].push_back(i + 1);
		}
		w = _w;
		memset(dp, -1, sizeof(dp));
		return dfs(0, 0);






	}




};



int main(){
	StonesOnATree ss;
	vector<int> a({ 0, 0, 1, 1, 2, 2 });
	vector<int> b({ 2, 1, 1, 1, 1, 1, 1 });
	cout << ss.minStones(a, b) << endl;





}