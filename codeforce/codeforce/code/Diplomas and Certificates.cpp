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
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	long long n, k;
	in >> n >> k;
	long long a, b, c;
	a = n/2 / (k + 1);
	b = a*k;
	c = n - a - b;
	cout << a << " " << b << " " << c << endl;
















	return 0;
}





