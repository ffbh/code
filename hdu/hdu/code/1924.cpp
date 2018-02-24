#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;
map<char, int> mci;
const char FF[4][2] = {
	'I', 'V',
	'X', 'L',
	'C', 'D',
	'M'
};

int GetV(const string& s){
	int temp[100];
	for (int i = 0; i < s.length(); ++i)
		temp[i] = mci[s[i]];
	for (int i = 0; i < s.length() - 1; ++i)
	if (mci[s[i]] < mci[s[i + 1]])
		temp[i] = -temp[i];
	int res = 0;
	for (int i = 0; i < s.length(); ++i)
		res += temp[i];
	return res;
}



string GetRM(int n){
	string res = "";
	int time = n / 1000;
	n %= 1000;
	for (int i = 0; i < time; ++i)
		res += 'M';
	for (int k = 2; k >= 0; --k){
		int MOD = int(pow(10, k));
		time = n / MOD;
		n %= MOD;
		if (time <= 3)
		for (int i = 0; i < time;++i)
			res += FF[k][0];
		else if (time == 4){
			res += FF[k][0];
			res += FF[k][1];
		}
		else if (time <= 8){
			res += FF[k][1];
			for (int i = 5; i < time; ++i)
				res += FF[k][0];
		}
		else{
			res += FF[k][0];
			res += FF[k + 1][0];
		}
	}
	return res;
}


int main(){
	ifstream in("C:\\temp.txt");
	mci['I'] = 1;
	mci['V'] = 5;
	mci['X'] = 10;
	mci['L'] = 50;
	mci['C'] = 100;
	mci['D'] = 500;
	mci['M'] = 1000;
	int N;
	int CASE = 1;
	while (cin >> N&&N){
		int sum = 0;
		string s;
		while (N--){
			cin >> s;
			sum += GetV(s);
		}
		printf("Case %s: %s\n", GetRM(CASE++).c_str(), GetRM(sum).c_str());
	}
	return 0;
}