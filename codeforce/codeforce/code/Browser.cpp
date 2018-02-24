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

int n, pos, l, r;



void input(){
	in >> n >> pos >> l >> r;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (l == 1 && r == n){
			cout << 0 << endl;
		}
		else if (l == 1){
			cout << abs(pos - r) + 1 << endl;
		}
		else if (r == n){
			cout << abs(pos - l) + 1 << endl;
		}
		else{
			int L = abs(pos - l);
			int R = abs(pos - r);
			int len = r - l;
			cout << len + min(L, R) + 2 << endl;

		}










	}


	return 0;
}





