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



class ProductsMatrix {
public:
		long long cale(long long n,long long mid){
			long long sum = 0;
			for (int i = 1; i <= n; ++i){
				long long num = mid / i;
				if (num > n)
					num = n;
				sum += num;
			}
			return sum;
		}

		long long nthElement(int n, int k) {
			long long L = 1, R = ((long long)n) * n;

			while (L <= R){
				long long mid = (L + R) / 2;
				long long lf = cale(n, mid - 1);
				long long rg = cale(n, mid);
				if (lf < k&&rg >= k){
					return mid;
				}
				else if (rg<k){
					L = mid + 1;
				}
				else{
					R = mid - 1;
				}
			}
			return -1;

		}
};



/*int main(){
	
	ProductsMatrix so;
	cout<<so.nthElement(1e5,1e8)<<endl;
	cout << so.nthElement(1e5, 1e9) << endl;















	return 0;
}
*/



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
