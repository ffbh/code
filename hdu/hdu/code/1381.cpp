#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	string s;
	set<string> ss;
	int n, nc;
	int N;
	cin >> N;
	int ok = 0;
	while (N--){
		if (ok == 1)cout << endl;
		ok = 1;
		ss.clear();
		cin >> n >> nc;
		cin >> s;
		int len = s.length();
		for (int i = 0; i <= len - n; ++i)
			ss.insert(s.substr(i, n));
		cout << ss.size() << endl;
	
	}

	return 0;
}