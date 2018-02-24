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

string s;
int k;



void input(){
	in >> s >> k;


}

bool h[266];
int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		if (s.length() < k){
			cout << "impossible" << endl;
		}
		else{
			int diff = 0;
			for (char c : s){
				if (!h[c]){
					h[c] = 1;
					diff++;
				}
			}
			if (k >= diff)
				cout << k - diff << endl;
			else
				cout << 0 << endl;
		}














	}


	return 0;
}





