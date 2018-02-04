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


class ConsecutiveOnes {
public:
	vector<int> get_binary(long long n){
		vector<int> ret;
		for (int i = 0; i < 63; ++i){
			ret.push_back(n % 2);
			n /= 2;
		}
		return ret;
	}

	int cale(vector<int> d){
		int ans = 0;
		int pos = 0;
		while (pos < d.size() && d[pos] == 0)
				pos++;
		while (pos < d.size()){
			int num = 0;
			while (pos < d.size() && d[pos] == 1){
				pos++;
				num++;
			}
			ans = max(ans, num);
			while (pos < d.size() && d[pos] == 0)
				pos++;
		}
		return ans;
	}

	long long get(long long n, int k) {
		vector<int> b = get_binary(n);
		if (cale(b) >= k)
			return n;
		for (int i = 0; i < k; ++i)
			b[i] = 1;
		int del = 0;
		for (int i = k; i < 63; ++i){
			if (b[i] == 0)
				break;
			del++;
		}
		for (int i = 0; i < del; ++i)
			b[i] = 0;
		long long ans = 0;
		for (int i = 62; i >= 0; --i){
			ans = ans * 2 + b[i];
		}
		return ans;


	}
};


#if 0
int main(){
	





	ConsecutiveOnes so;
	cout<<so.get(1,2)<<endl;


	return 0;
}
#endif




