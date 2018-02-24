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


class Divisibility {
public:
	vector<int> A;
	long long gcd(long long a,long long b){	
		if (b == 0)
			return a;
		else{
			long long d = a%b;
			return gcd(b, d);
		}
	}
	long long lim(long long a,long long b){
		if (a>1e10||b>1e10)
			return 1e10;
		long long g = gcd(a, b);
		return a*b / g;
	}

	long long getLim(int code){
		long long ans = 1;
		int p = -1;
		for (int i = 0; i < A.size(); ++i){
			if (code & (1 << i)){
				p = -p;
				ans = lim(ans, A[i]);
			}
		}
		return ans * p;
	}

	int numDivisible(int L, int R, vector <int> a) {
		A = a;
		int ans = 0;
		for (int i = 1; i < (1 << a.size()); ++i){
			long long ret = getLim(i);
			ans += (R / ret) - ((L - 1) / ret);
		}
		return ans;
	}
};



#if DEBUG
int main(){
	
	vector<int> p({ 1 });
	Divisibility so;
	cout<<so.numDivisible(293,784,p)<<endl;
















	return 0;
}
#endif

