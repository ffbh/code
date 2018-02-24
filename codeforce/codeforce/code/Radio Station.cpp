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

unordered_map<string, string> mii;
int n, m;


void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i){
		string a, b;
		in >> a >> b;
		mii[b] = a;
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		while (m-- > 0){
			string a, b;
			in >> a >> b;
			b = b.substr(0, b.length() - 1);
			cout << a << " " << b << "; #" << mii[b] << endl;
		}













	}


	return 0;
}





