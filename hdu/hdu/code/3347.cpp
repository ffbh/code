#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>
using namespace std;
map<string, int> msi;
stringstream ss;
int getInt(string& tmp){
	if (tmp[0] == '-' || tmp[0] >= '0'&&tmp[0] <= '9'){
		ss.clear();
		ss.str(tmp);
		int t;
		ss >> t;
		return t;
	}
	else
		return msi[tmp];
}




int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		msi.clear();
		int N;
		cin >> N;
		while (--N){
			string s;
			char c;
			int number;
			cin >> s >> c >> number;
			msi[s] = number;
		}
		string s1, s2;
		cin >> s1;
		int sum = getInt(s1);
		while (cin >> s1 >> s2){
			if (s1 == "=")
				break;
			int tmp = getInt(s2);
			if (s1 == "-")
				tmp = -tmp;
			sum += tmp;
		}
		cout << sum << endl;

	}


	return 0;
}
