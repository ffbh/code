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
long long mod = 1e9 + 7;

class ParenthesisRemoval {
public:
	int countWays(string s) {
		long long ans = 1;
		long long num = 0;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == '(')
				num++;
			else{
				ans = ans*num%mod;
				num--;
			}

		}

		return (int)ans;






	}
};


#if 0
int main(){
	





	ParenthesisRemoval so;
	cout<<so.countWays("")<<endl;


	return 0;
}
#endif




