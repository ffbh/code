#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;


int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int t;
	multiset<int> mi;
	while (cin >> N){
		mi.clear();
		string temp;
		while (N--){
			cin >> temp >> t;
			if (temp[1] == 'u')
				mi.insert(t);
			else{
				multiset<int>::iterator it = mi.lower_bound(t);
				if (*it == t){
					cout << t << endl;
					mi.erase(it);
				}
				else if (it != mi.begin()){
					it--;
					cout << *it << endl;
					mi.erase(it);
				}
				else
					cout << "No Element!" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}