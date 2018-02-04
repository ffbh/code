#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
int A[30];
int B[30];


int main(){
	//ifstream in("C:\\temp.txt");
	map<char, int> mci;
	for (char c = '2'; c <= '9'; ++c)
		mci[c] = c - '0';
	mci['T'] = 11;
	mci['J'] = 12;
	mci['Q'] = 13;
	mci['K'] = 14;
	mci['A'] = 15;
	mci['C'] = 1;
	mci['D'] = 2;
	mci['S'] = 3;
	mci['H'] = 4;
	int T;
	cin >> T;
	while (T--){
		int M;
		cin >> M;
		for (int i = 0; i < M; ++i){
			string s;
			cin >> s;
			A[i] = mci[s[0]] * 10 + mci[s[1]];
		}
		for (int i = 0; i < M; ++i){
			string s;
			cin >> s;
			B[i] = mci[s[0]] * 10 + mci[s[1]];
		}
		sort(A, A + M);
		sort(B, B + M);
		int num = 0;
		int R = 0;
		for (int i = 0; i < M; ++i){
			while (R < M){
				if (A[i] < B[R]){
					num++;
					R++;
					break;
				}
				R++;
			}
		}
		cout << num << endl;

	}
	return 0;
}