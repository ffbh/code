#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
#define MMAX 1000000
bool SG[MMAX];
int data[7];
int getmin(int n, int len){
	int base = int(pow(10, 6 - len));
	return n*base;
}

int getmax(int n,int len){
	int base = int(pow(10, 6 - len));
	return n*base + base/10 - 1;
}


void Init(){
	SG[0] = 1;
	for (int i = 0; i < MMAX;++i)
	if (!SG[i]){
		int temp = i;
		int len = 0;
		while (temp){
			data[len++] = temp % 10;
			temp /= 10;
		}
		int base;
		for (int j = 0; j < len; ++j){
			temp = i;
			base = int(pow(10, j));
			for (int k = data[j]; k < 9; ++k){
				temp += base;
				SG[temp] = 1;
			}
		}
		while (len < 6){
			int min = getmin(i, len);
			int max = getmax(i, len);
			for (int k = min; k <= max; ++k)
				SG[k] = 1;
			len++;
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	Init();
	string s;
	while (cin >> s){
		if (s[0] == '0')
			printf("Yes\n");
		else{
			int N = 0;
			for (int i = 0; i < s.length(); ++i)
				N = N * 10 + s[i] - '0';
			if (SG[N]) printf("Yes\n");
			else  printf("No\n");
		}
	}
	return 0;
}