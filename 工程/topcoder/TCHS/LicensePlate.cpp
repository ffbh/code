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
int h[266];
struct Node{
	int idx, num;
	Node(int a, int b){
		idx = a;
		num = b;
	}
};
vector<Node> tmp;
long long p[60];

char get(int n, int all){
	if (all == 10){
		return n + '0';
	}
	else if (all == 26){
		return 'A' + n;
	}
	else{
		if (n < 10)
			return n + '0';
		n -= 10;
		return 'A' + n;
	}
}

class LicensePlate {
public:
	string getPlate(string format, int n) {
		long long k = 1;
		tmp.clear();
		h['a'] = 36;
		h['u'] = 26;
		h['n'] = 10;
		for (int i = 0; i < format.size(); ++i){
			if (islower(format[i])){

				k *= h[(int)format[i]];
				if (k>n)
					k = (long long)n + 10;
				tmp.push_back(Node(i, h[(int)format[i]]));
			}
		}
		if (k <= n)
			return "";
		p[tmp.size()] = 1;
		for (int i = tmp.size() - 1; i >= 0; --i){
			p[i] = p[i + 1] * tmp[i].num;
			if (p[i]>n)
				p[i] = (long long)n + 10;
		}
		for (int i = 0; i < tmp.size(); ++i){

			format[tmp[i].idx] = get(n / p[i + 1], tmp[i].num);
			n %= p[i + 1];
		}

		return format;

	}
};


#if 0
int main(){
	LicensePlate so;
	cout << so.getPlate("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 2147483647) << endl;















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
