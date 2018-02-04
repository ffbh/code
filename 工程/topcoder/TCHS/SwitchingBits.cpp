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



class SwitchingBits {
	public:
	int minSwitches(vector <string> word) {
		string str = "";
		for (int i = 0; i < word.size(); ++i)
			str += word[i];
		int a, b;
		a = b = 0;
		int pos = 0;
		while (pos < str.size()){
			char now = str[pos];
			while (pos < str.size() && now == str[pos]){
				pos++;
			}
			if (now == '0'){
				a++;
			}
			else{
				b++;
			}
		}
		return min(a, b);


	}
};



/*int main(){
	
	SwitchingBits so;
	//cout<<so.minSwitches()<<endl;
















	return 0;
}

*/
