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

ifstream in("C:\\input.txt");
//istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

char str[5010];
int n, k;
string dp[2][5010];


bool cmp(string & a,string& b){
	if (a.size() == 0)
		return 1;
	return a < b;
}

void input(){
	in >> (str + 1);
	n = strlen(str + 1);
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		k = (int)(log(n) / log(2));

		for (int i=1)












	}


	return 0;
}





