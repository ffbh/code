#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
string mm[13] = { "", "January", "February", "March", "April", "May",
"June", "July", "August", "September", "October", "November", "December" };

string xx[8] = { "","Monday", "Tuesday", "Wednesday", "Thursday",
"Friday", "Saturday", "Sunday" };
int oldy[2200];
int newy[2200];
map<string, int> mmp, xxp;
int month[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
					{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

bool leap(int y){
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

bool add(int p){
	return p % 100 == 0 && p % 400 != 0;
}


void Init(){
	oldy[1] = newy[1] = 0;
	for (int i = 2; i < 2200; ++i){
		if (leap(i - 1)){
			newy[i] = newy[i - 1] + 366;
		}
		else{
			newy[i] = newy[i - 1] + 365;
		}

		if ((i - 1) % 4 == 0){
			oldy[i] = oldy[i - 1] + 366;

		}
		else{
			oldy[i] = oldy[i - 1] + 365;
		}
	}

	for (int i = 1; i <= 12; ++i){
		mmp[mm[i]] = i;
	}
	for (int i = 1; i <= 7; ++i)
		xxp[xx[i]] = i;
	


}



int getNew(int y,int m,int d){
	int sum = newy[y];

	bool p = leap(y);
	for (int i = 1; i < m; ++i)
		sum += month[p][i];
	sum += d;
	return sum;
}

int getOld(int y, int m, int d){
	int sum = oldy[y];

	bool p = (y % 4 == 0) ? 1 : 0;
	for (int i = 1; i < m; ++i)
		sum += month[p][i];
	sum += d;
	return sum;
}
ofstream ou("C:\\input2.txt");

void caleOld(int sum){
	
	int y, m, d;
	for (int i = 1588; i <2200;++i)
	if (sum < oldy[i]){
		y = i - 1;
		sum -= oldy[i - 1];
		break;
	}
	if (sum == 0){
		y--;
		sum = 365 + (y % 4 == 0);;
	}
	bool p = (y % 4 == 0) ? 1 : 0;
	for (int i = 1; i <= 12; ++i){
		if (sum <= month[p][i]){
			m = i;
			break;
		}
		sum -= month[p][i];
	}
	d = sum;
	cout <<  d << "*" << " " << mm[m] << " " << y << endl;
	ou << d << "*" << " " << mm[m] << " " << y << endl;

}


void caleNew(int sum){


	int y, m, d;
	for (int i = 1588; i <2200; ++i)
	if (sum < newy[i]){
		y = i - 1;
		sum -= newy[i - 1];
		break;
	}
	if (sum == 0){
		y--;
		sum = 365 + leap(y);
	}
	bool p = leap(y);
	for (int i = 1; i <= 12; ++i){
		if (sum <= month[p][i]){
			m = i;
			break;
		}
		sum -= month[p][i];
	}
	d = sum;
	cout << d  << " " << mm[m] << " " << y << endl;
	ou << d << " " << mm[m] << " " << y << endl;




}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string xingqi, yuefen;
	int year, day, mon;
	Init();
	//cout << getNew(1582, 10, 15) << endl;
	//cout << getOld(1582, 10, 5) << endl;

	//cout << getNew(1666, 12, 31) << endl;
	//caleOld(608492);
	//cout << getNew(1992, 8, 29) << endl;
	//cout << getOld(1992, 8, 16) << endl;


	while (in >> xingqi && xingqi != "#"){
		in >> day >> yuefen >> year;
		mon = mmp[yuefen];
		int sum = getNew(year, mon, day) ;
		int r = sum % 7;
		if (r == 0){
			r = 7;
		}
	/*	int chazhi = cd[year];
		if (add(year) && (mon > 2 || mon == 2 && day == 29)){
			chazhi++;
		}*/
		cout << xingqi << " ";
		ou << xingqi << " ";
		if (xx[r] == xingqi){
			sum += 2;
			caleOld(sum);
		}
		else{
			sum = getOld(year, mon, day);
			sum -= 2;
			caleNew(sum);
		}

	}



	return 0;
}