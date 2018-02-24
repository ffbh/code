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


LL n, d;
LL a[100010];


void input(){
	in >> n >> d;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}


}

bool judge(){
	LL sum = 0;
	for (int i = 1; i <= n; ++i){
		sum += a[i];
		if (sum > d){
			return 0;
		}
		if (a[i] == 0){
			if (sum < 0)
				sum = 0;	
		}
	}
	if (sum > d)
		return 0;
	return 1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		if (!judge()){
			cout << -1 << endl;
		}
		else{
			int ans = 0;
			LL sum = 0;
			for (int i = 1; i <= n; ++i){
				sum += a[i];
				if (sum > d){
					sum = d;
				}
				if (a[i] == 0){
					if (sum < 0){
						sum = d;
						ans++;
					}
				}
			}
			cout << ans << endl;

		}

		












	}


	return 0;
}





