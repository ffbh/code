#pragma comment(linker,"/STACK:1024000000,1024000000")
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
const int MMAX = 1587000;
int num[MMAX];
void Init(){
	//long start = clock();
	for (int i= 1; i < MMAX; ++i){
		for (int j = i; j < MMAX; j += i)
			num[j]++;
		
	}
	//cout << clock() - start << endl;

}
int data[47] = { 2, 3, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24,
28, 30, 32, 33, 34, 36, 40, 42, 44, 48, 50, 54, 56, 60, 64,
72, 80, 84, 90, 96, 100, 108, 112, 120, 128, 144, 150, 160, 168, 180,
192, 200 };
int ans[100010];
int mmax = 0;
bool dfs(int dept,int sum){
	//cout << dept << endl;
	if (dept == 100001){
		return 1;
	}
	//mmax = max(mmax, dept);
	for (int i = 0; i < 47 ; ++i){
		if (num[sum + data[i]] == data[i]){
			ans[dept] = data[i];
			if (dfs(dept + 1, sum + data[i]))
				return 1;
		}
	}
	return 0;
}
int main(){
	ifstream in("C:\\input.txt");
	Init();
	dfs(1, 0);
	int N;
	while (cin >> N){
		for (int i = 1; i <= N; ++i)
			printf("%d ", ans[i]);
		cout << endl;
	}

/*	string s;
	stringstream ss;
	while (in >> s){
		for (int i = 0; i < s.length();++i)
		if (s[i] == ',')
			s[i] = ' ';
		ss.clear();
		ss.str(s);
		int t;
		while (ss >> t){
			mark[t] = 1;
		}
	}
	int num = 0;
	ofstream out("C:\\input2.txt");
	for (int i = 1; i <= 300;++i)
	if (mark[i]){
		num++;
		out << i << ",";
		if (num % 15 == 0)
			out << endl;

	}*/


	/*long start = clock();
	bool f = dfs(1, 0);
	if (f){
		ofstream out("C:\\input.txt");
		for (int i = 1; i <= 100000; ++i){
			out << ans[i] << ",";
			if (i % 15 == 0)
				out << endl;
		}
		out << endl;
		cout << "AC" << endl;
	}
	else
		cout << "NOAC" << endl;

	
	cout << clock() - start << endl;
	*/












	return 0;
}