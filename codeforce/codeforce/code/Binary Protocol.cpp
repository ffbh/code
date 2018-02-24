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
using namespace std;

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int N;
	in >> N;
	string s;
	in >> s;
	int pos = 0;
	while (pos < s.length()){
		int num = 0;
		while (pos < s.length() && s[pos] == '1'){
			pos++;
			num++;
		}
		cout << num;
		pos++;
	}
	if (s.back() == '0')
		cout << 0;
	cout << endl;














	return 0;
}





