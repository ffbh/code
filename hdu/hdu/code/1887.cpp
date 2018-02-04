#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int getMod(int N, int R){
	int div = N / R;
	if (div*R > N)
		div++;
	return N - div*R;
}


int main(){
	//ifstream in("C:\\temp.txt");
	//ofstream on("C:\\temp2.txt");

	string s;
	int R, N;
	stringstream ss;
	while (cin >> s&&s != "end"){
		for (int i = 0; i < s.length();++i)
		if (s[i] == '-')
			s[i] = ' ';
		ss.clear();
		ss.str(s);
		ss >> s >> R;
		R = -R;
		if (s == "from"){
			int ans = 0;
			cin >> s;
			for (int i = 0; i < s.length(); ++i)
				ans = ans * R + s[i] - '0';
			cout << ans << endl;
		}
		else{
   			cin >> N;
			if (N){
				int m = N;
				string ans;
				int mod;
				while ( N){
					mod = getMod(N, R);
					N -= mod;
					N = N / R;
					ans += char(mod + '0');
				}
				for (int i = ans.length() - 1; i >= 0; --i)
					cout << ans[i];
				cout << endl;
			}
			else
				cout << 0 << endl;
		}
	}
	return 0;
}