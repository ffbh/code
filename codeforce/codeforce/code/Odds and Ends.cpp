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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;


int n, a[110];





void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}
int dp[110][2];
bool dfs(int pos ,int f){
	if (pos == n + 1){
		return f == 1;
	}
	int & ref = dp[pos][f];
	if (ref != -1){
		return ref;
	}
	ref = 0;
	if (a[pos] % 2 == 0){
		return ref = 0;
	}
	for (int i = pos; i <= n; i += 2){
		if (a[i] % 2 == 1){
			if (dfs(i + 1, 1 - f)){
				return ref = 1;
			}
		}
	}

	return ref = 0;


}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		memset(dp, -1, sizeof(dp));
		if (dfs(1, 0)){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;




	}


	return 0;
}





