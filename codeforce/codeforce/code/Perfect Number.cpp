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



int k;

void input(){
	in >> k;


}

int cale(int n){
	int sum = 0;
	while (n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1;; ++i){
			if (cale(i) == 10)
				k--;

			if (k == 0){
				cout << i << endl;
				break;
			}
		}













	}


	return 0;
}





