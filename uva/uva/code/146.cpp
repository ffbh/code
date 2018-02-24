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

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s;
	while (in >> s&&s != "#"){
		if (next_permutation(s.begin(), s.end())){
			cout << s << endl;
		}
		else{
			cout << "No Successor" << endl;
		}
	}
















	return 0;
}