#include <iostream>
#include <map>
#include <fstream>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	map<int, int> mii;
	while (cin >> N&&N){
		int t;
		for (int i = 0; i < N; ++i){
			//in >> t;
			scanf("%d", &t);
			mii[t]++;
		}
		cin >> t;
		cout << mii[t] << endl;
		mii.clear();
	
	}

	return 0;
}