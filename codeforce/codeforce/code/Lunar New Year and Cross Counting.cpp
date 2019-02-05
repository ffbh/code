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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n;
string str[510];

void input(){
	in >> n;
	for (int i = 0; i < n; ++i){
		in >> str[i];
	}


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int  num = 0;
		for (int i = 1; i < n - 1;++i)
		for (int j = 1; j < n - 1; ++j){
			if (str[i][j] == 'X' && str[i - 1][j - 1] == 'X'
				&& str[i - 1][j + 1] == 'X' && str[i + 1][j - 1] == 'X' && str[i + 1][j + 1] == 'X'){
				num++;
			}

		}
		cout << num << endl;













	}


	return 0;
}





