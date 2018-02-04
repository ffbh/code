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
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int n;


void input(){

	in >> n;

}

map<string, int> mii;
int size = 1;
vector<string> number[100];
string NAME[100];

bool idsuffix(string& a,string & b){
	return a == b.substr(b.length() - a.length());
}

vector<string> ch(int k){
	vector<string> ret;
	for (int i = 0; i < number[k].size(); ++i){
		bool ok = 1;
		for (int j = i + 1; j < number[k].size(); ++j){
			if (idsuffix(number[k][i], number[k][j])){
				ok = 0;
				break;
			}
		}
		if (ok){
			ret.push_back(number[k][i]);
		}
	}
	return ret;
}
bool cmp(string& a,string& b){
	return a.length() < b.length();
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		while (n-- > 0){
			string  name;
			int k;
			in >> name >> k;
			int idx;
			if (mii.count(name)){
				idx = mii[name];
			}
			else{
				idx = (mii[name] = size++);
			}
			NAME[idx] = name;
			for (int i = 0; i < k; ++i){
				string str;
				in >> str;
				number[idx].push_back(str);
			}
		}
		cout << size - 1 << endl;
		for (int i = 1; i < size; ++i){
			sort(number[i].begin(), number[i].end(), cmp);
			cout << NAME[i] << " ";
			vector<string> ans = ch(i);
			cout << ans.size() << " ";
			for (string s : ans){
				cout << s << " ";
			}
			cout << endl;


		}

		












	}


	return 0;
}





