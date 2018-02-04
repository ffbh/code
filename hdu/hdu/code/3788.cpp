#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("C:\\input.txt");
	string s;
	bool ans;
	int z, j;
	while (cin >> s){
		ans = 1;
		z = j = -1;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == 'z'){
				if (z == -1)
					z = i;
				else{
					ans = 0;
					break;
				}
			}
			if (s[i] == 'j'){
				if (j == -1 && z != -1)
					j = i;
				else{
					ans = 0;
					break;
				}
			}
		}

		if (ans){
			int a, b, c;
			a = z;
			c = s.length() - j - 1;
			b = s.length() - a - c - 2;
			ans = (b != 0 && a*b == c);
		}
		

		if (ans)
			cout << "Accepted" << endl;
		else
			cout << "Wrong Answer" << endl;
	}

	return 0;
}