#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;
int N, tN;
string s;
stringstream ss;
bool judge(){
	ss.clear();
	ss.str(s);
	int num = 0;
	while (ss >> tN){
		num++;
	}
	return num == 1;

}

int order[30], r[30], rk[30], dp[30];


int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	while (getline(in, s)){
		if (judge()){
			N = tN;
			for (int i = 1; i <= N; ++i){
				
				in>>order[i];
			}
			getline(in, s);
		}
		else{
			ss.clear();
			ss.str(s);
			for (int i = 1; i <= N; ++i){
				int t;
				ss >> t;
				r[t] = i;
			}
			for (int i = 1; i <= N; ++i)
				rk[i] = order[r[i]];
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= N; ++i){
				dp[i] = 1;
				for (int j = 1; j < i;++j)
				if (rk[i] > rk[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			int ans = 0;
			for (int i = 1; i <= N; ++i)
				ans = max(ans, dp[i]);
			cout << ans << endl;

		}



	}



	return 0;
}