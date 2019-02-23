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

string str;
bool ok[5010][5010];
int num[26][5010];

void input(){
	in >> str;


}

int dfs(int l ,int r){
	int len = r - l + 1;
	if (l == r){
		return -1;
	}

	if (!ok[l][r]){
		return 1;
	}

	if (len % 2 == 0){
		int R = r / 2;
		return dfs(l, R);
	}
	else{
		int R = r / 2;
		R--;
		return dfs(l, R) * 2;
	}
}

bool judge(string s){
	int l = 0, r = s.length() - 1;
	while (l < r){
		if (s[l] != s[r]){
			return 0;
		}
		l++; 
		r--;
	}
	return 1;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int n = str.length();
		for (int len = 1; len <= n;++len)
		for (int i = 0; i + len - 1 < n; ++i){
			int j = i + len - 1;
			if (i == j){
				ok[i][j] = 1;
			}
			else if (i + 1 == j){
				ok[i][j] = (str[i] == str[j]);
			}
			else{
				ok[i][j] = ok[i + 1][j - 1] && (str[i] == str[j]);
			}
		}

		int mid = n / 2;
		if (n % 2 == 1){
			mid--;
		}
	//	cout << mid << endl;
		int ans = 3;
		for (int i = 0; i <= mid; ++i){
			if (i == 1){
				int t = 0;
			}
			if (!ok[0][i]){
				ans = min(ans, 2);
			}
			string nn = str.substr(i+1) + str.substr(0, i+1);
			if (nn != str && judge(nn)){
				ans = 1;
				break;
			}
		}

		if (ans > 2){
			cout << "Impossible" << endl;
		}
		else{
			cout << ans << endl;
		}










	}


	return 0;
}





