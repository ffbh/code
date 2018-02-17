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
#define lson (root<<1)  
#define rson (root<<1|1)  

int a, b;


void input(){
	in >> a >> b;


}

bool cale(){
	if (b == 0)
		return 0;
	if (b == 1 && a > 0)
		return 0;
	if (a < b- 1)
		return 0;
	a -= b - 1;
	return a % 2 == 0;



}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		if (cale()){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}














	}


	return 0;
}





