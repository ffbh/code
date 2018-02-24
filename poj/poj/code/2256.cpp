#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>
using namespace std;
double P, U, V;
bool p, u, v;
void judge(string& s){
	double val = 0;
	double f = 1;
	bool dian = 0;
	int sign = 1;
	if (s.length() >= 4 && (s[0] == 'P' || s[0] == 'U' || s[0] == 'I') && s[1] == '='){
		int start = 2;
		while (s[start] >= '0'&&s[start] <= '9' || s[start] == '.' || s[start] == '-'){
			if (s[start] == '-')
				sign = -1;
			else if (s[start] == '.'){
				dian = 1;
				f = 0.1;
			}
			else{
				if (dian){
					val += (s[start] - '0')*f;
					f /= 10;
				}
				else{
					val = val * 10 + s[start] - '0';
				}
			}
			start++;
		}
		val = val * sign;
		switch (s[start]){
		case 'm':
			val = val * 0.001;
			break;
		case 'k':
			val = val * 1000;
			break;
		case'M':
			val = val * 1000000;
			break;
		}

		switch (s[0]){
		case 'P':
			p = 1;
			P = val;
			break;
		case 'U':
			u = 1;
			U = val;
			break;
		case 'I':
			v = 1;
			V = val;
			break;
		}
	}
}


int main(){
	//ifstream in("C:\\input.txt");
	int T, CASE = 1;
	cin >> T;
	cin.get();
	stringstream ss;
	while (T--){
		string s;
		getline(cin, s);
		ss.str(s);
		ss.clear();
		p = u = v = 0;
		while (ss >> s){
			judge(s);
		}
		printf("Problem #%d\n", CASE++);
		if (p&&u){
			printf("I=%.2fA\n", P / U);
		}
		else if (p&&v){
			printf("U=%.2fV\n", P / V);;
		}
		else{
			printf("P=%.2fW\n", U * V);
		}
		cout << endl;
	}
	return 0;
}