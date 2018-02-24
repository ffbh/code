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


int x, h, m;


void input(){
	in >> x >> h >> m;


}

bool lucky(int p){
	int a = p / 60;
	int b = p % 60;
	return a % 10 == 7 || b % 10 == 7;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		
		int time = h * 60 + m;
		int k = time;
		for (; time >= 0; --time){
			if (!lucky(time)){
				continue;
			}
			if (abs(k - time) % x == 0){
				cout << abs(k - time) / x << endl;
				return 0;
			}


		}

		for (time = 24 * 60 ; time >= 0; --time){
			if (!lucky(time)){
				continue;
			}
			if ((k + 24 * 60 - time) % x == 0){
				cout << (k+ 24 * 60 - time) / x << endl;
				return 0;
			}
		}











	}


	return 0;
}





