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


class MaximumRange {
	public:
	int findMax(string s) {
		int a, b;
		a = b = 0;
		for (char p : s){
			if (p == '+')
				a++;
			else
				b++;
		}

		return max(a, b);







	}
};



#if DEBUG
int main(){
	
	MaximumRange so;
	cout<<so.findMax()<<endl;
















	return 0;
}
#endif

