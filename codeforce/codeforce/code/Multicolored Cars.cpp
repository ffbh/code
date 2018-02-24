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
unordered_map<int, int> usi;
unordered_map<int, int>::iterator it;
int N, C;
vector<int> vi;

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N >> C;
	vi.clear();
	for (int i = 1; i <= N; ++i){
		int a;
		in >> a;
		vi.push_back(a);
	}
	
	bool f = 0;
	for (int p : vi){
		if (p == C){
			f = 1;
			it = usi.begin();
			while (it != usi.end()){
				if (it->second == 0){
					it = usi.erase(it);
				}
				else{
					it->second--;
					it++;
				}
			}
		}
		else{
			if (f){
				if (usi.count(p))
					usi[p]++;
			}
			else{
				usi[p]++;
			}
		}
	}

	if (usi.empty())
		cout << -1 << endl;
	else
		cout << usi.begin()->first << endl; 




	return 0;
}





