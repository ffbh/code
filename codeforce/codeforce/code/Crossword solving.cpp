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
string s, t;
vector<int> ans;
int mmin;

void cale(){
	mmin = 111111111;
	for (int i = 0; i + s.length() - 1 < t.length(); ++i){
		vector<int> tmp;
		for (int j = 0; j < s.length(); ++j){
			if (s[j] != t[i + j]){
				tmp.push_back(j+1);
			}
		}

		

		if (tmp.size() < mmin){
			mmin = tmp.size();
			ans = tmp;
		}
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int n, m;
	in >> n >> m;
	in >> s >> t;
	cale();
	cout << ans.size() << endl;
	for (int a : ans)
		cout << a << " ";
	cout << endl;
















	return 0;
}





