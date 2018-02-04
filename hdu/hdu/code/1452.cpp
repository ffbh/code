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
vector<int> vi;
bool judge(int p){
	for (int i = 2; i <= sqrt(p);++i)
	if (p%i == 0)
		return 0;
	return 1;
}

int num[3];
void Init(){
	num[0] = 2;
	num[1] = num[2] = 1;
}
const int mod = 29;
int qm(int a, int p){
	a %= 29;
	int ret = 1;
	while (p){
		if (p & 1)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;

	}
	return ret;
}

int main(){
	ifstream in("C:\\input.txt");
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(167);
	int X;
	while (cin >> X&&X){
		Init();
		for (int i = 0; i < 3; ++i)
			num[i] *= X;
		int ans = 1;
		for (int i = 0; i < 3; ++i){
			ans = ans * ((qm(vi[i], num[i] + 1) - 1)*qm(vi[i] - 1, mod - 2)) % mod;
		}
		cout << ans << endl;

	}




















	return 0;
}