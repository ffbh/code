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

int mmp[4][4];
int car[4];



void input(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			in >> mmp[i][j];
		}

		if (mmp[i][3]){
			car[i] = 1;
		}
	}


}

int c[3] = { -1, 2, 1 };

bool judge(){
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 3; ++j){
		if (mmp[i][j] == 1){
			if (car[i])
				return 0;
			if (car[(i + c[j] + 4) % 4])
				return 0;
		}

	}
	return 1;

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (!judge()){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}












	}


	return 0;
}





