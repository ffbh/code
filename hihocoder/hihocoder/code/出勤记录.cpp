#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

bool judge(string& s){
	int A, L;
	A = 0;
	L = 0;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == 'L'){
			L++;
			if (L == 3)
				return 0;
		}
		else{
			L = 0;
			if (s[i] == 'A')
				A++;

		}

	}
	return A <= 1;
}
int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T-- > 0){
		string s;
		cin >> s;
		if (judge(s)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}




	}
















	return 0;
}