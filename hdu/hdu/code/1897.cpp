#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;



int main(){
	//ifstream in("C:\\temp.txt");
	multiset<int> si;
	multiset<int>::iterator it;
	int N, M, Y;
	int T;
	int CASE = 1;
	cin >> T;
	while (T--){
		printf("Case %d:\n", CASE++);
		si.clear();
		cin >> N >> M >> Y;
		while (N--){
			int t;
			//in >> t;
			scanf("%d", &t);
			si.insert(t);
		}
		while (M--){
			int  t;
		//	in >> t;
			scanf("%d", &t);
			it = si.lower_bound(t);
			if (it != si.end() && t + Y >= *it){
				printf("%d\n", *it);
				si.erase(it);
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}