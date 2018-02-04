#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int Get(const string& s, int h){
	int res = 0;
	for (int i = 0; i < s.length(); ++i)
		res = res*h + s[i] - '0';
	return res;
}


int main(){
	ifstream in("C:\\temp.txt");
	stringstream ss;
	int N;
	int sum;
	while (cin >> N){
		sum = 0;
		while (N--){
			string s;
			cin >> s;
			int h;
			for (int i = 0; i < s.length();++i)
			if (s[i] == '(' || s[i] == ')')
				s[i] = ' ';
			ss.clear();
			ss.str(s);
			ss >> s >> h;
			sum += Get(s, h);
		}
		cout << sum << endl;
	}





	return 0;
}