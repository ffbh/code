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
#define pci pair<char,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


string str;
void ch(vector<pci> & all){
	vector<pci> copy = all;
	all.clear();

	for (int i = 0; i < copy.size(); ++i){
		if (i == 0 || i == copy.size() - 1){
			copy[i].second--;
		}
		else{
			copy[i].second -= 2;
		}
	}

	for (pci p : copy){
		if (p.second <= 0){
			continue;
		}
		if (all.empty() || all.back().first != p.first){
			all.push_back(p);
		}
		else{
			all.back().second += p.second;
		}
	
	}


}

void input(){
	in >> str;


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		vector<pci> all;
		for (char c : str){
			if (all.empty() || c != all.back().first){
				all.push_back(mp(c,1));
			}
			else{
				all.back().second++;
			}
		}
		int ans = 0;
		while (all.size() > 1){
			ans++;
			ch(all);

		}

		cout << ans << endl;









	}


	return 0;
}





