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


LL a, b, n;


void input(){
	fflush(stdin);
	fflush(stdout);
	in >> a >> b;
	in >> n;
	
	fflush(stdin);
	fflush(stdout);

}


int main(){

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		a++;
		while (a <= b){
			LL mid = (a + b) / 2;
			fflush(stdin);
			fflush(stdout);
			cout << mid << endl;
			
			string s;
			fflush(stdin);
			fflush(stdout);
			in >> s;
			fflush(stdin);
			fflush(stdout);
			if (s == "CORRECT"){
				break;
			}
			else if (s == "TOO_BIG"){
				b = mid - 1;
			}
			else if (s == "TOO_SMALL"){
				a = mid + 1;
			}
			else{
				assert(0);
			}
		}














	}


	return 0;
}





