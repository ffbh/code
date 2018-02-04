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



class BestSeller {
	public:
	string findBestSeller(vector <string> items) {
		unordered_map<string,int > usi;
		for (int i = 0; i < items.size(); ++i)
			usi[items[i]]++;
		int num = 0;
		string ans;

		unordered_map<string, int >::iterator it = usi.begin();
		while (it != usi.end()){
			if (it->second > num){
				num = it->second;
				ans = it->first;
			}
			else if (it->second == num){
				ans = min(ans, it->first);
			}
			it++;
		}

		return ans;






	}
};




