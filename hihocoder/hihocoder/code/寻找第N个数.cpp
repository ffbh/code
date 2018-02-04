#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
long long dp[20];
long long Pow(int n){
	long long ans = 1;
	for (int i = 1; i < n; ++i)
		ans *= 10;
	return ans;
}
void Init(){
	dp[1] = 9;
	long long x = 90;
	for (int i = 2; i <= 20; ++i){
		dp[i] = dp[i - 1] + x*i;
		x *= 10;
	}
}

int getAns(long long tar, int mod){
	string temp = "";
	while (tar){
		temp += tar % 10+'0';
		tar /= 10;
	}
	temp = string( temp.rbegin(),temp.rend());
	return temp[mod] - '0';
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	long long x;
	cin >> x;
	if (x <= 9){
		cout << x << endl;
		return 0;
	}
	int len = 1;
	while (dp[len] < x)
		len++;
	x -= dp[len - 1];
	long long div = (x-1) / len;
	div += Pow(len);
	int mod = (x-1) % len;
	cout << getAns(div, mod) << endl;


	return 0;
}