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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;



LL l, r, x, y, k;

void input(){
	in >> l >> r >> x >> y >> k;


}

bool judge(){
	LL L = x, R = y;
	while (L <= R){
		LL mid = (L + R) / 2;
		if (mid * k >= l&&mid*k <= r){
			return 1;
		}
		else if (mid*k < l){
			L = mid + 1;
		}
		else
			R = mid - 1;

	}
	return 0;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		
		if (judge()){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;











	}


	return 0;
}





