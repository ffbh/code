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


string n;

void input(){
	in >> n;


}

int ans = 0;

void dfs(int pos,int pre,bool ok){
	if (pos == n.length()){
		ans = max(ans, pre);
		return;
	}
	if (ok){
		dfs(pos + 1, pre * 9, ok);
	}
	else{
		dfs(pos + 1, pre * (n[pos] - '0'), 0);
		if (n[pos] != '0'){
			if (pos == 0 && n[pos] == '1'){
				dfs(pos + 1, 1, 1);
			}
			else{
				dfs(pos + 1, pre * (n[pos] - '0' - 1), 1);
			}
		}

	}



}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		dfs(0, 1, 0);
		cout << ans << endl;













	}


	return 0;
}





