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
int ans;



void input(){
	in >> str;


}

void cale(int pos){
	int st = pos;
	int l, q;
	l = q = 0;
	while (pos < str.length()){
		if (str[pos] == '('){
			l++;
		}
		else if (str[pos] == '?'){
			q++;
		}
		else{
			if (l>0){
				l--;
			}
			else if (q > 0){
				q--;
			}
			else{
				return;
			}
		}

		while (q > l){
			q--;
			l++;
		}
		
		if ((l + q) % 2 == 0){
			if (l <= q){
				ans++;
			}

		}
		


		
		pos++;
	}
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 0; i < str.length(); ++i){
			cale(i);
		//	cout << ans << endl;
		}

		cout << ans << endl;











	}


	return 0;
}





