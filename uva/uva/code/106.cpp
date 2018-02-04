#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;
vector<long long> prime;
#define MMAX (1000010)
bool vis[MMAX];

void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j+=i)
				vis[j] = 1;
		}
	}
}

unordered_set<long long> ssi;

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	Init();
	
	for (int i = 1; i < 100; ++i)
		ssi.insert(i*i);

	for (int i = 1; i < 100;++i)
	for (int j = i + 1; j < 100; ++j){
		if (ssi.count(i*i + j*j)  )
			cout << i << " " << j << " " << (int)sqrt(i*i + j*j) << endl;

	}














	return 0;
}