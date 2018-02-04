#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;
string s;
string cc = "PGSAN";
int h[266];
char data[110][6];
int diff[110][110];
int size;
stringstream ss;
void add(){
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == ',' || s[i] == '/')
			s[i] = ' ';
	}
	ss.clear();
	ss.str(s);
	char a, b;
	for (int i = 0; i < 5; ++i){
		ss >> a >> b;
		data[size][h[b]] = a;
	}
	size++;

}

int getdifff(int a,int b){
	int num = 0;
	for (int i = 0; i < 5;++i)
	if (data[a][i] != data[b][i])
		num++;
	return num;
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	for (int i = 0; i < 5; ++i)
		h[cc[i]] = i;
	while (getline(in, s) && s != "#"){
		size = 0;
		add();
		while (getline(in, s) && s[0] != 'e'){
			add();
		}

		for (int i = 0; i < size;++i)
		for (int j = i + 1; j < size; ++j)
			diff[i][j] = diff[j][i] = getdifff(i, j);

		int mmin = 1 << 29, ans;
		for (int i = 0; i < size; ++i){
			int sum = 0;
			for (int k = 0; k < size; ++k){
				if (i != k)
					sum += diff[i][k];
			}
			if (sum < mmin){
				mmin = sum;
				ans = i + 1;
			}


		}

		cout << ans << endl;

	}















	return 0;
}