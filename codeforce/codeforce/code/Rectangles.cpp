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


int n, m;
int mmp[60][60];


void input(){
	in >> n >> m;
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= m; ++j)
		in >> mmp[i][j];


}

LL ppp[60];

int main(){
	ppp[0] = 1;
	for (int i = 1; i<60; ++i)
		ppp[i] = ppp[i - 1] * 2;


	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			int zero = 0, one = 0;
			for (int j = 1; j <= m; ++j){
				if (mmp[i][j] == 0){
					zero++;
				}
				else
					one++;
			}
			ans += ppp[zero] - 1;
			ans += ppp[one] - 1;
		}


		for (int i = 1; i <= m; ++i){
			int zero = 0, one = 0;
			for (int j = 1; j <= n; ++j){
				if (mmp[j][i] == 0){
					zero++;
				}
				else
					one++;
			}
			ans += ppp[zero] - 1;
			ans += ppp[one] - 1;

		}


		ans -= n*m;
		cout << ans << endl;








	}


	return 0;
}





