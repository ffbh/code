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



string str;

void input(){
	in >> str;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		int ans = 0;
		for (char c : str){
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
				ans++;
			}
			else {
				int d = c - '0';
				if (d >= 0 && d <= 9 && d % 2 == 1){
					ans++;
				}

			}



		}

		cout << ans << endl;











	}


	return 0;
}





