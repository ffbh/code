#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <ctime>
using namespace std;
void stringhandle(string& s){
	for (int i = 0; i < s.length();++i)
	if (s[i]<'0' || s[i]>'9')
		s[i] = ' ';
}
int leap[2][13] = {
	{0,0,31,28,31,30,31,30,31,31,30,31,30},
	{0,0,31,29,31,30,31,30,31,31,30,31,30}
};

bool isLeap(int year){
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dp[50010];
void Init(){
	for (int i = 1; i < 50010; ++i){
		if (isLeap(i - 1))
			dp[i] = dp[i - 1] + 366;
		else
			dp[i] = dp[i - 1] + 365;
	}
	for (int i = 1; i < 13; ++i){
		leap[0][i] += leap[0][i - 1];
		leap[1][i] += leap[1][i - 1];
	}

}



int main(){
	ifstream in("C:\\input.txt");
	Init();
	int N;
	string t;
	stringstream ss;
	int h, m, s, d, y, sum;
	const double p = double(100000) / (3600 * 24);
	cin >> N;
	while (N--){	
		cin >> t;
		stringhandle(t);
		ss.clear();
		ss.str(t);
		ss >> h >> m >> s;
		sum = int(p*(h * 3600 + m * 60 + s));
		h = sum / 10000;
		sum %= 10000;
		m = sum / 100;
		sum %= 100;
		s = sum;
		printf("%d:%d:%d ", h, m, s);

		cin >> t;
		stringhandle(t);
		ss.clear();
		ss.str(t);
		ss >> d >> m >> y;
		y -= 2000;
		sum = dp[y] + leap[isLeap(y)][m] + d;
		sum = sum + 100 ;
		if (sum % 100 == 0){
			d = 100;
			sum -= 100;
		}
		else{
			d = sum % 100;
			sum -= d;
		}
		sum /= 100;
		if (sum % 10 == 0){
			m = 10;
			sum -= 10;
		}
		else{
			m = sum % 10;
			sum -= m;
		}
		sum /= 10;
		y = sum;
		printf("%d.%d.%d\n", d, m, y);
	}



	return 0;
}