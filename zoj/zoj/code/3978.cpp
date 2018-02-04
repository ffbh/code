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





void input(){



}

int table[2][7] = { { 2, 3, 5, 4, 6, 7, 3 }, { 3, 5, 2, 7, 3, 4, 6 } };


int main(){
	int T;
	in >> T;
	map<string, int> mii;
	mii["UFS2.0"] = 0;
	mii["UFS2.1"] = 1;
	mii["eMMC5.1"] = 2;
	mii["LPDDR3"] = 3;
	mii["LPDDR4"] = 4;
	mii["Sparse"] = 5;
	mii["Normal"] = 6;
	
	while (T-- > 0){
		int N;
		in >> N;
		double a = 1, b = 1;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < 3; ++j){
				string str;
				in >> str;
				a += log(table[0][mii[str]]);
				b += log(table[1][mii[str]]);
			}
			
		}

		if (fabs(a-b) < 1e-7){
			printf("E\n");
		}
		else if (a > b){
			printf("A\n");
		}
		else{
			printf("B\n");
		}


	}

	return 0;
}





