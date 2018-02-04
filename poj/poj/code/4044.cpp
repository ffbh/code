#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int A[40], B[40];

bool paixu(int a, int b){
	if (a % 10 == b % 10)
		return a < b;
	else
		return a%10 < b%10;

}
int main(){
	ifstream in("C:\\input.txt");
	int T,n1, n2;
	cin >> T;
	while (T--){
		cin >> n1 >> n2;
		for (int i = 0; i < n1; ++i)
			cin >> A[i];
		for (int i = 0; i < n2; ++i)
			cin >> B[i];
		sort(A, A + n1, greater<int>());
		n1 = unique(A , A + n1) - A;
		sort(B, B + n2, greater<int>());
		n2 = unique(B , B + n2) - B;
		int start = -1;
		int maxlen = 0;
		for (int i = 0; i < n1; ++i){
			for (int j = 0; j < n2; ++j)
			if (A[i] == B[j]){
				int len = 0;
				for (int k = 0; A[i + k] == B[j + k]&&i+k<n1&&j+k<n2; ++k)
					len++;
				if (len>maxlen){
					maxlen = len;
					start = i;
				}

			}
		}
		if (start == -1)
			cout << "NONE" << endl;
		else{
			for (int i = start; i < start + maxlen-1; ++i)
				printf("%d ", A[i]);
			printf("%d\n", A[start + maxlen - 1]);
			sort(A + start, A + start + maxlen, paixu);
			for (int i = start; i < start + maxlen - 1; ++i)
				printf("%d ", A[i]);
			printf("%d\n", A[start + maxlen - 1]);
		}





	}


	









	return 0;
}