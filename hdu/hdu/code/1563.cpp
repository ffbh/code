#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int k;
	map<int, int> mii;
	map<int, int>::iterator it;
	while (cin >> N&&N){
		mii.clear();
		for (int i = 0; i < N; ++i){
			scanf("%d", &k);
			mii[k]++;
		}
		for(it = mii.begin();;it++)
		if (it->second == 1){
			cout << it->first << endl;
			break;
		}
	
	
	}
	return 0;
}