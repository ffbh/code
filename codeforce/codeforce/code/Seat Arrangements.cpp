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



int n, m, k;
char str[2010][2010];
int ok[2010][2010];
void input(){
	in >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		in >> str[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		for (int i = 1; i <= n;++i)
		for (int j = 1; j <= m;++j)
		if (str[i][j-1] == '.')
			ok[i][j] = 1;

		int ans = 0;
		for (int i = 1; i <= n; ++i){
			int sum = 0;
			for (int j = 1; j <= m; ++j){
				if (ok[i][j]){
					sum++;
				}
				else{
					sum = 0;
				}
				if (sum >= k){
					ans++;
				}
			}
		}
		if (k > 1){
			for (int j = 1;  j <= m; ++j){
				int sum = 0;
				for (int i = 1; i <= n; ++i){
					if (ok[i][j]){
						sum++;
					}
					else{
						sum = 0;
					}
					if (sum >= k){
						ans++;
					}
				}
			}
		}

		cout << ans << endl;








	}


	return 0;
}





