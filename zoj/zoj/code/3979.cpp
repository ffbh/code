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





void input(){



}


int main(){

	int T;
	int n, m;
	in >> T;
	while (T-- > 0){
		in >> n >> m;
		int base = n / m;
		int mod = n%m;
		vector<int> ans;
		for (int i = 1; i <= m; ++i){
			for (int j = 0; j < base; ++j)
				ans.push_back(i);
		}
		for (int i = 1; i <= mod; ++i)
			ans.push_back(i);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size() - 1; ++i)
			printf("%d ", ans[i]);
		printf("%d\n", ans.back());

	}













	


	return 0;
}





