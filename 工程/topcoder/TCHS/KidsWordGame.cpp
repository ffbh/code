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


string run[200];
class KidsWordGame {
	public:
		bool judge(string& a,string& b){
			if (b.size() == a.size() + 1)
				return a == b.substr(1) || a == b.substr(0, b.size() - 1);
			else
				return 0;
		}


	int getCheater(vector <string> first, vector <string> second, vector <string> third) {
		int mmax = 0;
		for (int i = 0; i < first.size(); ++i){
			run[i * 3] = first[i];
			mmax = max(mmax, i * 3);
		}
		for (int i = 0; i < second.size(); ++i){
			run[i * 3 + 1] = second[i];
			mmax = max(mmax, i * 3 + 1);
		}
		for (int i = 0; i < third.size(); ++i){
			run[i * 3 + 2] = third[i];
			mmax = max(mmax, i * 3 + 2);
		}

		for (int i = 0; i < mmax; ++i){
			if (!judge(run[i], run[i + 1])){
				return i % 3 + 1;
			}
		}


		return -1;
	}
};

