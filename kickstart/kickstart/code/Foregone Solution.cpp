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


string str;

void input(){
	in >> str;


}



int main(){

	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		string A = string( str.length(),'0');
		string B = string( str.length(),'0');
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == '4'){
				A[i] = '1';
				B[i] = '3';
			}
			else{
				A[i] = str[i];
				B[i] = '0';
			}
		}

		printf("Case #%d:", CPP++);
		int pos = 0;
		while (A[pos] == '0'){
			pos++;
		}
		cout << " ";
		cout << A.substr(pos);
		pos = 0;
		while (B[pos] == '0'){
			pos++;
		}
		cout << " ";
		cout << B.substr(pos);
		cout << endl;






	}


	return 0;
}





