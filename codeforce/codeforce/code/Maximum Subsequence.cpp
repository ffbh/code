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


LL n, m;
vector<LL> A, B;

vector<LL> aA, aB;

LL ans;

void input(){
	in >> n >> m;
	for (int i = 0; i < n; ++i){
		LL t;
		in >> t;
		t %= m;
		if (i % 2 == 0){
			A.push_back(t);
		}
		else{
			B.push_back(t);
		}
	}
}


void dfs(LL pos,LL sum,vector<LL>& arr, vector<LL>& ret){
	if (pos == arr.size()){
		return;
	}

	ret.push_back(sum);
	dfs(pos + 1, sum, arr, ret);

	ret.push_back((sum + arr[pos])%m);
	dfs(pos + 1, (sum + arr[pos]) % m, arr, ret);

}


void cale(vector<LL>& p,vector<LL>& t){
	for (LL val : p){

		if (val == 571){
			int t = 0;
		}

		ans = max(val, ans);
		LL need = m - val - 1;
		vector<LL>::iterator it = upper_bound(t.begin(), t.end(), need);
		if (it != t.begin())
			--it;
		if (it != t.end()){
			ans = max(ans, (val + *it) % m);

		}

		need = (2 * m - val - 1)%m;
		it = upper_bound(t.begin(), t.end(), need);

		if (it != t.begin())
			--it;
		if (it != t.end())
			ans = max(ans, (val + *it)%m);

	}
}



int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		dfs(0, 0, A, aA);
		dfs(0, 0, B, aB);

		sort(aA.begin(), aA.end());
		aA.erase(unique(aA.begin(), aA.end()), aA.end());

		sort(aB.begin(), aB.end());
		aB.erase(unique(aB.begin(), aB.end()), aB.end());

		ans = 0;

		cale(aA, aB);
		cale(aB, aA);

		cout << ans << endl;





	}


	return 0;
}





