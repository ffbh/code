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
LL N;




void input(){



}


int main(){
	while (in >> N){
		if (N == 1){
			cout << 0 << endl;
			continue;
		}


		LL cube = N*N*N;
		LL ans = cube * (cube - 1) / 2;
		LL outer =  (N - 1) * 4 * 2 + (N - 2) * 4;
		LL five = (N - 2)*(N - 2) * 6;
		LL inner = cube - outer - five;
		ans -= 12;
		ans -= (outer - 8) * 4 / 2;
		ans -= five / 2 * 5;
		ans -= inner * 6 / 2;
		cout << ans << endl;


	}
	




	return 0;
}





