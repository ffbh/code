#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
string ans[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday",
				"Friday","Saturday" };
int yearsum[1000010];
int monthsum[2][13];
int day[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
bool leap(int y){
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

void Init(){
	for (int i = 2; i < 1000010; ++i){
		if (leap(i - 1))
			yearsum[i] = yearsum[i - 1] + 366;
		else
			yearsum[i] = yearsum[i - 1] + 365;
	}

	for (int i = 2; i < 13; ++i){
		monthsum[0][i] = monthsum[0][i - 1] + day[0][i - 1];
		monthsum[1][i] = monthsum[1][i - 1] + day[1][i - 1];
	}
}
int y, m, d;
bool legel(){
	return m>0 && d > 0 && d <= day[leap(y)][m];
}

int main(){
	ifstream in("C:\\input.txt");
	Init();

	for (int i = 1; i <= 10000; ++i){
		bool ok = 1;
		int num = yearsum[2 + i] - yearsum[2];
		for (int j = 3; j + i < 1000010;++j)
		if (yearsum[j + i] - yearsum[j] != num){
			ok = 0;
			break;
		}
		if (ok){
			cout << i << endl;
			return 0;
		}
	}


	
	while (cin >> y >> m >> d){
		if (legel()){
			int sum = yearsum[y] + monthsum[leap(y)][m] + d;
			cout << ans[sum % 7] << endl;
		}
		else
			cout << "illegal" << endl;
	}
	return 0;
}