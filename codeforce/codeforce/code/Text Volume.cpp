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
int n;

int cale(string& s){
	int ret = 0;
	for (char c : s){
		if (isupper(c))
			ret++;
	}
	return ret;
}
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> n;
	string s;
	int ans = 0;
	while (in >> s){
		int t = cale(s);
		ans = max(ans, t);



	}

	cout << ans << endl;














	return 0;
}





