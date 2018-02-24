#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

int array[5];
int index;
long long n;



char fun(int n){
	return char(n + 64);
}


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int p[20];

	while (cin >> n >> s&&n){

		memset(p, 0, 20 * sizeof(int));
		index = 0;
		vector<char> v(s.begin(), s.end());
		int size = v.size();
		bool f = false;
		for (int i = 0; i < size; ++i)
			p[i] = v[i] - 64;
		sort(p, p + 20, greater<int>());
		for (int a = 0; a < size; ++a)
		for (int b = 0; b < size; ++b)
		if (b != a)
		for (int c = 0; c < size; ++c)
		if (c != a&&c != b)
		for (int d = 0; d < size; ++d)
		if (d != a&&d != b&&d != c)
		for (int e = 0; e < size; ++e){
			if (e != a&&e != b&&e != c&&e != d)
			if (p[a]
				- p[b] * p[b]
				+ p[c] * p[c] * p[c]
				- p[d] * p[d] * p[d] * p[d]
				+ p[e] * p[e] * p[e] * p[e] * p[e] == n
				){

				cout << fun(p[a]) << fun(p[b]) << fun(p[c])
					<< fun(p[d]) << fun(p[e]) << endl;
				f = true;
				goto win;


			}
		}
	win:
		if (!f) cout << "no solution" << endl;

	}
	return 0;
}