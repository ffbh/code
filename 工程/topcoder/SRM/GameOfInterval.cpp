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
#define DEBUG (0)


class GameOfInterval {
public:
	char get(int p){
		if (p <= 9)
			return '0' + p;
		p -= 10;
		return 'A' + p;
	}

	string ch(int p){
		string ret = "";
		ret += get(p / 36);
		ret += get(p % 36);
		return ret;
	}

	string construct(int n) {
		string ans = "";
		for (int k = 1; (1 << k) <= n; ++k){
			int len = 1 << k;
			for (int i = 0; i < n; i += len){
				ans += ch(i);
				ans += ch(i + len - 1);
			}
		}


		
		return ans;


	}
};



#if 1
int main(){
	
	GameOfInterval so;
	cout<<so.construct(81)<<endl;
















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
