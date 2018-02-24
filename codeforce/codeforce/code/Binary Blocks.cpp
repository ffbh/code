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
int mmp[5010][5010];
int n, m;
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n >> m;
	for (int i = 1; i <= n; ++i){
		string s;
		in >> s;
		for (int j = 1; j <= m; ++j)
			mmp[i][j] = s[j - 1] - '0';
	}
	for (int i = 1; i <= 2*max(n,m); ++i)
	for (int j = 1; j <= 2*max(n,m); ++j)
		mmp[i][j] = mmp[i - 1][j] + mmp[i][j - 1] - mmp[i - 1][j - 1] + mmp[i][j];
	int ans = n*m;
	for (int k = 2; k <= max(n, m); ++k){
		int tn, tm;
		tn = n / k;
		if (n%k != 0)
			tn++;
		tn *= k;
		tm = m / k;
		if (m%k != 0)
			tm++;
		tm *= k;
		int sum = 0;
		for (int i = 1; i <= tn;i+=k)
		for (int j = 1; j <= tm; j += k){
			int ti = i + k - 1;
			int tj = j + k - 1;
			int tmp = mmp[ti][tj] - mmp[i - 1][tj] - mmp[ti][j - 1] + mmp[i - 1][j - 1];
			sum += min(k*k - tmp, tmp);
		}
		ans = min(sum, ans);



	}


	cout << ans << endl;












	return 0;
}





