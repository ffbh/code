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
map<int, int> M;


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		int t;
		in >> t;
		M[t]++;
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		vector<int> all;
		for (pii p : M){
			if (p.second % 2 == 1){
				cout << "Conan" << endl;
				return 0;
			}
		}

		
		cout << "Agasa" << endl;











	}


	return 0;
}





