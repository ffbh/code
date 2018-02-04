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
using namespace std;

int h[266];
int sign[4] = { 6, 8, 12, 16 };
string strs[] = { "3/8", "2/4", "3/4", "4/4" };
class CompositionTimeSignature {
public:

	int cale(string& s, int d){
		int pos = 0;
		int wa = 0;
		int tmp = 0;
		while (pos < s.length()){

			while (pos < s.length() && tmp < d){
				tmp += h[(int)s[pos]];
				pos++;
			}
			if (tmp > d){
				wa++;
			}
			tmp %= d;
		}
		return wa;

	}

	string getTimeSignature(string duration) {
		h['S'] = 1;
		h['E'] = 2;
		h['Q'] = 4;
		h['H'] = 8;
		h['W'] = 16;

		int sum = 0;
		for (int i = 0; i < duration.size(); ++i){
			sum += h[(int)duration[i]];
		}
		vector<int> ans;
		for (int i = 0; i < 4; ++i){
			if (sum % sign[i] == 0){
				ans.push_back(i);
			}
		}
		if (ans.size() == 0){
			return "?/?";
		}

		int mminnum = (1 << 29);
		int ret = -1;
		for (int i = 0; i < ans.size(); ++i){
			int number = cale(duration, sign[ans[i]]);
			if (number < mminnum){
				ret = ans[i];
				mminnum = number;
			}
		}


		return strs[ret];
	}
};



/*int main(){

	CompositionTimeSignature so;
	cout << so.getTimeSignature("EQHQQWEEHSEEQWQEHHEEQSQEQHESQSWQESQEWWSSHQWQHQWSQW") << endl;
















	return 0;
}
*/
