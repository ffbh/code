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


	int mod = 10007;
class BestDecomposition {
	public:
	int maxProduct(int n) {
		if (n <= 4)
			return n;
		int ans = 1;
		int num = n / 3;
		if (n % 3 == 0){
			for (int i = 0; i < num; ++i)
				ans = (ans * 3) % mod;
		}
		else if (n % 3 == 1){
			for (int i = 0; i < num - 1;++i)
				ans = (ans * 3) % mod;
			ans = (ans * 4) % mod;
		}
		else{
			for (int i = 0; i < num; ++i){
				ans = (ans * 3) % mod;
			}
			ans = ans * 2 % mod;


		}



	
		
	
		return ans;
	}
};


