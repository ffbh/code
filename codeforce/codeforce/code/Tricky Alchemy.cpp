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


LL a, b;
LL x, y, z;


void input(){
	in >> a >> b;
	in >> x >> y >> z;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL A = x * 2 + y;
		LL B = y + z * 3;
		LL ans = 0;
		if (A > a)
			ans += A - a;
		if (B > b)
			ans += B - b;
		cout << ans << endl;
















	}


	return 0;
}





