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
int k;
string s;
int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> k >> s;
	int sum = 0;
	sort(s.begin(), s.end());
	for (char c : s)
		sum += (c - '0');
	if (sum >= k){
		cout << 0 << endl;
	}
	else{
		int need = k - sum;
		int ans = 0;
		for (char c : s){
			ans++;
			int d = c - '0';
			d = 9 - d;
			need -= d;
			if (need <= 0)
				break;
		}
		cout << ans << endl;
	}















	return 0;
}





