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



LL n, x, a[100010];

void input(){
	in >> n >> x;
	for (int i = 1; i <= n; ++i)
		in >> a[i];

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += a[i];
		sum += n - 1;
		if (sum == x ){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}













	}


	return 0;
}





