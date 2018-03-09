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


LL a, b;

void input(){
	in >> a >> b;
}


void dfs(){
	if (a == 0 || b == 0)
		return;
	if (a >= 2 * b){
		a %= (2 * b);
	}
	else if (b >= 2 * a){
		b %= (2 * a);
	}
	else{
		return;
	}
	dfs(); 

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		dfs();
		cout << a << " " << b << endl;











	}


	return 0;
}





