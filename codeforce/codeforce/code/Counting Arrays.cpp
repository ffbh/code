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

int q;
pii data[100010];

LL mod = 1e9 + 7;


void input(){
	in >> q;
	for (int i = 0; i < q; ++i){
		in >> data[i].first >> data[i].second;

	}


}


LL p[1000010];

LL dp[21][1000010];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();



		p[1] = 1;
		for (int i = 2; i < 1000010; ++i){
			p[i] = p[i - 1] * 2 % mod;
		}

		for (int i = 2; i < 1000010; ++i)
			dp[1][i] = 1;

		for (int i = 2; i < 21; ++i)
		for (int j = 2; j < 1000010; ++j)
			if(dp[i - 1][j])
		for (int k = j + j; k < 1000010; k += j){
			dp[i][k] = (dp[i][k] + dp[i - 1][j]) % mod;
		}

		int t = 0;
		t++;

		cout << 0 << endl;








	}


	return 0;
}