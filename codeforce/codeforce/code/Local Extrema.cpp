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

int n, a[1010];



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (n == 1){
			cout << 0 << endl;
			return 0;
		}


		int ans = n - 2;
		for (int i = 2; i < n; ++i){
			if (a[i]>a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1]){


			}
			else{
				ans--;


			}


		}

		cout << ans << endl;











	}


	return 0;
}





