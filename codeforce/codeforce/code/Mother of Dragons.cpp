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
using namespace std;
int n, k, mmp[41][41];
vector<int> all;
int ans;
void input(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> k;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		in >> mmp[i][j];

}

void dfs(int p){
	//cout << p << endl;
	if (n - p + 1 + all.size() <= ans)
		return;
	if (all.size() > ans)
		ans = all.size();
	if (p == n + 1){
		return;
	}

	bool can_put = 1;
	for (int a : all){
		if (!mmp[a][p]){
			can_put = 0;
			break;
		}
	}

	dfs(p + 1);

	if (can_put){
		all.push_back(p);
		dfs(p + 1);
		all.pop_back();
	}

}

int main(){
	input();

	dfs(1);
	double ret = (double)k*k*(ans - 1) / 2.0 / (ans);
	printf("%.10f\n", ret);

















	return 0;
}





