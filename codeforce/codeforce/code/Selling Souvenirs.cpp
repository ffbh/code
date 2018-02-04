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


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int n, m;
vector<LL> V[4];



void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i){
		LL w, c;
		in >> w >> c;
		V[w].push_back(c);
	}
}

LL dp[300010];
pii pace[300010];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i < 4; ++i)
			sort(V[i].begin(), V[i].end(), greater<int>());

		for (int i = 1; i <= m; ++i){
			

			LL val;
			pace[i] = pace[i - 1];
			dp[i] = dp[i - 1];
			if (1 <= i && pace[i - 1].first < V[1].size()){


				val = dp[i - 1] + V[1][pace[i - 1].first];
				if (val >= dp[i]){
					dp[i] = val;
					pace[i].first = pace[i - 1].first + 1;
					pace[i].second = pace[i - 1].second;
				}
			}

			if (2 <= i && pace[i - 2].second < V[2].size()){


				val = dp[i - 2] + V[2][pace[i - 2].second];

				if (val >= dp[i]){
					dp[i] = val;
					pace[i].first = pace[i - 2].first;
					pace[i].second = pace[i - 2].second + 1;
				}
			}
		}

		LL ans = dp[m];
		LL sum = 0;
		for (int i = 0; i < V[3].size(); ++i){
			if (m - 3 * (i + 1) < 0)
				break;

			sum += V[3][i];
			if (ans < sum + dp[m - 3 * (i + 1)])
				ans = sum + dp[m - 3 * (i + 1)];


		}

		cout << ans << endl;








	}


	return 0;
}





