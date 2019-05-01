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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}

int n;
int a[110];

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		int ans = 0;
		for (int i = 1; i < n; ++i){
			if (a[i] == 1){
				if (a[i + 1] == 2){
					ans += 3;
				}
				else{
					ans += 4;
				}
			}
			else if (a[i] == 2){
				if (a[i + 1] == 1){
					ans += 3;
				}
				else{
					ans = -1;
					break;
				}
			}
			else{
				if (a[i + 1] == 1){
					ans += 4;
				}
				else{
					ans = -1;
					break;
				}

			}

		}

		for (int k = 3; k <= n; ++k){
			if (a[k] == 2 && a[k - 1] == 1 && a[k - 2] == 3){
				ans--;
			}
		}

		if (ans <= -1){
			cout << "Infinite" << endl;
		}
		else{
			cout << "Finite" << endl;
			cout << ans << endl;
		}













	}


	return 0;
}





