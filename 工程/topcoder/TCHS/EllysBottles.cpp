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
#include <set>
using namespace std;
#define DEBUG (0)


class EllysBottles {
	public:
	double getVolume(vector <int> bottles, int k) {
		
		multiset<double> ss;
		for (int i = 0; i < bottles.size(); ++i){
			ss.insert(bottles[i]);
		}
		while (k-->0){
			double a = *ss.begin();
			double b = *(--ss.end());
			if (fabs(a - b) < 1e-9){
				return a;
			}
			ss.erase(ss.begin());
			ss.erase(--ss.end());
			ss.insert((a + b)/ 2.0);
			ss.insert((a + b)/ 2.0);
		}
		

		return *ss.begin();
	}
};



#if 0
int main(){
	vector<int> p({ 42, 13, 17, 7, 22 });
	EllysBottles so;
	cout<<so.getVolume(p,8)<<endl;
















	return 0;
}
#endif

