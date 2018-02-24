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
int dp[110][2];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		memset(dp, 0, sizeof(dp));
		dp[n][a[n]] = 1;
		for (int i = n - 1; i >= 1; --i){
			if (a[i] == 0){
				dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]) + 1;
				dp[i][1] = dp[i + 1][1];
			}
			else{
				dp[i][0] = dp[i + 1][0];
				dp[i][1] = dp[i + 1][1] + 1;
			}
		}

		
		cout << max(dp[1][0], dp[1][1]) << endl;;












	}


	return 0;
}





