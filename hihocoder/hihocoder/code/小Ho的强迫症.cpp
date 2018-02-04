#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int gcd(int a, int b){
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}


bool cale(int l, int f, int d){
	int g = gcd(l, d);
	if ( g < f)
		return 0;
	return 1;

}

int main(){
	ifstream in("C:\\input.txt");
	int L, F, D, T;
	cin >> T;
	while (T-- > 0){
		cin >> L >> F >> D;
		if (cale(L, F , D))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}


	return 0;
}