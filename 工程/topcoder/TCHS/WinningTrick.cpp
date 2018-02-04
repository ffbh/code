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



class WinningTrick {
	public:
	double minimumSpeed(vector <int> speed, int yourSpeed) {
		int mmax = 0;
		for (int i = 0; i < speed.size(); ++i)
			mmax = max(mmax, speed[i]);
		if (mmax <= yourSpeed){
			return 0;
		}
		else{
			return (mmax - yourSpeed) / 2.0;
		}

	}
};




