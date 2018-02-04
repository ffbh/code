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
int a[200010];
bool ok[1000010];

void input(){
	in >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= n; ++i)
			ok[a[i]] = 1;

		int sum = 0;
		int ans = 0;
		for (int i = 1; i <= m; ++i){
			if (ok[i]){
				if (sum < k - 1){
					sum++;
				}
				else{
					ans++;
					ok[i] = 0;
				}
			}
		}

		for (int i = m + 1; i < 1000010; ++i){
			if (ok[i - m]){
				sum--;
			}
			if (ok[i]){
				if (sum < k - 1){
					sum++;
				}
				else{
					ans++;
					ok[i] = 0;
				}
			}
		
		}

		cout << ans << endl;











	}


	return 0;
}





