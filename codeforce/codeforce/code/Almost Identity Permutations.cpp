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

LL n, k;



void input(){
	in >> n >> k;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL ans = 0;
		ans = 1;
		if (k >= 2){
			ans += n*(n - 1) / 2;
		}

		if (k >= 3){
			ans += n*(n - 1)*(n - 2) * 2 / 3 / 2;

		}

		if (k >= 4){
			ans += n*(n - 1)*(n - 2)*(n - 3) * 9 / 4 / 3 / 2;
		}


		cout << ans << endl;








	}


	return 0;
}





