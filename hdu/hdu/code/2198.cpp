#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[51];
int temp[51];
int LCS(int n){
	int t[51];
	int count = 0;
	if (n){
		t[count++] = temp[0];
		for (int i = 1; i < n; ++i)
		if (temp[i]>t[count - 1])
			t[count++] = temp[i];
		else
			*lower_bound(t, t + count, temp[i]) = temp[i];
	}
	return n - count;
}



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		cin >> data[0];
		int num = 0;
		for (int i = 1; i < N; ++i){
			cin >> data[i];
			if (data[i] == data[i - 1]){
				i--;
				N--;
				num++;
			}
		}
		int A;
		int mmin = N;
		for (int i = 0; i < N; ++i){
			int size = 0;
			A = 0;
			for (int j = 0; j < i;++j)
			if (data[j] < data[i])
				temp[size++] = data[j];
			else A++;
			A += LCS(size);
			size = 0; 
			for (int j = N - 1; j>i;--j)
			if (data[j]<data[i])
				temp[size++] = data[j];
			else A++;
			A += LCS(size);
			if (A < mmin)
				mmin = A;
		}
		cout << mmin + num << endl;
	}
	return 0;
}