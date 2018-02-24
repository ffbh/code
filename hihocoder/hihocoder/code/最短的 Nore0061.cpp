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
#define INF (66666666)
string A, B, S;
int la, lb, ls;
int dp[3010][110][110];
int ans;
void input(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> (A ) >> (B ) >> (S );
	A = '-' + A;
	B = '-' + B;
	S = '-' + S;

}

int dfs(int s,int a,int b){
	int &ref = dp[s][a][b];
	if (ref != -1){
		return ref;
	}
	ref = INF;
	if (a == la && b == lb){
		return s;
	}

	if (s == ls)
		return INF;

	ref = min(ref, dfs(s + 1, a, b));

	if (a < la&&S[s + 1] == A[a + 1]){
		ref = min(ref, dfs(s + 1, a + 1, b));
	}
	if (b < lb&&S[s + 1] == B[b + 1]){
		ref = min(ref, dfs(s + 1, a, b + 1));
	}
	if (a == 0 && b == 0 && ref != INF){
		ans = min(ans, ref - s );
	}
	return ref;
}

int main(){
	input();
	
	la = A.length() - 1;
	lb = B.length() - 1;
	ls = S.length() - 1;

	ans = INF;
	memset(dp, -1, sizeof(dp));


	dfs(0, 0, 0);
	if (ans != INF)
		cout << ans << endl;
	else
		cout << -1 << endl;













	return 0;
}





