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
const int pingnian = 65;
const int runnian = 66;

int day[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

int cale(int p){
	int ans = 0;
	while (p){
		if (p % 10 == 9)
			ans++;
		p /= 10;
	}
	return ans;
}

int T;
int a1, b1, c1, a2, b2, c2;

int dp[10010];

int month[2][13];
int ninemonth[2][13];
int ydp[10010];

bool isleap(int p){
	return p % 400 == 0 || p % 100 != 0 && p % 4 == 0;
}
int m[50];

void Init(){
	for (int i = 0; i < 10010; ++i)
		dp[i] = cale(i);
	int startyear = 1995;
	ydp[startyear] = 0;
	for (int i = startyear + 1; i < 10010; ++i){
		int num = dp[i];
		ydp[i] = ydp[i - 1];
		if (isleap(i)){
			ydp[i] += runnian;
			ydp[i] += num * 366;
		}
		else{
			ydp[i] += num * 365;
			ydp[i] += pingnian;
		}

	}

	month[0][1] = month[1][1] = 0;
	for (int i = 2; i <= 12; ++i){
		month[0][i] += month[0][i - 1] + day[0][i - 1];
		month[1][i] += month[1][i - 1] + day[1][i - 1];
	}
	m[0] = 0;
	for (int i = 1; i < 50; ++i)
		m[i] = m[i - 1] + dp[i];

	ninemonth[0][1] = ninemonth[1][1] = 0;
	for (int i = 2; i <= 12; ++i){
		if (i == 10){
			ninemonth[0][i] = ninemonth[0][i - 1] + m[day[0][i - 1]] + 30;
			ninemonth[1][i] = ninemonth[1][i - 1] + m[day[1][i - 1]] + 30;
		}
		else{
			ninemonth[0][i] = ninemonth[0][i - 1] + m[day[0][i - 1]];
			ninemonth[1][i] = ninemonth[1][i - 1] + m[day[1][i - 1]];
		}
	}

}

int getAns(int a, int b, int c){


	int num;
	bool leap = isleap(a);
	int ans = ydp[a - 1];
	int ynum = dp[a];
	//	int y_num = 0;
	int y_num = month[leap][b];
	ans += ninemonth[leap][b];

	/*for (int i = 1; i < b; ++i){
	num = dp[i];
	for (int j = 1; j <= day[leap][i]; ++j){
	ans += dp[j];
	}
	y_num += day[leap][i];
	ans += num * day[leap][i];
	}*/

	int mnum = dp[b];
	int m_num = 0;
	for (int i = 1; i <= c; ++i)
		ans += dp[i];
	y_num += c;

	m_num = c;
	return ans + y_num*ynum + m_num*mnum;
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	Init();
	while (T-- > 0){
		//in >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
		int ans = getAns(a2, b2, c2) - getAns(a1, b1, c1);
		ans += dp[c1] + dp[b1] + dp[a1];
		printf("%d\n", ans);

	}

	return 0;
}