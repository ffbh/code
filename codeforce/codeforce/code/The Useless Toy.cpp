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
char c[] = { 'v', '<', '^', '>' };
char a, b;
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int n;
	in >> a >> b >> n;
	n %= 4;
	int spos, epos;
	for (int i = 0; i < 4; ++i){
		if (a == c[i]){
			spos = i;
		}
		if (b == c[i]){
			epos = i;
		}

	}
	if (n == 0 || n == 2){
		cout << "undefined" << endl;
	}
	else if (n == 1){
		if ((spos + 1) % 4 == epos){
			cout << "cw" << endl;
		}
		else{
			cout << "ccw" << endl;
		}

	}
	else{
		if ((spos + 3) % 4 == epos){
			cout << "cw" << endl;
		}
		else{
			cout << "ccw" << endl;
		}
	}





	return 0;
}





