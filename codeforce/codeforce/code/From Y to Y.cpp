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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

int k;




void input(){
	in >> k;


}

int cale(char c,int rest){
	putchar(c);
	for (int i = 1; i <= rest; ++i){
		putchar(c);
		rest -= i;
	}
	return rest;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		for (char c = 'a'; c <= 'z'; ++c){
			k = cale(c, k);
		}
		cout << endl;

	}


	return 0;
}





