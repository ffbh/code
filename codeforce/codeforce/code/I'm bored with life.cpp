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
	long long a, b, ans = 1;
	in >> a >> b;
	a = min(a, b);
	for (int i = 1; i <= a; ++i)
		ans *= i;
	cout << ans << endl;














	return 0;
}





