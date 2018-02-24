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


int n;
vector<int> v[110];
int idx[110];
void input(){
	in >> n;


}

int all;

void dfs(int pos){
	if (pos == n){
		return;
	}
	if (idx[pos] == v[pos].size()){
		dfs(pos + 1);
	}
	else{
		dfs(v[pos][idx[pos]]);
		idx[pos]++;
		all--;
	}

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < n;++i)
		for (int j = i + 1; j <= n; ++j){
			v[i].push_back(j);
			all++;
		}
		
		int ans = 0;
		while (all > 0){
			ans++;
			dfs(0);


		}
		cout << ans << endl;











	}


	return 0;
}





