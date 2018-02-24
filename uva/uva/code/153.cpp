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
int h[30];

long long gcd(long long a,long long b){
	if (b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

int cale(){	
	int th[30];
	int sum = 0;
	for (int i = 0; i < 30; ++i){
		sum += h[i];
		th[i] = h[i];
	}


	
}


int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	string str;
	while (in >> str && str != "#"){
		for (int i = 0; i < 30; ++i)
			h[i] = 0;
		for (int i = 0; i < str.length(); ++i){
			h[str[i] - 'a']++;
		}






	}

















	return 0;
}