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
LL a[100010], b[100010];


void input(){
	in >> n >> k;
	for (int i = 0; i < n; ++i)
		in >> a[i] >> b[i];
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL sum = 0;
		vector<LL> all;

		for (int i = 0; i < n; ++i){
			sum += min(a[i], b[i]);
			if (b[i] > a[i]){
				all.push_back(min(b[i] - a[i], a[i]));
			}
			else{
				all.push_back(0);
			}
		}

		sort(all.begin(), all.end(),greater<LL>());

		for (int i = 0; i < k; ++i)
			sum += all[i];

		cout << sum << endl;







	}


	return 0;
}





