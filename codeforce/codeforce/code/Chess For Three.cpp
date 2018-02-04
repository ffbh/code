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

int n, p[110];



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> p[i];
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		int a, b, c;
		a = 1;
		b = 2;
		c = 3;
		bool ok = 1;
		for (int i = 1; i <= n; ++i){
			if (p[i] == c){
				ok = 0;
				break;
			}
			if (a == p[i]){
				swap(b, c);
			}
			else {
				swap(a, c);
			}

		}

		if (ok){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}











	}


	return 0;
}





