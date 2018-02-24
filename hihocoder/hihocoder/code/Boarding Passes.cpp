#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
int inNum[210], outNum[210];
string ans[210];
int main(){
	//ifstream in("C:\\input.txt");
	map<string, int> msi;
	int size = 0;
	int N;
	cin >> N;
	while (N--){
		string s;
		cin >> s;
		int id;
		if (!msi.count(s)){
			id = size;
			ans[size] = s;
			msi[s] = size++;
		}
		else
			id = msi[s];
		outNum[id]++;

		cin >> s;
		if (!msi.count(s)){
			id = size;
			ans[size] = s;
			msi[s] = size++;
		}
		else
			id = msi[s];
		inNum[id]++;

	}
	for (int i = 0; i < size;++i)
	if (inNum[i] < outNum[i]){
		cout << ans[i] << " ";
		break;
	}

	for (int i = 0; i < size; ++i)
	if (inNum[i] > outNum[i]){
		cout << ans[i] << endl;
		break;
	}












	return 0;
}