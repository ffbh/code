#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int T;



int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.length(); ++i){
			string t = s.substr(i, 3);
			if (t == "cat" || t == "dog")
				ans++;
		}
		cout << ans << endl;

	}

















	return 0;
}