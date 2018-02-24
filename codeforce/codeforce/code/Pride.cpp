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

#define MMAX (33333)

vector<int> prime;
bool vis[MMAX];

int n;
int a[2010];



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

int gcd(int a,int b){
	if (b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		

		input();
		int one = 0;
		for (int i = 1; i <= n; ++i){
			if (a[i] == 1){
				one++;
			}
		}

		if (one != 0){
			cout << n - one << endl;
		}
		else{
			int ans = (int)1e9;
			for (int k = 1; k <= n; ++k){
				int now = a[k];
				for (int j = k + 1; j <= n; ++j){
					now = gcd(now, a[j]);
					if (now == 1){
						ans = min(ans, n - 1 + j - k);
					}
				}
				
			}
			if (ans != int(1e9))
				cout << ans << endl;
			else
				cout << -1 << endl;

		}











	}


	return 0;
}





