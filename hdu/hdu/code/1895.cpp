#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int num[5][310];
int temp[3][90000];

int slove(){
	int size1, size2;
	size1 = size2 = 0;
	for (int i = 1; i <= num[0][0]; ++i)
	for (int j = 1; j <= num[1][0]; ++j)
		temp[1][size1++] = num[0][i] + num[1][j];
	for (int i = 1; i <= num[2][0]; ++i)
	for (int j = 1; j <= num[3][0]; ++j)
		temp[2][size2++] = num[2][i] + num[3][j];
	sort(temp[1], temp[1] + size1);
	sort(temp[2], temp[2] + size2);
	sort(num[4] + 1, num[4] + 1 + num[4][0]);
	int res = 0;
	for (int i = 1; i <= num[4][0]; ++i)
	for (int j = 0; j < size1; ++j){
		int sum = num[4][i] + temp[1][j];
		int* p = lower_bound(temp[2],temp[2]+size2,-sum);
		while (*p == -sum&&p-temp[2]<size2){
			res++;
			p++;
		}
	}
	return res;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 0; i < 5; ++i){
			cin >> num[i][0];
			for (int j = 1; j <= num[i][0]; ++j)
				//in >> num[i][j];
				scanf("%d", &num[i][j]);
		}
		cout << slove() % 1000000007 << endl;
	}
	return 0;
}