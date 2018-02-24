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
int dp[110][110];
string s;

int dfs(int a,int b){
	if (a >= b)
		return 0;

	if (dp[a][b] != -1)
		return dp[a][b];
	
	if (s[a] == s[b]){
		dp[a][b] = dfs(a + 1, b - 1);
	}
	else{
		dp[a][b] = min(min(dfs(a + 1, b), dfs(a, b - 1)), dfs(a + 1, b - 1)) + 1;
	}
	return dp[a][b];


}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	memset(dp, -1, sizeof(dp));
	in >> s;



	cout << dfs(0, s.length() - 1) << endl;













	return 0;
}





