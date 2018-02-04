#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
	ifstream in("C:\\input.txt");
	string s;
	while (cin >> s){
		int ans = 0;
		for (int i = 0; i < s.length(); ++i)
			ans = (ans * 10 + s[i] - '0')%3;
		if (ans){
			cout << 1 << endl;
			cout << ans << endl;
		}
		else
			cout << 2 << endl;

	}
















	return 0;
}