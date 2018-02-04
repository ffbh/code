#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int N;
string name[20];
int ans[20];
unordered_map<string, int> usi;

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	bool f = 0;
	while (in >> N){
		if (f)
			cout << endl;
		f = 1;
		usi.clear();
		for (int i = 1; i <= N; ++i){
			in >> name[i];
			usi[name[i]] = i;
			ans[i] = 0;
		}

		for (int k = 1; k <= N; ++k){
			string str;
			int money;
			int m;
			in >> str >> money >> m;
			int gift = 0;
			if (m)
				gift = money / m;
			ans[usi[str]] -= gift*m;
			for (int i = 0; i < m; ++i){
				string t;
				in >> t;
				ans[usi[t]] += gift;
			}
		}

		for (int i = 1; i <= N; ++i)
			cout << name[i] << " " << ans[i] << endl;



	}
	return 0;
}