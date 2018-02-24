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
string s;


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	while (N-- > 0){
		cin >> s;
		bool ok = 0;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == '_'){
				i++;
				putchar(s[i] - 32);
			}
			else if (isupper(s[i])){
				putchar('_');
				putchar(s[i] + 32);
			}
			else{
				putchar(s[i]);
			}
		}
		cout << endl;
		
	}
















	return 0;
}