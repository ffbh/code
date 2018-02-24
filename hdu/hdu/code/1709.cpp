#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <cmath>
using namespace std;



int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	int S;
	int num[110];
	bool dp[21000];
	bool DP[21000];
	set<int> ss;
	while (cin >> N){
		S = 0;
		ss.clear();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++i){
			cin >> num[i];
			S += num[i];
		}
		dp[0] = 1;
		for (int k = 0; k < N; ++k){
			memset(DP, 0, sizeof(DP));
			for (int j = S; j >= 0; --j)
				if (dp[abs(j-num[k])]||dp[j+num[k]])
					DP[j] = 1;
			for (int i = 0; i <= S; ++i)
				if (DP[i])
					dp[i] = 1;
		}
		for (int i = 1; i <= S;++i)
		if (dp[i] == 0)
			ss.insert(i);
		if (ss.size() == 0)
			cout << 0 << endl;
		else
		{
			cout << ss.size() << endl;
			bool sign = 0;
			set<int>::iterator it = ss.begin();
			while (it != ss.end()){
				if (sign == 0){
					sign = 1;
					cout << *it;
				}
				else
					cout << " " << *it;
				it++;
			}
			cout << endl;
		}
	}
	return 0;
}