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


int n, m;


void input(){
	in >> n >> m;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		double ans = 1e18;
		for (int i = 1; i <= n; ++i){
			double a, b;
			in >> a >> b;
			double p = a / b;
			double q = p * m;
			ans = min(ans, q);
		}
		printf("%.9f\n", ans);













	}


	return 0;
}





