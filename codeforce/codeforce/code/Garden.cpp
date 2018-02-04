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



int n, k;
int a[110];
void input(){
	in >> n >> k;
	for (int i = 1; i <= n; ++i)
		in >> a[i];

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int ans = 110;
		for (int i = 1; i <= n; ++i){
			if (k % a[i] == 0){
				ans = min(ans, k / a[i]);
			}

		}
		cout << ans << endl;












	}


	return 0;
}





