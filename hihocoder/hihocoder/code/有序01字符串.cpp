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
//ifstream in("C:\\input.txt");
istream& in = cin;
string s;
int a[1010], b[1010], N;


void input(){
	
	//in >> s;


}


int main(){
	input();
	int T;
	in >> T;
	while (T-->0){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		in >> s;
		s = '-' + s;

		N = s.length() - 1;

		for (int i = 1; i <= N; ++i)
			a[i] = a[i - 1] + (s[i] == '1');

		for (int i = N; i >= 1; --i)
			b[i] = b[i + 1] + (s[i] == '0');
		int ans = N;
		for (int i = 0; i <= N; ++i)
			ans = min(ans, a[i] + b[i + 1]);




		cout << ans << endl;

	}









	return 0;
}





