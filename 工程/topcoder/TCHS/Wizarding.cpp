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

const int mod = 77077;

class Wizarding {
public:
	int max_val;
	string ans, tmp, s, r;
	void dfs(int pos,int val){
		if (pos == s.length()){
			if (tmp.length() == 0)
				return;
			if (val > max_val ||( val == max_val && ans.length() > tmp.length()) ||
				(val == max_val && ans.length() == tmp.length() && tmp < ans)){
				max_val = val;
				ans = tmp;
			}
			return;
		}

		dfs(pos + 1, val);

		tmp.push_back(s[pos]);
		dfs(pos + 1, val * (s[pos] - 'A' + 1) % mod);
		tmp.pop_back();

		if (r[s[pos] - 'A'] != '-'){

			tmp.push_back(r[s[pos] - 'A']);
			dfs(pos + 1, val * (r[s[pos] - 'A'] - 'A' + 1) % mod);
			tmp.pop_back();

		}
	}

	string counterspell(string spell, string rules) {
		s = spell;
		r = rules;
		max_val = -1;
		tmp = "";
		ans = "";
		dfs(0, 1);
		return ans;


	}
};


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

















	return 0;
}





