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

bool ok[5010];
void init(){
	ok[1] = 1;
	int a, b;
	a = b = 1;
	while (a <= 1000){
		int c = a + b;
		ok[c] = 1;
		a = b;
		b = c;
	}
}

void input(){
	in >> n;


}


int main(){
	init();
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= n; ++i){
			if (ok[i]){
				cout << "O";
			}
			else{
				cout << "o";
			}
		}
		cout << endl;












	}


	return 0;
}





