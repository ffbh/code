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


int n;


void input(){
	in >> n;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		vector<int> all;
		all.push_back(1);
		int dig = 1;
		while (all.back() < int(1e5)){
			int val = all.back() * 2;
			dig++;
			val += pow(2, dig);
			dig++;
			all.push_back(val);
		}
		
		int ans;
		for (int k : all){
			if (n % k == 0){
				ans = k;
			}
		}
		cout << ans << endl;










	}


	return 0;
}





