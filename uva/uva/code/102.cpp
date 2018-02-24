#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int data[3][3];
char d[3];
int h[266];

int cale(){
	int sum = 0;
	for (int i = 0; i < 3; ++i){
		int ha = h[d[i]];
		for (int j = 0; j < 3;++j)
		if (ha != j)
			sum += data[i][j];
	}
	return sum;
}

string get(){
	string s = "";
	for (int i = 0; i < 3; ++i)
		s += d[i];
	return s;
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	h['B'] = 0;
	h['G'] = 1;
	h['C'] = 2;
	while (cin >> data[0][0]){
		cin >> data[0][1] >> data[0][2];
		for (int i = 1; i < 3;++i)
		for (int j = 0; j < 3; ++j)
			cin >> data[i][j];
		d[0] = 'B';
		d[1] = 'C';
		d[2] = 'G';
		int step = cale();
		string ans = get();
		while (next_permutation(d, d + 3)){
			int ret = cale();
			if (ret < step){
				step = ret;
				ans = get();
			}

		}
		cout << ans << " " << step << endl;
	}






	return 0;
}