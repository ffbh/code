
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


int N, M;

void input(){
	fflush(stdin);
	fflush(stdout);
	in >> N >> M;
	fflush(stdin);
	fflush(stdout);

}

int f[10];

int V = 2;

int prime[7] = {18,17,16,15,14,13,11 };

int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE >> N >> M;
	while (TEST_CASE-- > 0){
		/*input();*/


		//	for (int KKK = 1; KKK <= 100; ++KKK){
		//	V = KKK;
		int mmax = 0;
		for (int i = 0; i < 7; ++i){
			fflush(stdin);
			fflush(stdout);
			string str = "";
			for (int j = 1; j <= 18; ++j){
				str += to_string(prime[i]);
				str += " ";
			}
			cout << str << endl;
			fflush(stdin);
			fflush(stdout);
			int sum = 0;
			for (int j = 1; j <= 18; ++j){
				int ttt;
				in >> ttt;
				sum += ttt;
				}
	//		sum = V % prime[i];

			fflush(stdin);
			fflush(stdout);
			mmax = max(mmax, sum);
			f[i] = sum%prime[i];


		}
		int ans;
		for (int i = mmax; i <= M; ++i){
			bool ok = 1;
			for (int k = 0; k < 7; ++k){
				if (i % prime[k] != f[k] % prime[k]){
					ok = 0;
					break;
				}
			}
			if (ok){
				ans = i;
				break;
			}
		}
		fflush(stdin);
		fflush(stdout);
		//	assert(ans == KKK);
		cout << ans << endl;
		fflush(stdin);
		fflush(stdout);
		int cost;
		in >> cost;
		//	assert(cost == 1);
		fflush(stdin);
		fflush(stdout);

		//	}
	}


	return 0;
}





