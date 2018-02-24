#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <sstream>
using namespace std;
stringstream ss;

long long mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

bool leap(int year){
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


bool r[3000][2];

void InitR(){
	memset(r, 0, sizeof(r));
	r[1972][0] = r[1972][1] = 1;
	for (int i = 1973; i <= 1979; ++i)
		r[i][1] = 1;
	for (int i = 1981; i <= 1983; ++i)
		r[i][0] = 1;
	r[1985][0] = 1;
	r[1987][1] = 1;
	r[1989][1] = r[1990][1] = 1;
	for (int i = 1992; i <= 1994; ++i)
		r[i][0] = 1;
	r[1995][1] = 1;
	r[1997][0] = 1;
	r[1998][1] = 1;
	r[2005][1] = 1;
	r[2008][1] = 1;
	r[2012][0] = 1;
	r[2015][0] = 1;
	r[2016][1] = 1;
}



long long getDayTime(string s){
	ss.clear();
	ss.str(s);
	long long h = 0, m = 0, se = 0;
	/*for (int i = 0; i <= 1; ++i)
		h = h * 10 + s[i] - '0';
	for (int i = 3; i <= 4; ++i)
		m = m * 10 + s[i] - '0';
	for (int i = 6; i <= 7; ++i)
		se = se * 10 + s[i] - '0';*/
	ss >> h >> m >> se;
	return h * 60 * 60 + m * 60 + se;

}

long long getTime(string& s1, string& s2){
	ss.clear();
	ss.str(s1);
	
	long long year = 0, month = 0, day = 0;
/*	for (int i = 0; i <= 3; ++i)
		year = year * 10 + s1[i] - '0';
	for (int i = 5; i <= 6; ++i)
		month = month * 10 + s1[i] - '0';
	for (int i = 8; i <= 9; ++i)
		day = day * 10 + s1[i] - '0';*/
	ss >> year >> month >> day;
	long long  sum = 0;
	long long sumday = 0;
	for (int i = 1969; i < year; ++i){
		sum += (leap(i) + 365)*24*60*60;
		sumday += leap(i) + 365;
	}
	for (int i = 1; i < month; ++i){
		sumday += mon[leap(year)][i];
		sum += mon[leap(year)][i] * 24 * 60 * 60;
	}
	sumday += day - 1 ;

	//cout << sumday << endl;

	sum += (day - 1) * 24 * 60 * 60;
	sum += getDayTime(s2);
	long long rnum = 0;
	for (int i = 1969; i < year; ++i){
		if (r[i][0]){
			rnum++;
			sum++;
		}
		if (r[i][1]){
			rnum++;
			sum++;
		}
	}
	if (month > 6 && r[year][0]){
		rnum++;
		sum++;
	}
	//cout << rnum << endl;
	return sum;
}

void cc(string& s){
	for (int i = 0; i < s.length();++i)
	if (s[i] == '-' || s[i]==':')
		s[i] = ' ';
}

int main(){
	ifstream in("C:\\input.txt");
	InitR();
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	cc(s1);
	cc(s2);
	cc(s3);
	cc(s4);
	long long a = getTime(s1, s2);
	long long b = getTime(s3, s4);
	cout << abs(b-a) << endl;
	


	return 0;
}