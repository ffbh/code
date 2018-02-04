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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int n, m;
vector<int> vi[100010];
int deg[100010];
int E[100010];



void input(){
	in >> n >> m;
	for (int i = 0; i < n; ++i)
		in >> E[i];
	for (int i = 1; i <= m; ++i){
		int a, b;
		in >> a >> b;
		vi[b].push_back(a);
		deg[a]++;
	}

}


queue<int> Q[2];

int cale(){
	int ans = 0;


	
	while (!Q[0].empty() || !Q[1].empty()){
		
		while (!Q[0].empty()){
			int u = Q[0].front();
			Q[0].pop();
			for (int e : vi[u]){
				deg[e]--;
				if (deg[e] == 0){
					Q[E[e]].push(e);
				}
			}
		}
		if (!Q[1].empty()){
			ans++;
		}
		while (!Q[1].empty()){
			int u = Q[1].front();
			Q[1].pop();
			for (int e : vi[u]){
				deg[e]--;
				if (deg[e] == 0){
					Q[E[e]].push(e);
				}
			}
		}

	}
	return ans;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < n; ++i){
			if (deg[i] == 0){
				Q[E[i]].push(i);
			}
		}
		int ans =  cale();
	
	
		cout << ans << endl;
	}


	return 0;
}


	






