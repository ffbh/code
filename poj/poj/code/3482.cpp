#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
long long cale(vector<int> s, int base){
	long long  sum = 0;
	for (int i = 0; i < s.size(); ++i)
		sum = sum*base + s[i];
	return sum;
}


int main(){
	ifstream in("C:\\input.txt");
	map<char, int> mci;
	string s = "";
	vector<int> vi;
	while (getline(cin, s)){
		if (s.length()==0)
			while (getline(cin, s) && s.length() == 0);
		mci.clear();
		int maxbase = 0;
		for (int i = 0; i < s.length(); ++i)
			mci[s[i]] = maxbase++;
		while (getline(cin, s) && s.length() != 0){
			long long  ans = 0;
			int minbase = 1;
			vi.clear();
			for (int i = 0; i < s.length();++i)
			if (s[i] >' '){
				int num = mci[s[i]];
				vi.push_back(num);
				if (minbase < num)
					minbase = num;
			}
			minbase++;
			for (int i = minbase; i <= maxbase; ++i)
				ans += cale(vi, i);
			cout << ans << endl;
		}
		cout << endl;
	}
	return 0;
}