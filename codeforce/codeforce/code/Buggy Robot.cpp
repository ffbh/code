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

int n;
string s;




void input(){
	in >> n >> s;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int a, b, ans = -1;
		a = b = 0;




		for (int i = 0; i < s.length(); ++i){
			


			if (s[i] == 'L')
				a--;
			else if (s[i] == 'R')
				a++;
			else if (s[i] == 'U')
				b--;
			else if (s[i] == 'D')
				b++;

		

		}

		cout << n - abs(a) - abs(b)<< endl;













	}


	return 0;
}





