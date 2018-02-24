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

LL n;
LL a[100010], b[100010];



void input(){
	in >> n;
	for (int i = 0; i < n; ++i)
		in >> a[i];
	for (int i = 0; i < n; ++i)
		in >> b[i];

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		LL sum = 0;

		for (int i = 0; i < n; ++i)
			sum += a[i];

		sort(b, b + n, greater<int>());

		LL all = b[0] + b[1];
		if (sum <= all){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;

		}













	}


	return 0;
}





