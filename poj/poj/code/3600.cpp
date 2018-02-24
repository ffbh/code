#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

bool A[21][21], B[21][21];
int markA[21], markB[21];
int N, M, X, Y;	
int n1, m1, n2, m2;
bool judge(){
	for (int i = 1; i < n1;++i)
	for (int j = 1; j < m1;++j)
	if (A[i][j] != B[markB[i]][markA[j]])
		return 0;
	return 1;
}
bool dfsX(int x, int mX){
	if (x == n1){
		return judge();
	}
	for (int i = mX; i < n2; ++i)
	if (A[x][0] == B[i][Y]){
		markB[x] = i;
		if (dfsX(x + 1, i + 1))
			return 1;
	}
	return 0;
}

bool dfsY(int y, int mY){
	if (y == m1){
		return dfsX(1, X + 1);
	}
	for (int i = mY; i < m2;++i)
	if (A[0][y] == B[X][i]){
		markA[y] = i;
		if (dfsY(y + 1, i + 1))
			return 1;
	}
	return 0;
}

bool start(){
	for (int i = 0; i < n2; ++i)
	for (int j = 0; j < m2; ++j)
	if (A[0][0] == B[i][j]){
		X = i;
		Y = j;
		if (dfsY(1, Y + 1))
			return 1;
	}
	return 0;
}
int main(){
	ifstream in("C:\\input.txt");

	cin >> n1 >> m1;
	for (int i = 0; i < n1; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < m1; ++j)
			A[i][j] = (s[j] == '1');
	}
	cin >> n2 >> m2;
	for (int i = 0; i < n2; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < m2; ++j)
			B[i][j] = (s[j] == '1');
	}
	if (n1>n2 || m1>m2)
		cout << "No" << endl;
	else{
		N = n2 - n1;
		M = m2 - m1;
		if (start())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}


	return 0;
}